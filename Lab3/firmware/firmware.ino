#include <WiFi.h>
#include "WebSocketsServer.h" //Make these angle brackets again?
// #include <ESP32Servo.h>


#define SERVOMIN  150
#define SERVOMAX  410
#define SERVO_FREQ 50
#define LOW_DEAD 85
#define HIGH_DEAD 95


// Constants
const char* ssid     = "ESP32";
const char* password = "";
int left_conv;
int right_conv;
int left_flag;
int right_flag;

// Globals
WebSocketsServer webSocket = WebSocketsServer(80);
//WiFiServer server(80); //Necessary?

void setup() {

  // Start Serial port
  Serial.begin(115200);

  // Connect to access point
  Serial.println("Connecting");
  // WiFi.mode(WIFI_AP);
  IPAddress myIP =  WiFi.softAP(ssid, password);
  Serial.print("ESP ip address:");
  Serial.println(myIP.toString());
  WiFi.begin(ssid, password);

  // Print our IP address
  Serial.println("Connected!");
  Serial.print("My IP address: ");
  Serial.println(WiFi.localIP());

  // Start WebSocket server and assign callback
  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);

}

void loop() {

  // Look for and handle WebSocket data
  webSocket.loop();
}



// Called when receiving any WebSocket message
void onWebSocketEvent(uint8_t num,
                      WStype_t type,
                      uint8_t * payload,
                      size_t length) {

  // Figure out the type of WebSocket event
  switch(type) {

    // Client has disconnected
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;

    // New client has connected
    case WStype_CONNECTED:
      {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connection from ", num);
        Serial.println(ip.toString());
        break;
      }     

    case WStype_BIN:
            Serial.printf("[%u] Connection from ", num);
            Serial.printf("[%u] Got binary of length ", length);
            for (int i = 0; i < length; i++)
              Serial.printf("[%u]     char :  ", payload[i]);

            if (payload[0] == '~') 
            Serial.print('drive: ');
            Serial.print(180-payload[1], payload[2]);


    // Echo text message back to client
    case WStype_TEXT:
      Serial.printf("[%u] Text: %s\n", num, payload);
      webSocket.sendTXT(num, payload);

      //...BUT ACTIVATED BY WEB SOCKET TEXT COMMANDS LIKE PAPERBOT
      if (payload[0] == '#') {
          if(payload[1] == 'F') {
          }
      }
      if (payload[0] == '~') 
        Serial.print('drive: ');
            Serial.print(180-payload[1], payload[2]);
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
