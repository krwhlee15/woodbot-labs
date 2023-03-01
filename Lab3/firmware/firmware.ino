

#include "Wire.h"
#include <PCF8574.h>
#include <Adafruit_LSM6DS3TRC.h>
#include <Adafruit_VL53L0X.h>
#include <ESP32Servo.h>
#include <QMC5883LCompass.h>
#include <FastLED.h>

#include <WiFi.h>
#include "WebSocketsServer.h" 



// Constants
const char* ssid = "romela_robocup_2G";
const char* password = "RoMeLa_Lab_UCLA";
String hostname = "ESP_01";
int left_conv;
int right_conv;
int left_flag;
int right_flag;




/*
Pin mapping
*/

#define SCL_PIN 32
#define SDA_PIN 33

#define LED_D3 P0
#define LED_D4 P1
#define LED_D5 P2
#define LED_D6 P3

#define LED_ON 0
#define LED_OFF 1

#define LED_NEO 2

#define LED_BUILTIN 2

#define SERVO_J6 14
#define SERVO_J7 12
#define SERVO_J8 13
#define SERVO_J9 15

#define IO_EXPANDER 0x38

#define LIDAR_XSHUT_R P4
#define LIDAR_XSHUT_B P5
#define LIDAR_XSHUT_L P6

#define LIDAR_RESET 0
#define LIDAR_ACTIVATE 1

// NEO LED info
#define LED_CHIP WS2811
#define NUM_LEDS 6

// Websocket init at port 80
WebSocketsServer webSocket = WebSocketsServer(80);

// Device variables
Adafruit_LSM6DS3TRC lsm6ds3trc;                  // 6dof IMU
Adafruit_VL53L0X lox_J2 = Adafruit_VL53L0X();       // Lidar
Adafruit_VL53L0X lox_J3 = Adafruit_VL53L0X();       // Lidar
Adafruit_VL53L0X lox_J4 = Adafruit_VL53L0X();       // Lidar
Adafruit_VL53L0X lox_J5 = Adafruit_VL53L0X();       // Lidar
QMC5883LCompass compass;                         //compass
Servo servo_J6;                                     // Servo PWM
Servo servo_J7;                                     // Servo PWM
Servo servo_J8;                                     // Servo PWM
Servo servo_J9;                                     // Servo PWM
CRGB leds[NUM_LEDS];                             // Neo LED
PCF8574 pcf8574(IO_EXPANDER, SDA_PIN, SCL_PIN);  // IO expander

// Servo settings for FS90r
#define WIDTH_MIN 700
#define WIDTH_MAX 2300



void setup() {
  //setup serial
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }
  wifiSetup();
  // Set I2C ports
  Wire.setPins(SDA_PIN, SCL_PIN);
  Serial.println("Device Initialization");
  device_setup();

}

void loop() {
  // Look for and handle WebSocket data
  webSocket.loop();
}



void device_setup() {
  led_setup();     // init LEDS on io expanders
  pcf8574.digitalWrite(LED_D3, LED_ON);  // turn D3 on (init progress)
  delay(500);
  imu_setup();     // init imu 6dof
  pcf8574.digitalWrite(LED_D4, LED_ON);  // turn D3 on (init progress)
  delay(500);
  compass.init();  // init compass
  pcf8574.digitalWrite(LED_D5, LED_ON);  // turn D3 on (init progress)
  delay(500);
  lidar_setup();                       // init lidar
  pcf8574.digitalWrite(LED_D6, LED_ON);  // turn D3 on (init progress)
  delay(1000);
  servo_setup();                                            // setup servo
  FastLED.addLeds<LED_CHIP, LED_NEO, GRB>(leds, NUM_LEDS);  // init neo led
  Serial.println("NEO LED is ready");
  neo_led_green();  // all setup done LED
  delay(1000);
  neo_led_off();
  Serial.println("end of setup");
}

void led_setup() {
  pcf8574.pinMode(LED_D3, OUTPUT);
  pcf8574.pinMode(LED_D4, OUTPUT);
  pcf8574.pinMode(LED_D5, OUTPUT);
  pcf8574.pinMode(LED_D6, OUTPUT);
  pcf8574.pinMode(LIDAR_XSHUT_L, OUTPUT);
  pcf8574.pinMode(LIDAR_XSHUT_R, OUTPUT);
  pcf8574.pinMode(LIDAR_XSHUT_B, OUTPUT);

    if (pcf8574.begin()) {
    Serial.println("OK");
  } else {
    Serial.println("KO");
  }

  pcf8574.digitalWrite(LIDAR_XSHUT_L, LIDAR_RESET);
  pcf8574.digitalWrite(LIDAR_XSHUT_R, LIDAR_RESET);
  pcf8574.digitalWrite(LIDAR_XSHUT_B, LIDAR_RESET);
  delay(100);
  pcf8574.digitalWrite(LIDAR_XSHUT_L, LIDAR_ACTIVATE);
  pcf8574.digitalWrite(LIDAR_XSHUT_R, LIDAR_ACTIVATE);
  pcf8574.digitalWrite(LIDAR_XSHUT_B, LIDAR_ACTIVATE);
  

  pcf8574.digitalWrite(LED_D3, LED_OFF);
  pcf8574.digitalWrite(LED_D4, LED_OFF);
  pcf8574.digitalWrite(LED_D5, LED_OFF);
  pcf8574.digitalWrite(LED_D6, LED_OFF);
  Serial.println("IO expander LEDs are ready");
  delay(1000);

}

