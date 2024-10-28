#include <stdio.h>
#include <assert.h>
#include <string.h>
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

int main() {
    BatteryStatus status;

    // Test cases with clearing and asserting after each
    clearBatteryStatus(&status);
    assert(batteryIsOk(25, 70, 0.7, &status));   // Valid case
    
    clearBatteryStatus(&status);
    assert(!batteryIsOk(50, 85, 0.9, &status));  // All Invalid Case
    assert(status.outOfRangeMessage[0] != NULL);
    assert(strcmp(status.outOfRangeMessage[0], "Temperature out of range!") == 0);
    assert(status.outOfRangeMessage[1] != NULL);
    assert(strcmp(status.outOfRangeMessage[1], "State of Charge out of range!") == 0);
    assert(status.outOfRangeMessage[2] != NULL);
    assert(strcmp(status.outOfRangeMessage[2], "Charge Rate out of range!") == 0);

    clearBatteryStatus(&status);
    assert(batteryIsOk(43, 77, 0.78, &status));  // Near Upper limit case
    assert(status.warningLowerMessage[0] != NULL);
    assert(strcmp(status.warningLowerMessage[0], "Warning: Temperature approaching upper limit!") == 0);
    assert(status.warningLowerMessage[1] != NULL);
    assert(strcmp(status.warningLowerMessage[1], "Warning: Approaching charge-peak!(upper limit)") == 0);
    assert(status.warningLowerMessage[2] != NULL);
    assert(strcmp(status.warningLowerMessage[2], "Warning: Approaching charge rate limit! (upper_limit)") == 0);

    clearBatteryStatus(&status);
    assert(batteryIsOk(2, 22, 0, &status));      // Near Lower limit case
    assert(status.warningLowerMessage[0] != NULL);
    assert(strcmp(status.warningLowerMessage[0], "Warning: Temperature approaching lower limit!") == 0);
    assert(status.warningLowerMessage[1] != NULL);
    assert(strcmp(status.warningLowerMessage[1], "Warning: Approaching discharge! (lower limit)") == 0);
    assert(status.warningLowerMessage[2] == NULL);

    clearBatteryStatus(&status);
    assert(!batteryIsOk(46, 30, 0.2, &status));  // Temperature out of range
    assert(status.outOfRangeMessage[0] != NULL);
    assert(strcmp(status.outOfRangeMessage[0], "Temperature out of range!") == 0);

    clearBatteryStatus(&status);
    assert(!batteryIsOk(20, 18, 0.95, &status)); // SOC and Charge Rate out of range
    assert(status.outOfRangeMessage[1] != NULL);
    assert(strcmp(status.outOfRangeMessage[1], "State of Charge out of range!") == 0);
    assert(status.outOfRangeMessage[2] != NULL);
    assert(strcmp(status.outOfRangeMessage[2], "Charge Rate out of range!") == 0);

    printf("All test cases passed!\n");
    return 0;
}
