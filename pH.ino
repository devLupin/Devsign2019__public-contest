/*
 Name:		pH.ino
 Created:	2019-08-14 ���� 4:36:43
 Author:	Hyuntaek Lim
*/

#include "pH.h"

double get_pH(void) {
	static unsigned long samplingTime = millis();
	static unsigned long printTime = millis();
	static double pHValue, voltage;
	if (millis() - samplingTime > samplingInterval)
	{
		pHArray[pHArrayIndex++] = analogRead(SensorPin);
		if (pHArrayIndex == ArrayLenth)pHArrayIndex = 0;
		voltage = avergearray(pHArray, ArrayLenth) * 5.0 / 1024;
		pHValue = 3.5 * voltage + Offset;
		samplingTime = millis();
	}
	if (millis() - printTime > printInterval)
		//Every 800 milliseconds, print a numerical, convert the state of the LED indicator
	{
		printTime = millis();
		return pHValue;
	}
}

double avergearray(int* arr, int number) {
	int i;
	int max, min;
	double avg;
	long amount = 0;
	if (number <= 0) {
		Serial.println("Error number for the array to avraging!/n");
		return 0;
	}
	if (number < 5) {   //less than 5, calculated directly statistics
		for (i = 0; i < number; i++) {
			amount += arr[i];
		}
		avg = amount / number;
		return avg;
	}
	else {
		if (arr[0] < arr[1]) {
			min = arr[0]; max = arr[1];
		}
		else {
			min = arr[1]; max = arr[0];
		}
		for (i = 2; i < number; i++) {
			if (arr[i] < min) {
				amount += min;        //arr<min
				min = arr[i];
			}
			else {
				if (arr[i] > max) {
					amount += max;    //arr>max
					max = arr[i];
				}
				else {
					amount += arr[i]; //min<=arr<=max
				}
			}
		}
		avg = (double)amount / (number - 2);
	}
	return avg;
}
