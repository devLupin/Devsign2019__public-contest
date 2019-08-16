/*
 Name:		pH.h
 Created:	2019-08-14 ¿ÀÈÄ 4:36:43
 Author:	Hyuntaek Lim
*/

#ifndef __PH_INO___
#define __PH_INO___

const static int SensorPin = A0;            //pH meter Analog output to Arduino Analog Input 0
const static int Offset = 0.00;            //deviation compensate
const static int samplingInterval = 20;
const static int printInterval = 800;
const static int ArrayLenth = 40;    //times of collection
static int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
static int pHArrayIndex = 0;

double get_pH(void);

#endif //!__PH_INO___