/*
 Name:		Temperature.h
 Created:	2019-08-14 ¿ÀÈÄ 3:36:43
 Author:	Hyuntaek Lim

 reference:	https://github.com/PaulStoffregen/OneWire
*/

#ifndef __TEMP_INO___
#define __TEMP_INO___

#include <OneWire.h>

static int temp_pin = 7;
static OneWire ds(temp_pin);

double getTemperature(void);

#endif		//!__TEMP_INO___
