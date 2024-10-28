#include <stdio.h>
#include "batteryValidation.h"
#include "utility.h"

// Check status function
int checkStatus(float value, const BatteryParameter* config, BatteryParameterIndex index)
{
    if (config->enableWarnings)
    {
        handleUpperLimit(config, value, index);
        handleLowerLimit(config, value, index); 
    }

    if (handleOutOfRange(config, value, index)) {
        return 0; 
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int tempStatus = checkStatus(temperature, &TEMP_CONFIG, PARAM_TEMP);
    int socStatus = checkStatus(soc, &SOC_CONFIG, PARAM_SOC);
    int chargeRateStatus = checkStatus(chargeRate, &CHARGE_RATE_CONFIG, PARAM_CHARGE_RATE);
    return tempStatus && socStatus && chargeRateStatus;
}
