/**
 * @file HardwareDevice.h
 * @author David Bonsall
 * @version 1.0
 * @see HardwareDevice.cpp
 * TODO Need to set all appropriate methods to const and do the same for other classes
 */

#pragma once

#include <string>

/**
 * Enumeration describing the different device types for any known children
 * of the ::HardwareDevice class
 */
enum DeviceType
{
	Generic,		/**< Used if the device doesn't represent a specific king of device */
	GPIO,			/**< Used to describe a ::GPIO device. */
	PWM,			/**< Used to describe a ::PWM device.*/
	ADC,			/**< Used to describe an ADC device (analog input). */
	Servo,			/**< Used to describe a Servo device */
	Unspecified		/**< Default value for device types not specified in this enum */
};

/** This array maps the enum values of ::DeviceType to their string representations. */
const std::string deviceTypeStrings[] = {"Generic", "GPIO", "PWM", "ADC", "Servo",
		"Unspecified"};

/**
 * @brief Describes a generic hardware device that has a given file or directory in the
 * Linux file system.
 *
 * The HardwareDevice class provides a simple template to create objects based off of
 * devices represented in the Linux file system. For such a device, a file (or directory
 * with files) can be read from, or written to in order to manipulate or interact with
 * a given device. The class also contains members to describe the device such as name,
 * physical location on the board, etc. While this class is not abstract, it was meant
 * to be extended by sub-classes to describe more specific device behavior.
 */
class HardwareDevice
{
private:
	std::string devDescription;	/**< Stores a short user description of the device */
	DeviceType deviceType;		/**< Describes the type of device */
	std::string deviceName;		/**< Holds the user given name of the device */
	std::string devicePath;		/**< The file path of the device in the Linux file system */
	std::string physicalLoc;	/**< Describes the pin's location on the P8/P9 headers*/

protected:
	/**
	 * Sets the user description of the device. Set by default in the constructor, this
	 * can be set again by a sub class after calling the HardwareDevice() constructor.
	 * @param description Text describing the device
	 */
	void setDescription(std::string description);

	/**
	 * Writes a string to a file that describes a property of the device.
	 * @param pathModifier This modifier is appended to the device path to form the path
	 * of the file that will be written to. The path should always start with the '/' character
	 * in order to avoid errors associated with the file path.
	 * @param data A pointer to the string to be written to the file.
	 * @return Returns 0 if the write operation was successful, -1 if it wasn't.
	 */
	int writeToProperty(std::string pathModifier, std::string data);

	/**
	 * Reads a string from a file that describes a property of the device.
	 * @param pathModifier This modifier is appended to the device path to form the path
	 * of the file that will be written to. the path should always start with the '/' character
	 * in order to avoid errors associated with the file path.
	 * @param data A pointer to the string to put the data that was read from the file.
	 * @return Returns 0 if the read operation was successful, -1 if it wasn't.
	 */
	int readFromProperty(std::string pathModifier, std::string *data);

public:
	/**
	 * Constructor for the HardwareDevice class
	 * @param devicePath The path to the device's main directory in the Linux file system.
	 * @param deviceName The user specified name of the device, often used to look up the device
	 * if stored in a container.
	 * @param deviceType The type of device that this object represents.
	 */
	HardwareDevice(std::string devicePath, std::string deviceName, DeviceType deviceType,
			std::string physicalLoc);

	/**
	 * Gets the name of the device specified by the user in the constructor.
	 * @return The name associated with this HardwareDevice object.
	 */
	std::string getName();

	/**
	 * Gets the path for this device specified by the user in the constructor.
	 * @return The device path associated with this HardwareDevice object.
	 */
	std::string getPath();

	/**
	 * Gets the description of this object that is set with the ::setDevDescription() method.
	 * @return A string with the description of this HardwareDevice object.
	 */
	std::string getDescription();

	/**
	 * Gets the device type of this device.
	 * @return The device type of this HardwareDevice object.
	 * @see ::DeviceType
	 */
	DeviceType getType();

	/**
	 * Gets the physical location of the device on the board (P8/P9 headers, etc.).
	 * @return A string containing a description of the physical location of the device.
	 */
	std::string getPhysicalLoc();

};
