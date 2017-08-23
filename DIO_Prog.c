#include "types.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "utl.h"


extern void DIO_Init(void)
{
	DDRA = Conc(DIO_PIN7_DIR,DIO_PIN6_DIR,DIO_PIN5_DIR,DIO_PIN4_DIR,DIO_PIN3_DIR,DIO_PIN2_DIR,DIO_PIN1_DIR,DIO_PIN0_DIR);
    DDRB = Conc(DIO_PIN15_DIR,DIO_PIN14_DIR,DIO_PIN13_DIR,DIO_PIN12_DIR,DIO_PIN11_DIR,DIO_PIN10_DIR,DIO_PIN9_DIR,DIO_PIN8_DIR);
	DDRC = Conc(DIO_PIN23_DIR,DIO_PIN22_DIR,DIO_PIN21_DIR,DIO_PIN20_DIR,DIO_PIN19_DIR,DIO_PIN18_DIR,DIO_PIN17_DIR,DIO_PIN16_DIR);
	DDRD = Conc(DIO_PIN31_DIR,DIO_PIN30_DIR,DIO_PIN29_DIR,DIO_PIN28_DIR,DIO_PIN27_DIR,DIO_PIN26_DIR,DIO_PIN25_DIR,DIO_PIN24_DIR);
	
 	PORTA = Conc(DIO_PIN7_INIT,DIO_PIN6_INIT,DIO_PIN5_INIT,DIO_PIN4_INIT,DIO_PIN3_INIT,DIO_PIN2_INIT,DIO_PIN1_INIT,DIO_PIN0_INIT);
  	PORTB = Conc(DIO_PIN15_INIT,DIO_PIN14_INIT,DIO_PIN13_INIT,DIO_PIN12_INIT,DIO_PIN11_INIT,DIO_PIN10_INIT,DIO_PIN9_INIT,DIO_PIN8_INIT);
   	PORTC = Conc(DIO_PIN23_INIT,DIO_PIN22_INIT,DIO_PIN21_INIT,DIO_PIN20_INIT,DIO_PIN19_INIT,DIO_PIN18_INIT,DIO_PIN17_INIT,DIO_PIN16_INIT);
   	PORTD = Conc(DIO_PIN31_INIT,DIO_PIN30_INIT,DIO_PIN29_INIT,DIO_PIN28_INIT,DIO_PIN27_INIT,DIO_PIN26_INIT,DIO_PIN25_INIT,DIO_PIN24_INIT);
	   
}

extern u8 DIO_WritePin(u8 PinNumber, u8 Value)
{ if (PinNumber>=0 && PinNumber<DIO_PIN_NUM)
    {	
			if(Value==1)
			{
				switch (PinNumber/DIO_PIN_PER_PORT)
				{
					case 0: PORTA |=(1<<PinNumber%DIO_PIN_PER_PORT);
					break;
					case 1: PORTB |=(1<<PinNumber%DIO_PIN_PER_PORT);
					break;
					case 2: PORTC |=(1<<PinNumber%DIO_PIN_PER_PORT);
					break;
					case 3: PORTD |=(1<<PinNumber%DIO_PIN_PER_PORT);
					break;
				}
			}
			
			else if(Value==0)
			{	
				switch (PinNumber/8)
				{
					case 0: PORTA &=~(1<<PinNumber%DIO_PIN_PER_PORT);
					break;
					case 1: PORTB &=~(1<<PinNumber%DIO_PIN_PER_PORT);
					break;
					case 2: PORTC &=~(1<<PinNumber%DIO_PIN_PER_PORT);
					break;
					case 3: PORTD &=~(1<<PinNumber%DIO_PIN_PER_PORT);
					break;
				}
				
			}
			

        return OK;
    }
    else
        return ERROR;

}
extern u8 DIO_ReadPin(u8 PinNumber, u8 *PtrValue)
{
    int PIN_Number[]={PINA,PINB,PINC,PIND};
	if (PinNumber>=0 && PinNumber<DIO_PIN_NUM)
    {

	*PtrValue= GET_BIT(PIN_Number[PinNumber/DIO_PIN_PER_PORT], PinNumber%DIO_PIN_PER_PORT);
	
        return OK;
    }
    else
        return ERROR;

}

//Using it : Intiate a variable read,  DIO_ReadPin(DIO_PIN11, &read);
