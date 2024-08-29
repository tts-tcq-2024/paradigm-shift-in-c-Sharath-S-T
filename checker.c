#include <stdio.h>
#include <assert.h>

int is_Within_Range(float value, float minimum, float maximum) {
  return (value >= minimum && value <= maximum);
}

int check_scope(float value, float minimum, float maximum, const char* errorMessage) {
  if (!is_Within_Range(value, minimum, maximum)) {
    printf("%s\n", errorMessage);
    return 0;
  }
  return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  int Temp_Ok = check_scope(temperature, 0, 45, "The temperature is out of range!");
  int Soc_Ok = check_scope(soc, 20, 80, "The state of Charge is out of range!");
  int ChargeRate_Ok = check_scope(chargeRate, 0, 0.8, "The charge Rate is out of range!");

  return Temp_Ok && Soc_Ok && ChargeRate_Ok;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
