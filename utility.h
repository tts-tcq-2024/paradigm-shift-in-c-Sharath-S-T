#ifndef UTILITY_H
#define UTILITY_H

// Structure to hold battery parameters
typedef struct {
    float min;
    float max;
    float warningTolerance;
    int enableWarnings;
    const char* outOfRangeMessage;
    const char* warningLowerMessage;
    const char* warningUpperMessage;
} BatteryParameter;

// Function declarations
extern const BatteryParameter TEMP_CONFIG;
extern const BatteryParameter SOC_CONFIG;
extern const BatteryParameter CHARGE_RATE_CONFIG;

typedef enum {
    PARAM_TEMP,
    PARAM_SOC,
    PARAM_CHARGE_RATE,
    PARAM_COUNT // This will give the count of parameters
} BatteryParameterIndex;

typedef struct {
    float value[PARAM_COUNT];              // Stores temperature, SOC, charge rate
    const char* outOfRangeMessage[PARAM_COUNT]; // Out of range messages
    const char* warningLowerMessage[PARAM_COUNT]; // Lower limit warning messages
    const char* warningUpperMessage[PARAM_COUNT]; // Upper limit warning messages
} BatteryStatus;

// void printErrorMessage(const char *warningMessage, float value);
int handleLowerLimit(const BatteryParameter* config, BatteryStatus* status, BatteryParameterIndex index, float value)
int handleUpperLimit(const BatteryParameter* config, BatteryStatus* status, BatteryParameterIndex index, float value);
int handleOutOfRange(const BatteryParameter* config, BatteryParameterIndex index, float value);
int outOfMaxThreshold(const BatteryParameter* config, BatteryStatus* status, BatteryParameterIndex index, float value);
int outOfMinThreshold(const BatteryParameter* config, BatteryStatus* status, BatteryParameterIndex index, float value);
int checkLowerLimit(const BatteryParameter* config, BatteryStatus* status, BatteryParameterIndex index, float value);
int checkUpperLimit(const BatteryParameter* config, BatteryStatus* status, BatteryParameterIndex index, float value);

#endif // UTILITY_H
