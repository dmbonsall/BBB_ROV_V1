/**
 * @file GPIO.h
 * @author David Bonsall
 * @version 1.0
 */

#pragma once

#include "HardwareDevice.h"
#include <string>

/** Used to specify a high logic level */
#define GPIO_HIGH	1

/** Used to specify a low logic level */
#define GPIO_LOW	0

/** Used to specify a pin as an input */
#define GPIO_IN		0

/** Used to specify a pin as an output */
#define GPIO_OUT	1

/**
 * Class used to control a simple digital input or output pin. To initialize,
 * the class requires a path to the GPIO device's directory in the Linux file
 * system. The default location of the directory is found in /sys/class/gpio/gpioX
 * where 'X' represents the number of the pin as it is referenced in the file
 * system, not the physical or chip pin number. Once the file path is given,
 * this class is able to perform all the tasks needed to manipulate a GPIO Device.
 */
class GPIO : public HardwareDevice
{
private:
	//these describe the additions to the root device path for various device operations
	/** File used to read/write the value (high/low) of the pin */
	const std::string valueBuffer = "/value";

	/**File used to read/write the direction (in/output) of the pin */
	const  std::string directionBuffer = "/direction";


	int GPIONum;	/**< Describes the pin number as referenced in software*/

public:
	/**
	 * Constructor for the GPIO Class
	 * @param devicePath the file path for the GPIO device.
	 * @param devName	user specified name for the GPIO device for self reference
	 * @param GPIONum the pin number as referenced in software
	 * @param physicalPinLoc the pin's physical location on the P8/P9 headers
	 */
	GPIO(std::string devicePath, std::string deviceName, int GPIONum,
			std::string physicalPinLoc);

	/**
	 * Gets the current value (high/low) of the GPIO device.
	 * @return an integer representing the value as either ::GPIO_HIGH or ::GPIO_LOW
	 */
	int getValue();

	/**
	 * Sets the current value (high/low) of the GPIO device.
	 * @param value an integer representing the value as either ::GPIO_HIGH or ::GPIO_LOW
	 */
	void setValue(int value);

	/**
	 * Gets the current direction (in/out) of the GPIO device.
	 * @return an integer representing the value as either ::GPIO_IN or ::GPIO_OUT
	 */
	int getDirection();

	/**
	 * Sets the current direction (in/out) of the GPIO device.
	 * @param direction an integer representing the value as either ::GPIO_IN or ::GPIO_OUT
	 */
	void setDirection(int direction);

	/**
	 * Gets the GPIO Device's pin number as represented in the software.
	 * @return The pin number
	 */
	int getPinNum();
};
