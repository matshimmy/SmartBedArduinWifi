#include <SoftwareSerial.h>
#include "Wifi.h"

SoftwareSerial bt(2, 3);
Wifi wifi('a', 'b');
char char_SSID[100];
int ssidCount = 0;
char char_sspass[100];
int sspassCount = 0;

void setup() {
  bt.begin(9600);
  Serial.begin(9600);
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
