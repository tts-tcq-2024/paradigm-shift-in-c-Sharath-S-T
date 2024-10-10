// parameter_state.h
#ifndef PARAMETER_STATE_H
#define PARAMETER_STATE_H

typedef struct {
    const char *errorMessage;
    const char *warningLow;
    const char *warningHigh;
} ParameterState;

void setParameterState(ParameterState *state, const char *errorMessage, const char *warningLow, const char *warningHigh);

#endif // PARAMETER_STATE_H
