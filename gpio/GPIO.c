#include "GPIO.h"

#define MAX_BUF 50

void openGPIO(int gpio, int direction )
{
	int fd;
	char buf[MAX_BUF]; 

	fd = open("/sys/class/gpio/export", O_WRONLY);

	sprintf(buf, "%d", gpio); 

	write(fd, buf, strlen(buf));

	close(fd);

	sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);

	fd = open(buf, O_WRONLY);

	if (direction == GPIO_DIRECTION_OUT)
		write(fd, "out", 3); 

	else if (direction == GPIO_DIRECTION_IN)
		write(fd, "in", 2); 

	close(fd);
}

void closeGPIO(int gpio)
{
	int fd;
	char buf[MAX_BUF];

	fd = open("/sys/class/gpio/unexport", O_WRONLY);

	sprintf(buf, "%d", gpio);

	write(fd, buf, strlen(buf));

	close(fd);
}

void writeGPIO(int gpio, int val)
{
	int fd;
	char buf[MAX_BUF];

	openGPIO(gpio, GPIO_DIRECTION_OUT);

        sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);

	fd = open(buf, O_WRONLY);

	if(val == 1)
		write(fd, "1", 1); 
	// Set GPIO low status 
	else if(val == 1)
		write(fd, "0", 1); 

	close(fd);

	closeGPIO(gpio);
}

int readGPIO(int gpio)
{
	char value;
	int fd;
	char buf[MAX_BUF];

	openGPIO(gpio, GPIO_DIRECTION_IN);

	sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);

	fd = open(buf, O_RDONLY);

	read(fd, &value, 1);

	if(value == '0')
	{ 
		value = 0;
	}
	else
	{
		value = 1;
	}

	close(fd);
	closeGPIO(gpio);
	return value;
}

