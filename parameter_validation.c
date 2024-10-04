// parameter_validation.c
#include <stdio.h>
#include "parameter_validation.h"

int isOutOfRange(float value, float min, float max) {
    return value < min || value > max;
}

int isWarningLow(float value, float min, float max) {
    float warningLowThreshold = min + (TOLERANCE_PERCENTAGE * max);
    return value <= warningLowThreshold;
}

int isWarningHigh(float value, float max) {
    float warningHighThreshold = max - (TOLERANCE_PERCENTAGE * max);
    return value >= warningHighThreshold;
}

void checkBounds(float value, float min, float max, const char *errorMessage) {
    if (isOutOfRange(value, min, max)) {
        printMessage(errorMessage);
    }
}

void checkWarnings(float value, float min, float max, const ParameterState *state) {
    if (isWarningLow(value, min, max)) {
        printMessage(state->warningLow);
    }
    if (isWarningHigh(value, max)) {
        printMessage(state->warningHigh);
    }
}}
