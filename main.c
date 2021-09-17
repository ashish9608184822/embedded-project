#include <avr/io.h>			/*Includes AVR library*/
#include <util/delay.h>
#include <string.h>
#include "passanger.h"

int main(void)
{
    LCD_Init();
    InitADC();
    uint16_t temp;
    int a;
    char str[10];
    DDRD&=~(1<<PD0);
    PORTD|=(1<<PD0);
    DDRB|=(1<<PB2);

    while(1)
    {
        if(!(PIND&(1<<PD0)))
        {
            temp = ReadADC(0);
            a = ADC;
            if(a>=0 && a<=200)
                {
                    strcpy(str,"20 Degree");
                    PORTB|=(1<<PB2);
                }
            else if(a>200 && a<=350)
                {
                    strcpy(str,"23 Degree");
                    PORTB|=(1<<PB2);
                }
            else if(a>350 && a<=500)
                {
                    strcpy(str,"25 Degree");
                    PORTB|=(1<<PB2);
                }
            else if(a>500 && a<=600)
                {
                    strcpy(str,"27 Degree");
                    PORTB &=~(1<<PB2);
                }
            else if(a>600 && a<=700)
                {
                    strcpy(str,"29 Degree");
                    PORTB &=~(1<<PB2);
                }
            else if(a>700 && a<=850)
                {
                    strcpy(str,"31 Degree");
                    PORTB &=~(1<<PB2);
                }
            else if(a>850 && a<=1024)
                {
                    strcpy(str,"33 Degree");
                    PORTB &=~(1<<PB2);
                }


            LCD_String("Temprature");
                LCD_Command(0xC0);
	            LCD_String(str);
                _delay_ms(500);
        }
        else{
            LCD_Clear();
        }
    }
    return 0;
}
