#include "battery_monitor.h"
#include "parameter_validation.h"

void printMessage(const char *message)
{
    printf("%s\n", message);
}

void checkTemperature(float temperature, ParameterState *state) 
{
    setParameterState(state, "Temperature out of range!", 
                     "Warning: Approaching low temperature!", 
                     "Warning: Approaching high temperature!");
    
    checkBounds(temperature, TEMPERATURE_MIN, TEMPERATURE_MAX, state->errorMessage);
    
    if (WARN_FOR_TEMPERATURE) 
    {
        checkWarnings(temperature, TEMPERATURE_MIN, TEMPERATURE_MAX, state);
    }
}

void checkSoc(float soc, ParameterState *state) 
{
    setParameterState(state, "State of Charge out of range!", 
                     "Warning: Approaching SOC discharge!", 
                     "Warning: Approaching SOC charge-peak!");
    
    checkBounds(soc, SOC_MIN, SOC_MAX, state->errorMessage);
    
    if (WARN_FOR_SOC) 
    {
        checkWarnings(soc, SOC_MIN, SOC_MAX, state);
    }
}

void checkChargeRate(float chargeRate, ParameterState *state) 
{
    setParameterState(state, "Charge Rate out of range!", 
                     "", 
                     "Warning: Approaching charge rate peak!");
    
    checkBounds(chargeRate, 0, CHARGE_RATE_MAX, state->errorMessage);
    
    if (WARN_FOR_CHARGE_RATE) 
    {
        handleWarningHigh(chargeRate, CHARGE_RATE_MAX, state);
    }
}
