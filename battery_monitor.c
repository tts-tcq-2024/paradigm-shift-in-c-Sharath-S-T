// battery_monitor.c
#include "battery_monitor.h"

void printMessage(const char *message) {
    printf("%s\n", message);
}

void checkTemperature(float temperature, ParameterState *state) {
    setParameterState(state, "Temperature out of range!", "Warning: Approaching low temperature!", "Warning: Approaching high temperature!");
    
    if (temperature < TEMPERATURE_MIN || temperature > TEMPERATURE_MAX) {
        printMessage(state->errorMessage);
    } else if (WARN_FOR_TEMPERATURE) {
        float warningLowThreshold = TEMPERATURE_MIN + (TOLERANCE_PERCENTAGE * TEMPERATURE_MAX);
        float warningHighThreshold = TEMPERATURE_MAX - (TOLERANCE_PERCENTAGE * TEMPERATURE_MAX);

        if (temperature <= warningLowThreshold) {
            printMessage(state->warningLow);
        } else if (temperature >= warningHighThreshold) {
            printMessage(state->warningHigh);
        }
    }
}

void checkSoc(float soc, ParameterState *state) {
    setParameterState(state, "State of Charge out of range!", "Warning: Approaching discharge!", "Warning: Approaching charge-peak!");

    if (soc < SOC_MIN || soc > SOC_MAX) {
        printMessage(state->errorMessage);
    } else if (WARN_FOR_SOC) {
        float warningLowThreshold = SOC_MIN + (TOLERANCE_PERCENTAGE * SOC_MAX);
        float warningHighThreshold = SOC_MAX - (TOLERANCE_PERCENTAGE * SOC_MAX);

        if (soc <= warningLowThreshold) {
            printMessage(state->warningLow);
        } else if (soc >= warningHighThreshold) {
            printMessage(state->warningHigh);
        }
    }
}

void checkChargeRate(float chargeRate, ParameterState *state) {
    setParameterState(state, "Charge Rate out of range!", "", "Warning: Approaching charge rate peak!");

    if (chargeRate > CHARGE_RATE_MAX) {
        printMessage(state->errorMessage);
    } else if (WARN_FOR_CHARGE_RATE) {
        float warningHighThreshold = CHARGE_RATE_MAX - (TOLERANCE_PERCENTAGE * CHARGE_RATE_MAX);

        if (chargeRate >= warningHighThreshold) {
            printMessage(state->warningHigh);
        }
    }
}
