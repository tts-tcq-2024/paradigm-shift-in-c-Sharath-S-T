// parameter_validation.h
#ifndef PARAMETER_VALIDATION_H
#define PARAMETER_VALIDATION_H

#include "config_parameters.h"
#include "parameter_state.h"

void printMessage(const char *message, float value);
void checkBounds(float value, float min, float max, const char *errorMessage);
void checkWarnings(float value, float min, float max, const ParameterState *state);

#endif // PARAMETER_VALIDATION_H
