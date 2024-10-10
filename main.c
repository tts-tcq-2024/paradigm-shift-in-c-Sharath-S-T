// main.c
#include "parameter_state.h"
#include "battery_monitor.h"

int main() {
    ParameterState temperatureState;
    ParameterState socState;
    ParameterState chargeRateState;

    // Test values for temperature, SoC, and charge rate
    checkTemperature(46, &temperatureState); // Should print error
    checkTemperature(39, &temperatureState); // Should print warning
    checkTemperature(25, &temperatureState); // Should print nothing
    checkTemperature(0, &temperatureState); // Should print warning

    checkSoc(85, &socState); // Should print error
    checkSoc(76, &socState); // Should print warning
    checkSoc(50, &socState); // Should print nothing
    checkSoc(20, &socState); // Should print warning

    checkChargeRate(0.85, &chargeRateState); // Should print error
    checkChargeRate(0.77, &chargeRateState); // Should print warning
    checkChargeRate(0.70, &chargeRateState); // Should print nothing

    return 0;
}
