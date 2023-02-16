## UCLA LEMUR woodbot

![Fully assembled woodbot](media/woodbot.jpg)


### Requirements:
#### Arduino support for ESP32 board
- Install Arduino IDE (Tested with IDE 2.0.3)
- Follow [setup instruction](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/). But You don't need to flash their example.
- To install library: Sketch > Include Library > Manage Libraries... > library name > Install 
- You can click "more info" for how to use them, if you want to know.


#### vl53l0x Library (Lidar)
- vl53l0x by Adafruit

#### PCF8574 (IO expander)
- PCF8574 by Renzo Mischianti

#### LSM6DS3TRC (6DoF IMU)
- LSM6DS by Adafruit

#### QMC5883LCompass (Compass)
- QMC5883LCompass by MPrograms

#### FastLED (RGB led control)
- FastLED by Daniel Garcia


### Hardware: 
- ESP32 Wrover-E with camera
- PCB board 
- 2 continuous rotation servos 
- 2 VL53L0X Time-of-Flight (ToF) Laser Ranging Sensor:
- 1 Lipo Battery 3.8V 650mAh
- Wood parts

# Instruction

## Soldering
- 20*2 row female headers at least inner 1 row (two ports) 
  - *Be sure to solder inner rows*
- 6 row lidar female headers (4 ports)
- right angle lidar male headers (2 lidars) 
  - *Be sure the lidar points outward*
- 3 row male headers (4 ports)
- Lipo power port
  - Watch out connector direction!
  - wrong wiring can even damage your laptop



    
![led](media/led.png)
![lidar](media/lidar.png)
![servo](media/servo.png)

## Coding
1. install above required libraries
2. IDE environment check
   1. open: file -> examples -> ESP32 -> chipID -> getchipID
   2. Make sure your upload baudrate is "115200" and frequency is 40Mhz
   3. upload the file to check if you can compile and run the code
   4. Open Serial monitor from tools
   5. Set baudrate to 115200
   6. Now you should see the chip ID
3. Testing components 
   1. Open 'woodbot_test.ino' in this folder
   2. check if it compiles. If not you are probably missing libraries or installed wrong one
   3. flash to ESP32
   4. If hardware is not ready, ask TA for testing board
   5. We should see green LED flashing (meaning all components initialized)
4. Test LEDs
   1. in loop() write a code to blink D3-D6 leds
   2. you set a pin HIGH (on) with pcf8574.digitalWrite(LED_PIN, HIGH);
   3. you set a pin LOW (off) with pcf8574.digitalWrite(LED_PIN, LOW);
   4. put delay to pose after changing led states
5. Test Neo LEDs
   1. use or based on neo_led_green() function in the code, set all leds to be a different color (Red, Green, etc.) IDE should show list of colors you can pick
   2. neo_led_off() or setting LED to Black turn off the lights
6. Test Servo
   1. we can velocity control servo. command range is 0-180. and 90 means stop. 180 is full speed and 0 is reverse
   2. do servo_J7.write(0) to run the servo
   3. try doing back and forth motion
7. Test IMU 
   1. use read imu to see the imu reading in serial monitor
8. Test compass
   1. Goto their library and get: x, y, z readings and Azimuth
   2. print them




rst:0x7 (TG0WDT_SYS_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
flash read err, 1000
ets_main.c 371 
ets Jun  8 2016 00:22:57
