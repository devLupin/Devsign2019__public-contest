/*
 Name:		Devsign_2019_publiccontest.ino
 Created:	2019-08-14 오후 1:36:43
 Author:	Hyuntaek Lim
*/

#include "pH.h"
#include "Temperature.h"
#include "wifi.h"

#define P_SEPERATE() "-----------------------------------\n";
#define P_SEPERATE_TWO_LINES() "-----------------------------------\n\n";

const int term = 30000;
int start = millis();
int sendTime;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	Serial1.begin(9600);
	Serial.println("Temperature");
	Serial.println("pH");

	wifi_setup();
	wifi_test();
}

// the loop function runs over and over again until power down or reset
void loop() {
	sendTime = millis();

	double phValue = get_pH();
	double temperature = getTemperature();

	if (sendTime - start >= term) {
		P_SEPERATE();
		Serial.print("pH: "); Serial.println(phValue);
		Serial.print("Temperature: "); Serial.print(temperature); Serial.println("C");
		P_SEPERATE_TWO_LINES();

		start = millis();
	}
}