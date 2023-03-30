#ifndef MY_WIFI_H
#define MY_WIFI_H
#include <Arduino.h>
#include <SPI.h>
#include <WiFi.h>
class Wifi{
  private:
    char* SSID;
    char* password;
  public:
    Wifi(char* SSID, char* password);
    void setSSID(char* SSID);
    void setPassword(char* password);
    char* getSSID();
    char* getPassword();
    void connect(int ssidLength, int passLength);
    bool Wifi::status();
};
#endif
