/*
 * I2C.c
 *
 *  Created on: Mar 13, 2013
 *      Author: Admin
 */

#include "Raspberry_I2C.h"
#include "I2CKomunikation_PI.h"
#include "PE_Types.h"
#include "cstdlib"

typedef struct Raspberry_
{
	int received;
	void (*functionPtr)();
} Raspberry, *RaspberryPtr;


typedef struct {
  uint8_t SerFlag;                     /* Flags for serial communication */
                                       /* Bits: 0 - Running int from TX */
  bool EnUser;                         /* Enable/Disable device */
  LDD_I2C_TAckType AckType;            /* Specify received byte acknowledge */
  LDD_I2C_TErrorMask ErrorMask;        /* Variable for errors mask value */
  LDD_I2C_TSize InpLenS;               /* The counter of input bufer's content */
  LDD_I2C_TSize InpLenSReq;            /* Length of input bufer's content */
  uint8_t *InpPtrS;                    /* Pointer to input buffer for Slave mode */
  LDD_I2C_TSize OutLenS;               /* The counter of output bufer's content */
  LDD_I2C_TSize OutLenSReq;            /* Length of output bufer's content */
  uint8_t *OutPtrS;                    /* Pointer to output buffer for Slave mode */
  LDD_TUserData *UserData;             /* RTOS device data structure */
} I2CKomunikation_PI_TDeviceData;

typedef I2CKomunikation_PI_TDeviceData *I2CKomunikation_PI_TDeviceDataPtr; /* Pointer to the device data structure. */

I2CKomunikation_PI_TDeviceDataPtr I2cSlavePtr;
byte *buffer;
RaspberryPtr userDataPtr;

void initRaspberryI2C()
{
	buffer = (byte *)malloc(sizeof(byte) * 2);
	//userDataPtr->functionPtr = receiveBlock;
	
	I2cSlavePtr = I2CKomunikation_PI_Init(&userDataPtr);
	
	receiveBlock();
}

void receiveBlock()
{
	I2CKomunikation_PI_SlaveReceiveBlock(I2cSlavePtr, buffer, 2);
}
/*
void blockReceived()
{
	error = I2cSlavePtr->ErrorMask;
	if(error == 0)
	{
		char high = *buffer;
		char low = *(buffer + 1);
		userDataPtr->received = 0;
	}
	userDataPtr->received = 0;
	
	receiveBlock();
}
*/
