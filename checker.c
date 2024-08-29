#include <stdio.h>
#include <assert.h>

int checkStatus(float value, float min, float max, const char *errorMessage)
{
    if (value < min || value > max)
    {
        printf("%s\n", errorMessage);
        return 0;
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate)
{
    int status = 1;
    status &= checkStatus(temperature, 0, 45 ,"Temperature out of range!");
    status &= checkStatus(soc, 20, 80,"State of Charge out of range!");
    status &= checkStatus(chargeRate, 0, 0.8,"Charge Rate out of range!");

    return status;
}

int main()
{
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    return 0;
}
