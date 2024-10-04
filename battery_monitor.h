// battery_monitor.h
#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

#include <stdio.h>
#include "config_parameters.h"
#include "parameter_state.h"

// Function to print messages to the console
void printMessage(const char *message);

// Function to check temperature and print appropriate messages
void checkTemperature(float temperature, ParameterState *state);

// Function to check State of Charge (SoC) and print appropriate messages
void checkSoc(float soc, ParameterState *state);

// Function to check charge rate and print appropriate messages
void checkChargeRate(float chargeRate, ParameterState *state);

#endif // BATTERY_MONITOR_H
