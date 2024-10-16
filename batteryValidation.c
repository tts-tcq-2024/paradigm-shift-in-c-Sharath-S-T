#include <stdio.h>
#include "batteryValidation.h"
#include "utility.h"

// Check status function
int checkStatus(float value, const BatteryParameter* config)
{
    #if config->enableWarnings
        handleUpperLimit(config, value);
        handleLowerLimit(config, value); 
    #endif

    if (handleOutOfRange(config, value)) {
        return 0; 
    }
    return 1;
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
