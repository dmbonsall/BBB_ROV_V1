/**
 * @file GPIO.cpp
 * @author David Bonsall
 * @version 1.0
 * @see GPIO.h
 */

#include "GPIO.h"
#include "HardwareDevice.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

GPIO::GPIO(string devicePath, string deviceName, int GPIONum, string physicalPinLoc) :
		HardwareDevice(devicePath, deviceName, DeviceType::GPIO, physicalPinLoc),
		GPIONum(GPIONum)
{
	//TODO: implement custom description with setDescription()
}

int GPIO::getValue()
{
	//read a string from the value file, and then convert to an integer
	string data;
	readFromProperty(valueBuffer, &data);	//TODO implement error checking
	return stoi(data);
}

int GPIO::getDirection()
{
	//read a string from the value file, and then convert to an integer
	string data;
	readFromProperty(directionBuffer, &data);	//TODO implement error checking
	return stoi(data);
}

int GPIO::getPinNum()
{
	return GPIONum;
}

void GPIO::setDirection(int direction)
{
	if (direction != 0 || direction != 1)	//if it is an invalid direction
	{
		throw runtime_error("Invalid pin direction for GPIO device");
		return;	//may be redundant, but whatever.....
	}

	//convert the direction to a string, and then write it to the direction file
	writeToProperty(directionBuffer, to_string(direction));	//TODO implement error checking
}

void GPIO::setValue(int value)
{
	if (value != 0 || value != 1)	//if it is an invalid value
	{
		throw runtime_error("Invalid value for GPIO device");
		return;	//may be redundant, but whatever.....
	}

	//convert the value to a string, and then write it to the value file
	writeToProperty(valueBuffer, to_string(value));	//TODO implement error checking
}
