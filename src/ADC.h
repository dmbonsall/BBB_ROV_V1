/**
 * @file ADC.h
 * @author David Bonsall
 * @version 1.0
 */

#pragma once

#include "HardwareDevice.h"
#include <string>

/**
 * Defines the maximum value that the raw ADC reading will return. Due to
 * ADC having 12 bit resolution.
 */
#define ADC_RAW_MAX	4096

/** Defines the minimum value that the raw ADC reading will return. */
#define ADC_RAW_MIN	0

/** Defines the operating voltage of the BBB ADC */
#define ADC_VOLTAGE	1.8

/**
 * Class used to control an ADC device (analog input). To initialize, the class requires a path
 * to the ADC device'd directory in the Linux file system. The default location
 * of the directory is found in (TODO:: get the filepath) . Once the file path is given,
 * this class is able to perform all of the tasks needed to read from an analog
 * input, such as getting a raw reading, as well as a value scaled to the voltage.
 */
class ADC : public HardwareDevice
{
private:
	//these describe the additions to the root device path for various device operations
	/** File used to read the value of the ADC */
	const std::string rawBuffer = "/idk";	//TODO: get the correct path

	/** The name of the ADC device as referenced in the Linux file system */
	std::string identifier;

public:
	/**
	 * Constructor for the ADC class
	 * @param devicePath The file path for the ADC device.
	 * @param deviceName The user specified name of the device.
	 * @param identifier The name of the ADC device as referenced in the Linux file system.
	 * @param physicalPinLoc The pin's physical location on the P8/P9 headers.
	 */
	ADC(std::string devicePath, std::string deviceName, std::string identifier = "unknown",
			std::string physicalPinLoc = "unknown");

	/**
	 * Gets the current reading of the ADC device and returns as an un-scaled, raw value
	 * @return A value representing the analog reading. Will be between ::ADC_RAW_MIN and
	 * ::ADC_RAW_MAX.
	 */
	int getRawValue();

	/**
	 * Gets the curent reading of the ADC device and scales it to represent a real voltage.
	 * @return A value representing the current voltage on the pin. Will be between 0 and
	 * ::ADC_VOLTAGE.
	 */
	float getVoltageValue();

	/**
	 * Gets the name of the ADC pin as referenced in the Linux file system.
	 * @return a string representing the identifier.
	 */
	std::string getIdentifier();
};
