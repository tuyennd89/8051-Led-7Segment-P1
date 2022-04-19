#include <AT89X52.h>

#define LED7_PORT           P0
#define BTN_PORT            P3
#define BTN_POS             2
#define BTN_MASK            0x3

#define BTN_NO_PRESS        0x3
#define BTN1_IS_PRESSED     0x2
#define BTN2_IS_PRESSED     0x1

/** Led 7 Data                   0     1     2     3     4     5     6     7     8     9   */
unsigned char u8ArrLed7[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};



void Delay(unsigned int time);
unsigned char Button_Read();

void main(void)
{
    char u8Cnt=0;
    unsigned char u8Btnvalue = 0;
    
	/** Default LED7 is turn off */
    LED7_PORT = 0xFF;
	while(1)
	{
        LED7_PORT = u8ArrLed7[u8Cnt];
        u8Btnvalue = Button_Read();
        if(u8Btnvalue == 1)
        {
            u8Cnt++;
            if(u8Cnt > 9)
                u8Cnt = 0;
        }else if(u8Btnvalue == 2)
        {
            u8Cnt--;
            if(u8Cnt < 0)
                u8Cnt = 9;
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

/** Read button
    Return 0 if no button press
    Return 1 if button 1 is pressed
    Return 2 if button 2 is pressed
 */
unsigned char Button_Read(void)
{
    unsigned char u8RetVal = 0;
    unsigned char u8BtnCurrVal = BTN_NO_PRESS;
    static unsigned char u8BtnPreVal = BTN_NO_PRESS;
    
    u8BtnCurrVal = ((BTN_PORT >> BTN_POS) & BTN_MASK);
    
    if(u8BtnPreVal != u8BtnCurrVal)
    {
        if(BTN1_IS_PRESSED == u8BtnCurrVal)
        {
            u8RetVal = 1;
        } else if(BTN2_IS_PRESSED == u8BtnCurrVal)
        {
            u8RetVal = 2;
        }
        u8BtnPreVal = u8BtnCurrVal;
    }
    
    return u8RetVal;
}











