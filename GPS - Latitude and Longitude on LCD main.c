#include<lpc214x.h>
#include "stdio.h"
#include "lcd.h"
#include "UART.h"
/* Get characters from UART till '*' (end of GPS sentence) */
void GPS_string(unsigned char *temp)
{
unsigned int i=0;
do
{
temp[i] = UART_GetChar();
}
while(temp[i++] != '*'); // keep reading till '*' comes
temp[i] = '\0'; // end the string
}
/* Show latitude and longitude on LCD */
void GPS_display(unsigned char *lat, unsigned char *lon)
{
unsigned int i;
LCD_cmd(0x84); // line 1, position 5
for(i=0;i<2;i++)
LCD_data(*lat++); // degrees
LCD_data('\''); // degree symbol
for(i=0;i<8;i++)
LCD_data(*lat++); // minutes + N/S
LCD_cmd(0xC4); // line 2, position 5
for(i=0;i<3;i++)
LCD_data(*lon++); // degrees
LCD_data('\''); // degree symbol
for(i=0;i<8;i++)
LCD_data(*lon++); // minutes + E/W
}
/* Eg: $GPGGA,155635,3730.4379,N,02357.4137,E,1,04,5.6,3.8,M,34.5,M,,*41 */
int main()
{
unsigned char ch, temp[100], lat[15], lon[15];
unsigned int i=0, j=0;
LCD_init();
UartInit(9600);
LCD_display(1,1,"GPS Program");
delay(200000);
LCD_cmd(0x01); // clear display
LCD_display(1,1,"LAT:");
LCD_display(2,1,"LON:");
while(1)
{
if((ch = UART_GetChar()) == '$') // sentence starts with '$'
{
GPS_string(temp); // read till '*'
if(temp[2] == 'G' && temp[3] == 'G' && temp[4] == 'A') // only GPGGA
{
i=0;
j=0;
while(temp[i++] != ','); // skip GPGGA
while(temp[i++] != ','); // skip time
while(temp[i] != ',') // copy latitude

Microcontrollers & VLSI Design Lab (PCC304) - final programs, 8051 and LPC2148 Page 16
lat[j++] = temp[i++];
while(temp[i++] != ',');
lat[j++] = temp[i++]; // N or S
j=0;
while(temp[i++] != ',');
while(temp[i] != ',') // copy longitude
lon[j++] = temp[i++];
while(temp[i++] != ',');
lon[j++] = temp[i++]; // E or W
GPS_display(lat,lon); // show on LCD
}
}
}
}
