#include "GPIO.h"

int main(void)
{

//	printf("READED: %d\n", readGPIO(27));
while(1)
{
//	writeGPIO(3, 0);	
//	sleep(1);
//	writeGPIO(3, 1);
//	sleep(1);
	if (!readGPIO(GP_5)){
		printf("Button Pressed\n");
		while(!readGPIO(GP_5));
	}

}
        puts("Finished LED blink GP_LED - gpio-3 on Galileo board.");

        return 0;
}
