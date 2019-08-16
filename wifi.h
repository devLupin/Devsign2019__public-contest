/*
 Name:		wifi.h
 Created:	2019-08-16 ¿ÀÈÄ 4:22:09
 Author:	Hyuntaek Lim
 
 reference:	https://github.com/itead/ITEADLIB_Arduino_WeeESP8266
*/

#ifndef __WIFI_H___
#define __WIFI_H___

#include<SoftwareSerial.h>
#include<ESP8266.h>

#define SSID        ""  
#define PASSWORD    ""  
#define HOST_NAME   "192.168.0.101"  
#define HOST_PORT   22

ESP8266 wifi(Serial1);
bool isConnected = false;

//void printUsage();
void wifi_setup(void);
void wifi_test(void);

#endif // !__WIFI_H___