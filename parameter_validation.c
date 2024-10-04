// parameter_validation.c
#include <stdio.h>
#include "parameter_validation.h"

void checkBounds(float value, float min, float max, const char *errorMessage) {
    if (value < min || value > max) {
        printMessage(errorMessage);
    }
}

void checkWarnings(float value, float min, float max, const ParameterState *state) {
    float warningLowThreshold = min + (TOLERANCE_PERCENTAGE * max);
    float warningHighThreshold = max - (TOLERANCE_PERCENTAGE * max);

    if (value <= warningLowThreshold) {
        printMessage(state->warningLow);
    } else if (value >= warningHighThreshold) {
        printMessage(state->warningHigh);
    }
}
