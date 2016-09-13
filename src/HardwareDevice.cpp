/**
 * @file HardwareDevice.cpp
 * @author David Bonsall
 * @version 1.0
 * @see HardwareDevice.h
 */

#include "HardwareDevice.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


HardwareDevice::HardwareDevice(string devicePath, string deviceName,
		DeviceType deviceType, string physicalLoc) : devicePath(devicePath),
		deviceName(deviceName), deviceType(deviceType), physicalLoc(physicalLoc)
{
	//format and set the description
	devDescription = deviceName + " :: " + deviceTypeStrings[deviceType] +
				" device on " + physicalLoc + " located at " + devicePath + ".";
}

void HardwareDevice::setDescription(string description)
{
	devDescription = description;
}

int HardwareDevice::writeToProperty(string pathModifier, string data)
{
	//setup the output stream using the path modifier appended to the main
	//device path
	ofstream ofs((devicePath + pathModifier).c_str());

	ofs << data << flush;	//write to and flush the stream

	ofs.close();

	//if there were no problems, return 0
	if (ofs.good())
		return 0;

	//otherwise return -1 to indicate an error occurred.
	return -1;
}

int HardwareDevice::readFromProperty(string pathModifier, string *data)
{
	//setup the input stream using the path modifier appended to the main
	//device path
	ifstream ifs((devicePath + pathModifier).c_str());

	ifs >> (*data);	//read the data from the stream

	ifs.close();

	//if there were no problems, return 0
	if (ifs.good())
		return 0;

	//otherwise return -1 to indicate that an error occurred
	return -1;
}

string HardwareDevice::getName()
{
	return deviceName;
}

string HardwareDevice::getPath()
{
	return devicePath;
}

string HardwareDevice::getPhysicalLoc()
{
	return physicalLoc;
}

string HardwareDevice::getDescription()
{
	return devDescription;
}

DeviceType HardwareDevice::getType()
{
	return deviceType;
}
