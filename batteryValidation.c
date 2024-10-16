#include <stdio.h>
#include "batteryValidation.h"
#include "utility.h"

int checkRange(float value, float min, float max) {
    return value >= min && value <= max;
}

int checkStatus(float value, float min, float max, float warningTolerance, const char *errorMessage, const char *warningMessage) {
    if (!checkRange(value, min, max)) {
        printf("%s (Value: %.2f, Range: [%.2f, %.2f])\n", errorMessage, value, min, max);
        return 0; // Out of range
    }
    if ((value >= (max - warningTolerance)) || (value <= (min + warningTolerance))) {
        printWarning(value, warningMessage);
    }
    return 1; // Within range
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int tempStatus = checkStatus(temperature, TEMP_MIN, TEMP_MAX, TEMP_WARNING_TOLERANCE, 
                                 "Temperature out of range!", "Warning: Approaching temperature limit!");
    int socStatus = checkStatus(soc, SOC_MIN, SOC_MAX, SOC_WARNING_TOLERANCE, 
                                "State of Charge out of range!", "Warning: Approaching discharge/charge-peak!");
    int chargeRateStatus = checkStatus(chargeRate, CHARGE_RATE_MIN, CHARGE_RATE_MAX, 
                                        CHARGE_RATE_WARNING_TOLERANCE, "Charge Rate out of range!", 
                                        "Warning: Approaching charge rate limit!");
    return tempStatus && socStatus && chargeRateStatus;
}
