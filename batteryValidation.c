#include <stdio.h>
#include "batteryValidation.h"
#include "utility.h"

// Check status function
int checkStatus(float value, const BatteryParameter* config, BatteryParameterIndex index, BatteryStatus* status)
{
    if (config->enableWarnings)
    {
        handleUpperLimit(config, status, index, value);
        handleLowerLimit(config, status, index, value); 
    }

    if (handleOutOfRange(config, status, index, value)) {
        return 0; 
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate, BatteryStatus* status) {
    int tempStatus = checkStatus(temperature, &TEMP_CONFIG, PARAM_TEMP, status);
    int socStatus = checkStatus(soc, &SOC_CONFIG, PARAM_SOC, status);
    int chargeRateStatus = checkStatus(chargeRate, &CHARGE_RATE_CONFIG, PARAM_CHARGE_RATE, status);
    return tempStatus && socStatus && chargeRateStatus;
}
