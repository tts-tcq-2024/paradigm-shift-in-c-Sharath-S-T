// config_parameters.h
#ifndef CONFIG_PARAMETERS_H
#define CONFIG_PARAMETERS_H

#define CHARGE_RATE_MAX 0.8
#define TEMPERATURE_MIN 0.0
#define TEMPERATURE_MAX 45.0
#define SOC_MIN 20.0
#define SOC_MAX 80.0

#define TOLERANCE_PERCENTAGE 0.05
#define WARN_FOR_TEMPERATURE 1 // Set to 1 to enable temperature warnings
#define WARN_FOR_SOC 1         // Set to 1 to enable SoC warnings
#define WARN_FOR_CHARGE_RATE 1 // Set to 1 to enable charge rate warnings

#endif // CONFIG_PARAMETERS_H
