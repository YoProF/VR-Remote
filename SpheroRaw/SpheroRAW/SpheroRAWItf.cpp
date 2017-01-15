//######################################################################################################################
/*
    Copyright (c) since 2014 - Paul Freund

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/
//######################################################################################################################

#include "SpheroDevice.h"

//======================================================================================================================

#include <string>

//======================================================================================================================

ISpheroDevice* device;

//======================================================================================================================

SPHERO_RAW_API int SpheroRAW_Init(char name[]) {
	//return string(name).length();
	//return string(name).compare("Sphero-GYY");
	//device = new SpheroDevice(string(name));
	device = new SpheroDevice("Sphero-GYY");
	return SpheroRAW_GetStatus();
}

//======================================================================================================================

SPHERO_RAW_API int SpheroRAW_Connect() {
	SpheroState state = SpheroState(SpheroRAW_GetStatus());
	if (state != SpheroState_Disconnected) return state;
	device->connect();
	return device->state();
}

//======================================================================================================================

SPHERO_RAW_API void SpheroRAW_Disconnect() {
	device->disconnect();
}

//======================================================================================================================

SPHERO_RAW_API int SpheroRAW_GetStatus() {
	if (!device) return SpheroState_None;
	return device->state();
}

//======================================================================================================================

SPHERO_RAW_API int SpheroRAW_Roll(int speed, int heading, int state) {
	return device->roll(speed, heading, state);
}

//======================================================================================================================

SPHERO_RAW_API int SpheroRAW_SetRGBLedOutput(int red, int green, int blue, bool persist) {
	return device->setRGBLedOutput(red, green, blue, persist);
}

//======================================================================================================================

SPHERO_RAW_API void SpheroRAW_CleanUp() {
	SpheroRAW_Disconnect();
	delete device;
}

//======================================================================================================================

SPHERO_RAW_API int SpheroRAW_SetBackLEDOutput(int intensity) {
	return  device->setBackLEDOutput(intensity);
}

//======================================================================================================================
