#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define GP_LED                 3
#define GP_5		       17
#define GP_6		       24
#define GP_7		       27
#define GPIO_DIRECTION_IN      1
#define GPIO_DIRECTION_OUT     0

void openGPIO(int gpio, int direction);

void closeGPIO(int gpio);

void writeGPIO(int gpio, int val);

int readGPIO(int gpio);
