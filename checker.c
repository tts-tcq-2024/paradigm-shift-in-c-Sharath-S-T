#include <stdio.h>
#include <assert.h>

void printTemperatureOutOfRange()
{
    printf("Temperature out of range!\n");
}

void printSocOutOfRange()
{
    printf("State of Charge out of range!\n");
}

void printChargeRateOutOfRange() {
    printf("Charge Rate out of range!\n");
}

int checkValue(float value, float min, float max, void (*printErrorMessage)())
{
    if (value < min || value > max)
    {
        printErrorMessage();
        return 0;
    }
    return 1;
}

int checkTemperature(float temperature)
{
    return checkValue(temperature, 0, 45, printTemperatureOutOfRange);
}

int checkSoc(float soc)
{
    return checkValue(soc, 20, 80, printSocOutOfRange);
}

int checkChargeRate(float chargeRate)
{
    return checkValue(chargeRate, 0, 0.8, printChargeRateOutOfRange);
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
