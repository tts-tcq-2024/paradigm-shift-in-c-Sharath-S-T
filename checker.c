#include <stdio.h>
#include <assert.h>

int checkValue(float value, float min, float max, const char *errorMessage)
{
    if (value < min || value > max)
    {
        printf("%s\n", errorMessage);
        return 0;
    }
    return 1;
}

int checkTemperature(float temperature)
{
    return checkValue(temperature, 0, 45, "Temperature out of range!");
}

int checkSoc(float soc)
{
    return checkValue(soc, 20, 80, "State of Charge out of range!");
}

int checkChargeRate(float chargeRate)
{
    return checkValue(chargeRate, 0, 0.8, "Charge Rate out of range");
}

int batteryIsOk(float temperature, float soc, float chargeRate)
{
    return checkTemperature(temperature) & checkSoc(soc) & checkChargeRate(chargeRate);
}

int main()
{
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    return 0;
}
