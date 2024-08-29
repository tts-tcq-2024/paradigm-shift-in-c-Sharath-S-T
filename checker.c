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

void printChargeRateOutOfRange()
{
    printf("Charge Rate out of range!\n");
}

int checkTemperature(float temperature)
{
    return (temperature < 0 || temperature > 45);
}

int checkSoc(float soc)
{
    return (soc < 20 || soc > 80);
}

int checkChargeRate(float chargeRate)
{
  return (chargeRate > 0.8);
}

void setStatus(int* status) {
    *status = 0;
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
    int status = 1;
    if (checkTemperature(temperature))
    {
        printTemperatureOutOfRange();
        setStatus(&status);
    }
    
    if (checkSoc(soc))
    {
        printSocOutOfRange();
        setStatus(&status);
    }

    if (checkChargeRate(chargeRate))
    {
        printChargeRateOutOfRange();
        setStatus(&status);
    }

    return status;
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
