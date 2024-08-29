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
    if(temperature < 0 || temperature > 45)
    {
        printTemperatureOutOfRange();
        return 0;
    }
    return 1;
}

int checkSoc(float soc)
{
    if(soc < 20 || soc > 80)
    {
        printSocOutOfRange();
        return 0;
    }
    return 1;
}

int checkChargeRate(float chargeRate)
{
  if(chargeRate > 0.8)
  {
    printChargeRateOutOfRange();
    return 0;
  }
  return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
    int status = 1;
    status &= checkTemperature(temperature);
    status &= checkSoc(soc);
    status &= checkChargeRate(chargeRate);
    return status;
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
