#include "LPC214x.h"
#include "UART.h"
#include "I2C.h"
#include "EEPROM.h"
#include "stdio.h"
unsigned char write_array[10] = {0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0xC5};
unsigned char read_array[10];
int main()
{
unsigned int i;
PINSEL2 = 0; // PORT1 as GPIO (LEDs)
IODIR1 = 0xFF000000; // LEDs P1.24-P1.31 as output
IOCLR1 = 0xFF << 24; // all LEDs OFF
UartInit(9600); // UART0 at 9600 baud
printf("I2C EEPROM\r\n");
I2CInit(); // initialise I2C
printf("Writing Data.....\r\n");
EEPROM_write(0x1349, write_array, 10); // address 0x1349, 10 bytes
printf("Reading Data.....\r\n");
EEPROM_read(0x1349, read_array, 10); // read back same 10 bytes
for(i=0;i<10;i++)
printf("write_array[%d] = 0x%02X\tread_array[%d] = 0x%02X\r\n",
i, write_array[i], i, read_array[i]);
IOSET1 = read_array[9] << 24; // last byte (0xC5) on LEDs
while(1); // stop here
}
