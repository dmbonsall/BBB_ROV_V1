/**
 * @file PWM.h
 * @author David Bonsall
 * @version 1.0
 */

#pragma once

#include "HardwareDevice.h"
#include <string>

/** Used to specify an active low polarity (time "on" is High, "off" is low) */
#define PWM_POL_ACTIVE_LOW	0

/** Used to specify an active high polarity (time "on" is low, "off" is high) */
#define PWM_POL_ACTIVE_HIGH	1

/**
 * Class used to control a PWM Device. To initialize, the class requires a path
 * to the PWM device's directory in the Linux file system. The default location
 * of the directory is found in /sys/dev/ocp.3/ . Once the file path is given,
 * this class is able to perform all the tasks needed to manipulate a PWM Device,
 * such as control the period and duty of the PWM signal, as well as adjust things
 * like polarity (active high/low).
 */
class PWM : public HardwareDevice
{
private:
	//these describe the additions to the root device path for various device operations
	/** File used to describe the period of the PWM signal */
	const std::string periodBuffer = "/period";

	/** File used to describe the duty (on time) of the PWM signal */
	const std::string dutyBuffer = "/duty";

	/** File used to enable and disable the PWM signal */
	const std::string runBuffer = "/run";

	/** File used to describe the polarity of the PWM signal (active high/low) */
	const std::string polarityBuffer = "/polarity";

	/** The name of the PWM pin as referenced in the Linux file system */
	std::string identifier;

public:
	/**
	 * Constructor to initialize a PWM device object
	 * @param devicePath The file path for the PWM device.
	 * @param deviceName The user specified name of the device.
	 * @param identifier The name of the PWM device as referenced in the Linux file system.
	 * @param physicalPinLoc The pin's physical location on the P8/P9 headers.
	 */
	PWM(std::string devicePath, std::string deviceName,
			std::string identifier = "unknown", std::string physicalPinLoc = "unknown");

	/**
	 * Gets the duty (in nano seconds) of the PWM signal.
	 * @return The duty in ns.
	 */
	int getDuty();

	/**
	 * Gets the duty (as a percentage of the period) of the PWM signal.
	 * @return A number between 0 and 1 (inclusive) representing the percentage.
	 */
	float getDutyPercent();

	/**
	 * Gets the period (in nano seconds) of the PWM signal.
	 * @return The period in ns.
	 */
	int getPeriod();

	/**
	 * Gets the polarity (active high/low) of the PWM signal.
	 * @return An int representing the polarity. Will be either ::PWM_POL_ACTIVE_LOW
	 * or ::PWM_POL_ACTIVE_HIGH.
	 */
	int getPolarity();

	/**
	 * Sets the duty (in nano seconds) of the PWM signal. Will throw an error if the
	 * specified duty is greater than the current period of the PWM signal, or if the
	 * specified duty is less than zero.
	 * @param duty The duty in ns.
	 */
	void setDuty(int duty);

	/**
	 * Sets the duty (as a percentage of the current period) of the PWM signal.
	 * @param duty The duty as a percentage of the period. Must be between 0 and 1
	 * inclusive or the method will throw an error.
	 */
	void setDutyPercent(float duty);

	/**
	 * Sets the period (in nano seconds) of the PWM signal.
	 * @param period The period in ns.
	 */
	void setPeriod(int period);

	/**
	 * Sets the polarity of the PWM signal.
	 * @param polarity An int representing the polarity. Will be either ::PWM_POL_ACTIVE_LOW
	 * or ::PWM_POL_ACTIVE_HIGH.
	 */
	void setPolarity(int polarity);

	/**
	 * Enables the PWM signal, causing the device to begin generating a signal.
	 */
	void enable();

	/**
	 * Disables the PWM signal, causing the device to stop generating a signal.
	 */
	void disable();

	/**
	 * Returns whether or not the PWM device is enabled (generating a PWM signal).
	 * @return True if enabled, false if disabled.
	 */
	bool isEnabled();

	/**
	 * Gets the name of the PWM pin as referenced in the Linux file system.
	 * @return a string representing the identifier.
	 */
	std::string getIdentifier();
};
