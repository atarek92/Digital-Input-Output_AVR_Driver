#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#include "DIO_Private.h"
#define DIO_PORT_NUM		4
#define DIO_PIN_NUM			32
#define DIO_PIN_PER_PORT    8

extern void DIO_Init(void);
extern u8 DIO_WritePin(u8 PinNumber, u8 Value);
extern u8 DIO_ReadPin(u8 PinNumber, u8 *PtrValue);





#endif // _DIO_INTERFACE_H_
