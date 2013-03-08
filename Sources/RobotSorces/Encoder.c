/*
 * Encoder.c
 *
 *  Created on: Feb 5, 2013
 *      Author: 8460p
 */
#include "Encoder.h"

void startEncoding(void){
	EncoderMotorA_Enable();
	EncoderMotorB_Enable();
}
void stopEncoding(void){
	EncoderMotorA_Disable();
	EncoderMotorB_Disable();
}
void initEncoders(void){
	tiksA_am=0xFFFF;
	tiksB_am=0xFFFF;
	resetStepsA();
	resetStepsB();
	startEncoding();
}

void calcAritmeticMidle(int i){
	switch(i)
		 {
		    case 0:
		    	tiksA_am = tiksA0;
		    break;

		    case 1:
		    	tiksA_am = (tiksA0+tiksA1)/(i+1);
		    break;
		    case 2:
		    	tiksA_am = (tiksA0+tiksA1+tiksA2)/(i+1);
		    break;
		    case 3:
		    	tiksA_am = (tiksA0+tiksA1+tiksA2+tiksA3)/(i+1);
		    break;
		 }
	if(tiksA_am==0){
		tiksA_am=0xFFFF;
	}
}

uint32_t calcDistAmm(void){
	return (stepsA*UMPROSTEP)/1000;
}
uint32_t calcDistBmm(void){
	return (stepsB*UMPROSTEP)/1000;
}
void resetStepsA(void){
	stepsA=0;
}
void resetStepsB(void){
	stepsB=0;
}

