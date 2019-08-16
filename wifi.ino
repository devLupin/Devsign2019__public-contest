/*
 Name:		wifi.ino
 Created:	2019-08-16 ¿ÀÈÄ 4:22:09
 Author:	Hyuntaek Lim
*/

#include"wifi.h"

/*
void printUsage()
{
	uint8_t buf[] = "Usage\n1 : Turn On LED\n2 : Turn Off LED\nS : LED status\n\n";
	wifi.send(buf, strlen(buf));
}
*/

void wifi_setup(void)
{
	Serial.print("wifi setup \r\n");

	Serial.print("FW Version:");
	Serial.println(wifi.getVersion().c_str());

	if (wifi.setOprToStationSoftAP()) {
		Serial.print("to station + softap ok\r\n");
	}
	else {
		Serial.print("to station + softap err\r\n");
	}

	if (wifi.joinAP(SSID, PASSWORD)) {
		Serial.print("Join AP success\r\n");
		Serial.print("IP:");
		Serial.println(wifi.getLocalIP().c_str());
	}
	else {
		Serial.print("Join AP failure\r\n");
	}

	if (wifi.disableMUX()) {
		Serial.print("single ok\r\n");
	}
	else {
		Serial.print("single err\r\n");
	}

	Serial.print("wifi setup end\r\n");



	pinMode(LED_BUILTIN, OUTPUT);

}



void wifi_test(void)
{
	if (isConnected == false) {

		while (1) {
			if (wifi.createTCP(HOST_NAME, HOST_PORT)) {
				Serial.print("create tcp ok\r\n");
				isConnected = true;
				break;
			}
			else {
				Serial.print("create tcp err\r\n");
			}
		}
	}

	uint8_t buffer[128] = { 0 };

	uint32_t len = wifi.recv(buffer, sizeof(buffer), 10000);
	if (len > 0) {
		Serial.print("Received:[");
		for (uint32_t i = 0; i < len; i++) {
			Serial.print((char)buffer[i]);
		}
		Serial.print("]\r\n");
	}
}