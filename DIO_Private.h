#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_


/************* Registers Definition ************/

#define PORTA *((volatile unsigned char*) (0x3B))
#define PORTB *((volatile unsigned char*) (0x38))
#define PORTC *((volatile unsigned char*) (0x35))
#define PORTD *((volatile unsigned char*) (0x32))

#define PINA *((volatile unsigned char*) (0x39))
#define PINB *((volatile unsigned char*) (0x36))
#define PINC *((volatile unsigned char*) (0x33))
#define PIND *((volatile unsigned char*) (0x30))

#define DDRA *((volatile unsigned char*) (0x3A))
#define DDRB *((volatile unsigned char*) (0x37))
#define DDRC *((volatile unsigned char*) (0x34))
#define DDRD *((volatile unsigned char*) (0x31))

/************* PINS Definition ************/

#define DIO_PIN0    0
#define DIO_PIN1    1
#define DIO_PIN2    2
#define DIO_PIN3    3
#define DIO_PIN4    4
#define DIO_PIN5    5
#define DIO_PIN6    6
#define DIO_PIN7    7
#define DIO_PIN8    8
#define DIO_PIN9    9
#define DIO_PIN10   10
#define DIO_PIN11   11
#define DIO_PIN12   12
#define DIO_PIN13   13
#define DIO_PIN14   14
#define DIO_PIN15   15
#define DIO_PIN16   16
#define DIO_PIN17   17
#define DIO_PIN18   18
#define DIO_PIN19   19
#define DIO_PIN20   20
#define DIO_PIN21   21
#define DIO_PIN22   22
#define DIO_PIN23   23
#define DIO_PIN24   24
#define DIO_PIN25   25
#define DIO_PIN26   26
#define DIO_PIN27   27
#define DIO_PIN28   28
#define DIO_PIN29   29
#define DIO_PIN30   30
#define DIO_PIN31   31
#define DIO_PIN32   32

/************* Concatanation ************/
#define Conc(A7,A6,A5,A4,A3,A2,A1,A0)                             Conc_Helper(A7,A6,A5,A4,A3,A2,A1,A0)
#define Conc_Helper(X7,X6,X5,X4,X3,X2,X1,X0)                      0b##X7##X6##X5##X4##X3##X2##X1##X0

/************States Defintion**************/

#define HIGH			1
#define LOW				0

#define OK				1
#define ERROR			0

#define INPUT			0
#define OUTPUT			1


#endif // _DIO_PRIVATE_H_
