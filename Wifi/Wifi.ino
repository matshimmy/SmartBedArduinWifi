#include <SoftwareSerial.h>
#include "Wifi.h"

SoftwareSerial bt(2, 3);
Wifi wifi('a', 'b');
char char_SSID[100];
int ssidCount = 0;
char char_sspass[100];
int sspassCount = 0;
const int ENB_PIN = 7; // the Arduino pin connected to the EN1 pin L298N
const int IN4_PIN = 6; // the Arduino pin connected to the IN4 pin L298N
const int IN3_PIN = 5; // the Arduino pin connected to the IN3 pin L298N

void setup() {
  bt.begin(9600);
  Serial.begin(9600);
  pinMode(ENB_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);
  digitalWrite(ENB_PIN, HIGH);
}

void loop() {
  char i;

  if (bt.available() > 0) {
    i = bt.read();
    if (i == 0x00) {  // start ssid reading
      while (true) {
        if (bt.available() > 0) {
          i = bt.read();
          if (i == 0x00) {  // end ssid reading
            break;
          }
          char_SSID[ssidCount] = i;
          ssidCount++;
        }
      }
      wifi.setSSID(char_SSID);
    }

    if (i == 0x01) {  // start sspass reading
      while (true) {
        if (bt.available() > 0) {
          i = bt.read();
          if (i == 0x01) {  // end sspass reading
            break;
          }
          char_sspass[sspassCount] = i;
          sspassCount++;
        }
      }
      wifi.setPassword(char_sspass);
    }

    //bed part 1
    if(i == 0x02){
      while(i != 0x03){ //user releases button
        i = bt.read();
        // extend the actuator
        digitalWrite(IN4_PIN, HIGH);
        digitalWrite(IN3_PIN, LOW);
      }
      // extend the actuator
      digitalWrite(IN4_PIN, LOW);
      digitalWrite(IN3_PIN, LOW);
    }

    //bed part 2
    if(i == 0x04){
      while(i != 0x03){ // user releases button
        i = bt.read();
      }
    }

    //bed part 3
    if(i == 0x05){
      while(i != 0x03){ // user releases button
        i = bt.read();
      }
    }

    //bed part 4
    if(i == 0x04){
      while(i != 0x03){
        i = bt.read(); //user releases button
      }
    }

    //bed part 5
    if(i == 0x05){
      while(i != 0x03){
        i = bt.read(); //user releases button
      }
    }

    //bed part 6
    if(i == 0x06){
      while(i != 0x03){
        i = bt.read(); //user releases button
      }
    }
  }

  if(ssidCount > 0 && sspassCount > 0 && !wifi.status()) {
    Serial.print("SSID: ");
    Serial.println(wifi.getSSID());
    Serial.print("Password: ");
    Serial.println(wifi.getPassword());
    Serial.print("Connected: ");
    wifi.connect(ssidCount, sspassCount);
    Serial.println(wifi.status());
  }
}
