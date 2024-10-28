#include <stdio.h>
#include <assert.h>
#include "batteryValidation.h"

// Function to reset BatteryStatus structure
void clearBatteryStatus(BatteryStatus* status) {
    for (int i = 0; i < PARAM_COUNT; i++) {
        status->value[i] = 0.0;
        status->outOfRangeMessage[i] = NULL;
        status->warningLowerMessage[i] = NULL;
        status->warningUpperMessage[i] = NULL;
    }
}

// Function to print the value of a parameter
void printParameterValue(float value, int index) {
    printf("Parameter %d:\n", index + 1);
    printf("  Value: %.2f\n", value);
}

// Function to print messages for a parameter
void printMessages(const char* message, const char* lowerWarning, const char* upperWarning) {
    if (message != NULL) {
        printf("  Out of Range Message: %s\n", message);
    }
    if (lowerWarning != NULL) {
        printf("  Lower Limit Warning Message: %s\n", lowerWarning);
    }
    if (upperWarning != NULL) {
        printf("  Upper Limit Warning Message: %s\n", upperWarning);
    }
}

// Function to print BatteryStatus structure contents
void printBatteryStatus(const BatteryStatus* status) {
    for (int i = 0; i < PARAM_COUNT; i++) {
        printParameterValue(status->value[i], i);
        printMessages(status->outOfRangeMessage[i], status->warningLowerMessage[i], status->warningUpperMessage[i]);
    }
}

int main() {
    BatteryStatus status;

    // Test cases with clearing and printing after each
    clearBatteryStatus(&status);
    assert(batteryIsOk(25, 70, 0.7, &status));   // Valid case
    printBatteryStatus(&status);

    clearBatteryStatus(&status);
    assert(!batteryIsOk(50, 85, 0.9, &status));  // All Invalid Case
    printBatteryStatus(&status);

    clearBatteryStatus(&status);
    assert(batteryIsOk(43, 77, 0.78, &status));  // Near Upper limit case
    printBatteryStatus(&status);

    clearBatteryStatus(&status);
    assert(batteryIsOk(2, 22, 0, &status));      // Near Lower limit case
    printBatteryStatus(&status);

    clearBatteryStatus(&status);
    assert(!batteryIsOk(46, 30, 0.2, &status));  // Temperature out of range
    printBatteryStatus(&status);

    clearBatteryStatus(&status);
    assert(!batteryIsOk(20, 18, 0.95, &status)); // SOC and Charge Rate out of range
    printBatteryStatus(&status);

    printf("All test cases passed!\n");
    return 0;
}
