// parameter_state.c
#include "parameter_state.h"

void setParameterState(ParameterState *state, const char *errorMessage, const char *warningLow, const char *warningHigh) {
    state->errorMessage = errorMessage;
    state->warningLow = warningLow;
    state->warningHigh = warningHigh;
}
