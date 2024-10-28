#include <stdio.h>
#include <assert.h>
#include "batteryValidation.h"

int main() {
    BatteryStatus status;
    
    assert(batteryIsOk(25, 70, 0.7, &status));   // Valid case
    assert(!batteryIsOk(50, 85, 0.9, &status));  // All Invalid Case
    assert(batteryIsOk(43, 77, 0.78, &status));  // Near Upper limit case
    assert(batteryIsOk(2, 22, 0, &status));      // Near Lower limit case
    assert(!batteryIsOk(46, 30, 0.2, &status));  // Temperature out of range
    assert(!batteryIsOk(20, 18, 0.95, &status));  // SOC and Charge Rate out of range

    printf("All test cases passed!\n");
    return 0;
}
