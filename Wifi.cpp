#include "Wifi.h"
Wifi::Wifi(char* SSID, char* password){
  this->SSID = SSID;
  this->password = password;
}

// Wifi::Wifi()

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

bool Wifi::connect(){
  // int size_SSID = SSID.length();
  // int size_password = password.length();
  // char char_SSID [size_SSID + 1];
  // char char_password [size_password + 1];
  // for (int i = 0; i < sizeof(char_SSID); i++) {
  //       char_SSID[i] = SSID[i];
  // }

  // for (int i = 0; i < sizeof(char_password); i++) {
  //       char_password[i] = password[i];
  // }
  // WiFi.begin(char_SSID, char_password);
  // if(WiFi.status() == WL_CONNECTED){
  //   return true;
  // }  
  // else{
  //   return false;
  // }
  return true;
}
