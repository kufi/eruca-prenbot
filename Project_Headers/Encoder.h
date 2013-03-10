/*
 * Encoder.h
 *
 *  Created on: Dec 20, 2012
 *      Author: 8460p
 */

#ifndef ENCODER_H_
#define ENCODER_H_
#include "Cpu.h"

#define UMPROSTEP 1

int iA;
int iB;
uint32_t tiksA0,tiksA1,tiksA2,tiksA3;
uint32_t tiksA_am;
uint32_t tiksB0,tiksB1,tiksB2,tiksB3;
uint32_t tiksB_am;
uint32_t oldticksA;
uint32_t oldticksB;
uint32_t stepsA;
uint32_t stepsB;
uint32_t tiks;

LDD_TDeviceData *MyFakeEncoderRefrenzTimerPtr;

void startEncoding(void);
void stopEncoding(void);
uint32_t calcDistAmm(void);
uint32_t calcDistBmm(void);
void initEncoders(void);
void resetStepsA(void);
void resetStepsB(void);
void calcAritmeticMidleA(int i);
void calcAritmeticMidleB(int i);

#endif /* ENCODER_H_ */
