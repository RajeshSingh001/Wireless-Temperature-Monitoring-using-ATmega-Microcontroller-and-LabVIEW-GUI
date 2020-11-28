#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"


void delay(uint16_t count)
{
	uint16_t i;
	for(i=0;i<count;i++)
	_delay_ms(1);
}
void main()
{
	uint16_t adc_val;
	uint8_t FSR1;
	InitLCD(0);
	USARTInit(51);
	InitADC();
	LCDClear();
	LCDWriteString("Temperature");
	LCDWriteStringXY(0,1,"Monitoring Node");
	delay(20);
	LCDClear();
	LCDWriteString("Temperature 0C");
	while(1)
	{
		adc_val=ReadADC(0);
        FSR1=adc_val/2;
		delay(100);
        USARTWriteChar(FSR1);
	  	
		LCDWriteIntXY(0,1,FSR1,3);
	    
		delay(100);
		}
}
