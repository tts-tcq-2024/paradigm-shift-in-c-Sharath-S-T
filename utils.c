#include <stdio.h>
#include "utility.h"

void printWarning(float value, const char *warningMessage) {
    printf("%s (Value: %.2f)\n", warningMessage, value);
}
