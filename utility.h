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

void printErrorMessage(const char *warningMessage, float value);
int handleLowerLimit(const BatteryParameter* config, float value);
int handleUpperLimit(const BatteryParameter* config, float value);
int handleOutOfRange(const BatteryParameter* config, float value);
int outOfMaxThreshold(const BatteryParameter* config, float value);
int outOfMinThreshold(const BatteryParameter* config, float value);
int checkLowerLimit(const BatteryParameter* config, float value);
int checkUpperLimit(const BatteryParameter* config, float value);

#endif // UTILITY_H
