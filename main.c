#include <stdio.h>
#include <assert.h>
#include "batteryValidation.h"

int main() {
    assert(batteryIsOk(25, 70, 0.7));   // Valid case
    assert(!batteryIsOk(50, 85, 0.9));  // All Invalid Case
    assert(batteryIsOk(43, 77, 0.78));  // Near Upper limit case
    assert(batteryIsOk(2, 22, 0));      // Near Lower limit case
    assert(!batteryIsOk(46, 30, 0.2));  // Temperature out of range
    assert(!batteryIsOk(20, 18, 0.95));  // SOC and Charge Rate out of range

    printf("All test cases passed!\n");
    return 0;
}
