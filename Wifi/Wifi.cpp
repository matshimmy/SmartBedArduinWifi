#include "Wifi.h"

Wifi::Wifi(char* SSID, char* password){
  this->SSID = SSID;
  this->password = password;
}

void Wifi::setSSID(char* SSID){
  this->SSID = SSID;
}

void Wifi::setPassword(char* password){
  this->password = password;
}

char* Wifi::getSSID(){
  return this->SSID;
}

char* Wifi::getPassword(){
  return this->password;
}

void Wifi::connect(int ssidLength, int passLength){
  char char_SSID [ssidLength + 1];
  char char_password [passLength + 1];
  for (int i = 0; i < sizeof(char_SSID); i++) {
        char_SSID[i] = SSID[i];
  }

  for (int i = 0; i < sizeof(char_password); i++) {
        char_password[i] = password[i];
  }
  WiFi.begin(char_SSID, char_password);

}

bool Wifi::status(){
  if(WiFi.status() == WL_CONNECTED){
    return true;
  }  
  else{
    return false;
  }
}
