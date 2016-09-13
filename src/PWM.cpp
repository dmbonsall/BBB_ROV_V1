/**
 * @file PWM.cpp
 * @author David Bonsall
 * @version 1.0
 * @see PWM.h
 * TODO implement error checking on all of the property reads and writes
 */

#include "PWM.h"
#include "HardwareDevice.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

PWM::PWM(string devicePath, string deviceName, string identifier, string physicalPinLoc) :
		HardwareDevice(devicePath, deviceName, DeviceType::PWM, physicalPinLoc),
		identifier(identifier)
{
	//TODO Set the period and frequency of the signal
}

int PWM::getDuty()
{
	string str;
	readFromProperty(dutyBuffer, &str);
	return stoi(str);
}

int PWM::getPeriod()
{
	string str;
	readFromProperty(periodBuffer, &str);
	return stoi(str);
}

int PWM::getPolarity()
{
	string str;
	readFromProperty(polarityBuffer, &str);
	return stoi(str);
}

float PWM::getDutyPercent()
{
	float duty = getDuty();
	float period = getPeriod();
	return duty / period;
}

void PWM::setDuty(int duty)
{
	if (duty > getPeriod())
	{
		throw runtime_error("Duty may not be greater than the period");
		return;
	}
	else if (duty < 0)
	{
		throw runtime_error("Duty may not be less than 0");
		return;
	}

	writeToProperty(dutyBuffer, to_string(duty));
}

void PWM::setPeriod(int period)
{
	writeToProperty(periodBuffer, to_string(period));
}

void PWM::setPolarity(int polarity)
{
	if (polarity != 0 || polarity != 1)
	{
		throw runtime_error("Polarity must be set to either 0 or 1 or use the definitions in PWM.h");
		return;
	}

	writeToProperty(polarityBuffer, to_string(polarity));
}

void PWM::setDutyPercent(float duty)
{
	if (duty < 0 || duty > 1)
	{
		throw runtime_error("Duty percentage must be between 0 and 1 inclusive");
		return;
	}

	//calculate the duty in ns and cast to an int
	int i_duty = static_cast<int>(duty * getPeriod());

	writeToProperty(dutyBuffer, to_string(i_duty));
}

void PWM::enable()
{
	writeToProperty(runBuffer, "1");
}

void PWM::disable()
{
	writeToProperty(runBuffer, "0");
}

bool PWM::isEnabled()
{
	string data;
	readFromProperty(runBuffer, &data);
	return stoi(data);
}

string PWM::getIdentifier()
{
	return identifier;
}
