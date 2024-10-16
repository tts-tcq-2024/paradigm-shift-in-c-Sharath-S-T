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
    .warningUpperMessage = "Warning: Approaching charge-peak!",
    .warningLowerMessage = "Warning: Approaching discharge!"
};

const BatteryParameter CHARGE_RATE_CONFIG = {
    .min = CHARGE_RATE_MIN,
    .max = CHARGE_RATE_MAX,
    .warningTolerance = CHARGE_RATE_MAX * WARNING_TOLERANCE_PERCENT,
    .enableWarnings = CHARGE_RATE_WARNING ,
    .outOfRangeMessage = "Charge Rate out of range!",
    .warningUpperMessage = "Warning: Approaching charge rate limit!",
    .warningLowerMessage = "Warning: Charge rate is too low!"
};

void printWarning(float value, const char *warningMessage) {
    printf("%s (Value: %.2f)\n", warningMessage, value);
}

// Function to handle lower limit warnings
int handleLowerLimit(const BatteryParameter* config, float value) {
    if (value <= (config->min + config->warningTolerance) && value > config->min) {
        printWarning(value, config->warningLowerMessage); 
        return 1; 
    }
    return 0; 
}

// Function to handle upper limit warnings
int handleUpperLimit(const BatteryParameter* config, float value) {
    if (value >= (config->max - config->warningTolerance) && value < config->max) {
        printWarning(value, config->warningUpperMessage); 
        return 1; 
    }
    return 0; 
}

// Function to handle out-of-range checks
int handleOutOfRange(const BatteryParameter* config, float value) {
    if (value > config->max || value < config->min) {
        printErrorMessage(config->outOfRangeMessage);
        return 1;
    }
    return 0;
}
