// battery_monitor.c
#include "battery_monitor.h"

void printMessage(const char *message) {
    printf("%s\n", message);
}

static void checkWarnings(float value, float min, float max, const ParameterState *state) {
    float warningLowThreshold = min + (TOLERANCE_PERCENTAGE * max);
    float warningHighThreshold = max - (TOLERANCE_PERCENTAGE * max);

    if (value <= warningLowThreshold) {
        printMessage(state->warningLow);
    } else if (value >= warningHighThreshold) {
        printMessage(state->warningHigh);
    }
}

void checkTemperature(float temperature, ParameterState *state) {
    setParameterState(state, "Temperature out of range!", 
                     "Warning: Approaching low temperature!", 
                     "Warning: Approaching high temperature!");
    
    checkBounds(temperature, TEMPERATURE_MIN, TEMPERATURE_MAX, state->errorMessage);
    
    if (WARN_FOR_TEMPERATURE) {
        checkWarnings(temperature, TEMPERATURE_MIN, TEMPERATURE_MAX, state);
    }
}

void checkSoc(float soc, ParameterState *state) {
    setParameterState(state, "State of Charge out of range!", 
                     "Warning: Approaching discharge!", 
                     "Warning: Approaching charge-peak!");
    
    checkBounds(soc, SOC_MIN, SOC_MAX, state->errorMessage);
    
    if (WARN_FOR_SOC) {
        checkWarnings(soc, SOC_MIN, SOC_MAX, state);
    }
}

void checkChargeRate(float chargeRate, ParameterState *state) {
    setParameterState(state, "Charge Rate out of range!", 
                     "", 
                     "Warning: Approaching charge rate peak!");
    
    checkBounds(chargeRate, 0, CHARGE_RATE_MAX, state->errorMessage);
    
    if (chargeRate <= CHARGE_RATE_MAX && WARN_FOR_CHARGE_RATE) {
        float warningHighThreshold = CHARGE_RATE_MAX - (TOLERANCE_PERCENTAGE * CHARGE_RATE_MAX);
        if (chargeRate >= warningHighThreshold) {
            printMessage(state->warningHigh);
        }
    }
}
