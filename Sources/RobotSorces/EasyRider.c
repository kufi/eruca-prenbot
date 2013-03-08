/*
 * EasyRider.c
 *
 *  Created on: Feb 6, 2013
 *      Author: 8460p
 */
#include "US.h"
#include "Encoder.h"
#include "Motor.h"
#include "PID.h"
#include "EasyRider.h"


void startRiding(void){
	initUS();

	for(;;){
		
		
		
		
		
	}
}
void testCalibratePID_A(int Max,int pFacktor, int iFacktor, int dFacktor, int sollwert, int istwert){
	initPIDA(Max,pFacktor,iFacktor,dFacktor);
	initEncoders();
	regelverzoegerung=20;
	PIDA_Testsollwert= sollwert;
	PIDA_Testistwert= istwert;
	PIDA_Activated=1;
	
	
	
}
void testMotor(void){
	frekwentMotortestON =1;
	initUS();
	freqwentMesuring();
	initalizeMotros();
	
	
}
void testUS(void){
	initUS();
	freqwentMesuring();
}
