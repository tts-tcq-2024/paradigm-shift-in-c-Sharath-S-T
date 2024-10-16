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
    int tempStatus = checkStatus(temperature, &TEMP_CONFIG);
    int socStatus = checkStatus(soc, &SOC_CONFIG);
    int chargeRateStatus = checkStatus(chargeRate, &CHARGE_RATE_CONFIG);
    return tempStatus && socStatus && chargeRateStatus;
}