void imu_setup() {
  if (!lsm6ds3trc.begin_I2C()) {
    Serial.println("Failed to find LSM6DS3TR-C chip");
    while (true) {
      delay(10);
    }
  }
  Serial.println("6DoF IMU: LSM6DS3TR is ready");
}

void lidar_setup() {
  if (!lox_J2.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (10)
      ;
  }
  Serial.println("Lidar: VL53L0X is ready");
}



void read_compass() {
  int x, y, z;

  // Read compass values
  compass.read();

  // Return XYZ readings
  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();

  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" Y: ");
  Serial.print(y);
  Serial.print(" Z: ");
  Serial.print(z);
  Serial.println();

  delay(250);
}


void servo_setup() {
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  servo_J6.setPeriodHertz(50);  // standard 50 hz servo
  servo_J7.setPeriodHertz(50);  // standard 50 hz servo
  servo_J8.setPeriodHertz(50);  // standard 50 hz servo
  servo_J9.setPeriodHertz(50);  // standard 50 hz servo

  servo_J6.attach(SERVO_J6, WIDTH_MIN, WIDTH_MAX);
  servo_J7.attach(SERVO_J7, WIDTH_MIN, WIDTH_MAX);
  servo_J8.attach(SERVO_J8, WIDTH_MIN, WIDTH_MAX);
  servo_J9.attach(SERVO_J9, WIDTH_MIN, WIDTH_MAX);
  Serial.println("Servos are ready");
}




void drive(int right, int left) {
  servo_J7.write(180 - left);
  servo_J9.write(right);
}



void read_imu(){
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  lsm6ds3trc.getEvent(&accel, &gyro, &temp);

  Serial.print("\t\tTemperature ");
  Serial.print(temp.temperature);
  Serial.println(" deg C");

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("\t\tAccel X: ");
  Serial.print(accel.acceleration.x);
  Serial.print(" \tY: ");
  Serial.print(accel.acceleration.y);
  Serial.print(" \tZ: ");
  Serial.print(accel.acceleration.z);
  Serial.println(" m/s^2 ");

  /* Display the results (rotation is measured in rad/s) */
  Serial.print("\t\tGyro X: ");
  Serial.print(gyro.gyro.x);
  Serial.print(" \tY: ");
  Serial.print(gyro.gyro.y);
  Serial.print(" \tZ: ");
  Serial.print(gyro.gyro.z);
  Serial.println(" radians/s ");
  Serial.println();
}


void neo_led_green() {
  for (int i = 0; i < NUM_LEDS; i++) {
    // set our current dot to red, green, and blue
    leds[i] = CRGB::Green;
    FastLED.show();
  }
  Serial.println("green");
}

void neo_led_off() {
  for (int i = 0; i < NUM_LEDS; i++) {
    // set our current dot to red, green, and blue
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}



void wifiSetup(){
  // Connect to access point
  Serial.println("Connecting");
  // WiFi.mode(WIFI_AP);

  WiFi.setHostname(hostname.c_str());  //define hostname
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Print our IP address
  Serial.println("Connected!");
  Serial.print("My IP address: ");
  Serial.println(WiFi.localIP());

  // Start WebSocket server and assign callback
  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);
}


// Called when receiving any WebSocket message
void onWebSocketEvent(uint8_t num,
                      WStype_t type,
                      uint8_t* payload,
                      size_t length) {

  // Figure out the type of WebSocket event
  switch (type) {

    // Client has disconnected
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      drive(90, 90)
      break;

    // New client has connected
    case WStype_CONNECTED:
      {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connection from ", num);
        Serial.println(ip.toString());
        // send message to client
        webSocket.sendTXT(num, "Connected to ");
        webSocket.sendTXT(num, hostname);
        break;
      }

    case WStype_BIN:
      Serial.printf("[%u] Connection from ", num);
      Serial.printf("[%u] Got binary of length ", length);
      for (int i = 0; i < length; i++)
        Serial.printf("[%u]     char :  ", payload[i]);

      if (payload[0] == '~') {
        Serial.print('drive: ');
        Serial.print(180 - payload[1], payload[2]);
        drive(payload[1], payload[2]);
      }


    // Echo text message back to client
    case WStype_TEXT:
      Serial.printf("[%u] Text: %s\n", num, payload);
      webSocket.sendTXT(num, payload);

      //...BUT ACTIVATED BY WEB SOCKET TEXT COMMANDS LIKE PAPERBOT
      if (payload[0] == '#') {
        if (payload[1] == 'F') {
        }
      }
      if (payload[0] == '~')
        Serial.print('drive: ');
      Serial.print(180 - payload[1], payload[2]);
      drive(payload[1], payload[2]);
      break;

    // For everything else: do nothing
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
    default:
      break;
  }
}
