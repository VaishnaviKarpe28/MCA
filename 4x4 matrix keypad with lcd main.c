#include "keypad.h"
#include "LCD.h"
int main()
{
unsigned char temp;
kbdInit(); // initialise keypad
LCD_init(); // initialise LCD
LCD_display(1,1,"Keypad"); // title on line 1
while(1)
{
temp = GetKey(); // read key (0 = no key pressed)
if(temp != 0)
{
LCD_cmd(0xC0); // cursor at line 2, position 1
LCD_data(temp); // show pressed key
}
}
}
