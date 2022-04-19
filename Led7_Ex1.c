#include <AT89X52.h>

#define LED7_PORT           P0

/** Led 7 Data                   0     1     2     3     4     5     6     7     8     9   */
unsigned char u8ArrLed7[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};



void Delay(unsigned int time);

void main(void)
{
    unsigned char u8Cnt=0;
    
	/** Default LED7 is turn off */
    LED7_PORT = 0xFF;
	while(1)
	{
        for(u8Cnt=0;u8Cnt<10;u8Cnt++)
        {
            LED7_PORT = u8ArrLed7[u8Cnt];
            Delay(500);
        }
	}
}


/** Delay */
void Delay(unsigned int time)
{
    unsigned int i,j;
    
    for(i=0;i<time;i++)
    {
        for(j=0;j<125;j++);
    }
}











