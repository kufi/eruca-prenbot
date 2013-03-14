/*
 * I2C.c
 *
 *  Created on: Mar 13, 2013
 *      Author: Admin
 */

#include "Raspberry_I2C.h"
#include "I2CKomunikation_PI.h"
#include "PE_Types.h"

typedef struct Raspberry_
{
	int received;
	void (*functionPtr)();
} Raspberry, *RaspberryPtr;

I2cSlave_TDeviceDataPtr I2cSlavePtr;
byte *buffer;
RaspberryPtr userDataPtr;
I2cSlave_TDeviceDataPtr I2cSlavePtr;

void init()
{
	buffer = (byte *)malloc(sizeof(byte) * 2);
	userDataPtr->functionPtr = receiveBlock;
	
	I2cSlavePtr = I2cSlave_Init(&userDataPtr);
}

void receiveBlock()
{
	I2cSlave_SlaveReceiveBlock(I2cSlavePtr, buffer, 2);
}

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

