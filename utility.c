#include <stdio.h>
#include "utility.h"
#include "battery_validation.h"

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
