#include <stdio.h>
#include "utility.h"
#include "batteryValidation.h"

// Define and initialize configuration variables for all three parameters
const BatteryParameter TEMP_CONFIG = {
    .min = TEMP_MIN,
    .max = TEMP_MAX,
    .warningTolerance = TEMP_MAX * WARNING_TOLERANCE_PERCENT,
    .enableWarnings = TEMPERATURE_WARNING ,
    .outOfRangeMessage = "Temperature out of range!",
    .warningUpperMessage = "Warning: Temperature approaching upper limit!",
    .warningLowerMessage = "Warning: Temperature approaching lower limit!"
};

const BatteryParameter SOC_CONFIG = {
    .min = SOC_MIN,
    .max = SOC_MAX,
    .warningTolerance = SOC_MAX * WARNING_TOLERANCE_PERCENT,
    .enableWarnings = SOC_WARNING ,
    .outOfRangeMessage = "State of Charge out of range!",
    .warningUpperMessage = "Warning: Approaching charge-peak!(upper limit)",
    .warningLowerMessage = "Warning: Approaching discharge! (lower limit)"
};

const BatteryParameter CHARGE_RATE_CONFIG = {
    .min = CHARGE_RATE_MIN,
    .max = CHARGE_RATE_MAX,
    .warningTolerance = CHARGE_RATE_MAX * WARNING_TOLERANCE_PERCENT,
    .enableWarnings = CHARGE_RATE_WARNING ,
    .outOfRangeMessage = "Charge Rate out of range!",
    .warningUpperMessage = "Warning: Approaching charge rate limit! (upper_limit)",
    .warningLowerMessage = NULL
};

void printErrorMessage(const char *warningMessage, float value) {
    printf("%s (Value: %.2f)\n", warningMessage, value);
}

// Function to handle lower limit warnings
int handleLowerLimit(const BatteryParameter* config, float value)
{
    if(config->warningLowerMessage != NULL)
    {
        checkLowerLimit(config,value);
        return 1;
    }
    return 0; 
}

// Function to handle upper limit warnings
int handleUpperLimit(const BatteryParameter* config, float value) 
{
    if(config->warningUpperMessage  != NULL)
    {
        checkUpperLimit(config,value);
        return 1;
    }
    return 0;  
}

int outOfMaxThreshold(const BatteryParameter* config, BatteryStatus* status, BatteryParameterIndex index, float value)
{
    if ((config->max !=INT_MAX) && (value >= config->max)) {
        status->value[index] = value;
        status->outOfRangeMessage[index] = config->outOfRangeMessage;
        return 1;
    }
    return 0;
}

int outOfMinThreshold(const BatteryParameter* config, BatteryStatus* status, BatteryParameterIndex index, float value)
{
    if ((config->min != INT_MIN) && (value <= config->min)) {
        status->value[index] = value;
        status->outOfRangeMessage[index] = config->outOfRangeMessage;
        return 1;
    }
    return 0;
}

// Function to handle out-of-range checks
int handleOutOfRange(const BatteryParameter* config, float value) {
    int status = 0;
    status |= outOfMaxThreshold(config, value);
    status |= outOfMinThreshold(config, value);
    return status;
}

int checkLowerLimit(const BatteryParameter* config, BatteryStatus* status, BatteryParameterIndex index, float value) {
    if (value <= (config->min + config->warningTolerance) && value > config->min) {
        status->value[index] = value;
        status->warningLowerMessage[index] = config->warningLowerMessage; 
        return 1; 
    }
    return 0; 
}

int checkUpperLimit(const BatteryParameter* config, BatteryStatus* status, BatteryParameterIndex index, float value) {
    if (value >= (config->max - config->warningTolerance) && value < config->max) {
        status->value[index] = value;
        status->warningLowerMessage[index] = config->warningUpperMessage; 
        return 1; 
    }
    return 0; 
}
