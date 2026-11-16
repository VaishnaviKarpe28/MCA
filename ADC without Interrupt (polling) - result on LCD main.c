#include "adc.h"
#include "LCD.h"
#include <stdio.h>
void delay(unsigned int time)
{
unsigned int i,j;
for(i = 0; i < time; i++)
for(j = 0; j < 5000; j++);
}
int main()
{
unsigned int temp;
char buf[20];
LCD_init(); // initialise LCD
ADCInit(); // initialise ADC
while(1)
{
temp = ADC_Read(1); // read channel AD0.1 (P0.28)
sprintf(buf,"ADC result:0x%03X",temp); // convert value to string
LCD_display(1,1,buf); // show on LCD line 1
delay(20);
}
}
