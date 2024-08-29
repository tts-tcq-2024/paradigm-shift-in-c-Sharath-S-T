#include <stdio.h>
#include <assert.h>

// Simplified checkStatus function with reduced complexity
int checkStatus(float value, float min, float max)
{
    return (value >= min && value <= max);
}

// Function to determine battery condition
int batteryIsOk(float temperature, float soc, float chargeRate)
{
    // Check conditions and use logical OR to combine the results
    int tempOk = checkStatus(temperature, 0, 45);
    int socOk = checkStatus(soc, 20, 80);
    int chargeRateOk = checkStatus(chargeRate, 0, 0.8);

    // Combine results using logical AND
    return tempOk && socOk && chargeRateOk;
}

int main()
{
    // Test cases
    assert(batteryIsOk(25, 70, 0.7));     // Expected: true
    assert(!batteryIsOk(50, 85, 0));      // Expected: false
    return 0;
}
