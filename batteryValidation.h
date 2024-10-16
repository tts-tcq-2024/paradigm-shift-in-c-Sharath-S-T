#ifndef BATTERY_VALIDATION_H
#define BATTERY_VALIDATION_H

#include "utility.h"
#include <limits.h>

#define TEMP_MIN 0
#define TEMP_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE_MIN INT_MIN
#define CHARGE_RATE_MAX 0.8

#define WARNING_TOLERANCE_PERCENT 0.05

// Enable/Disable warnings 
#define TEMPERATURE_WARNING 1
#define SOC_WARNING 1
#define CHARGE_RATE_WARNING 1

// Check status function
int checkStatus(float value, const BatteryParameter* config);

int batteryIsOk(float temperature, float soc, float chargeRate);

#endif // BATTERY_VALIDATION_H
