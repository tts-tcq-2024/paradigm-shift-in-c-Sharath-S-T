#include <stdio.h>
#include <assert.h>
#include "batteryValidation.h"

int main() {
    // Test cases for battery validation
    assert(batteryIsOk(25, 70, 0.7)); // Normal values
    assert(!batteryIsOk(50, 85, 0));   // Out of range values
    assert(batteryIsOk(44, 79, 0.79)); // Near upper limits
    assert(batteryIsOk(6, 21, 0.05));     // Near lower limits

    // Additional test cases
    assert(batteryIsOk(30, 22, 0.5));  // Valid case
    assert(!batteryIsOk(46, 30, 0.2));  // Temperature out of range
    assert(!batteryIsOk(20, 18, 0.9));  // SOC and Charge Rate out of range

    printf("All test cases passed!\n");
    return 0;
}
