/** ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-03, 21:43, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "Encoder.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "US.h"
#include "Encoder.h"
#include "PID.h"
#include "Motor.h"
#include "motor_HR.h"
#include "EasyRider.h"
#include "Raspberry_I2C.h"
/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
**     Description :
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the <NMI
**         interrrupt> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/




void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  EncoderRefrenztimer_OnCounterRestart (module Events)
**
**     Component   :  EncoderRefrenztimer [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void EncoderRefrenztimer_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
		
}

/*
** ===================================================================
**     Event       :  EncoderMotorA_OnInterrupt (module Events)
**
**     Component   :  EncoderMotorA [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void EncoderMotorA_OnInterrupt(void)
{
	if(EncoderMotorA_GetVal()){
	tiks = EncoderRefrenztimer_GetCounterValue(MyFakeEncoderRefrenzTimerPtr);
	switch(iA)
	 {
	    case 0:
	    	tiksA0 = tiks - oldticksA;
	    	iA++;
	    break;

	    case 1:
	    	tiksA1 = tiks - oldticksA;
	    	iA++;
	    break;
	    case 2:
	    	tiksA2 = tiks - oldticksA;
	    	iA++;
	    break;
	    case 3:
	    	tiksA3 = tiks - oldticksA;
	    	iA=0;
	    break;
	    default:
	    	iA=0;
	 }
	
	oldticksA = tiks;
	}
	stepsA++;
}

/*
** ===================================================================
**     Event       :  I2CKomunikation_PI_OnSlaveBlockSent (module Events)
**
**     Component   :  I2CKomunikation_PI [I2C_LDD]
**     Description :
**         This event is called when I2C in slave mode finishes the
**         transmission of the data successfully. This event is not
**         available for the MASTER mode and if SlaveSendBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2CKomunikation_PI_OnSlaveBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  I2CKomunikation_PI_OnSlaveBlockReceived (module Events)
**
**     Component   :  I2CKomunikation_PI [I2C_LDD]
**     Description :
**         This event is called when I2C in slave mode finishes the
**         reception of the data successfully. This event is not
**         available for the MASTER mode and if SlaveReceiveBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2CKomunikation_PI_OnSlaveBlockReceived(LDD_TUserData *UserDataPtr)
{
	RaspberryPtr raspberryPtr = (RaspberryPtr)UserDataPtr;
	raspberryPtr->received = 1;
	(*raspberryPtr->functionPtr)();
}

/*
** ===================================================================
**     Event       :  I2CKomunikation_PI_OnError (module Events)
**
**     Component   :  I2CKomunikation_PI [I2C_LDD]
**     Description :
**         This event is called when an error (e.g. Arbitration lost)
**         occurs. The errors can be read with GetError method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2CKomunikation_PI_OnError(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  EncoderMotorB_OnInterrupt (module Events)
**
**     Component   :  EncoderMotorB [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void EncoderMotorB_OnInterrupt(void)
{
	if(EncoderMotorB_GetVal()){
	tiks = EncoderRefrenztimer_GetCounterValue(MyFakeEncoderRefrenzTimerPtr);
	switch(iB)
		 {
		    case 0:
		    	tiksB0 = tiks - oldticksB;
		    	iB++;
		    break;

		    case 1:
		    	tiksB1 = tiks - oldticksB;
		    	iB++;
		    break;
		    case 2:
		    	tiksB2 = tiks - oldticksB;
		    	iB++;
		    break;
		    case 3:
		    	tiksB3 = tiks - oldticksB;
		    	iB=0;
		    break;
		    default:
		    	iB=0;
		 }
	oldticksB = tiks;
	}
	stepsB++;
}

/*
** ===================================================================
**     Event       :  I2C_Kompass_OnMasterBlockSent (module Events)
**
**     Component   :  I2C_Kompass [I2C_LDD]
**     Description :
**         This event is called when I2C in master mode finishes the
**         transmission of the data successfully. This event is not
**         available for the SLAVE mode and if MasterSendBlock is
**         disabled. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2C_Kompass_OnMasterBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  I2C_Kompass_OnMasterBlockReceived (module Events)
**
**     Component   :  I2C_Kompass [I2C_LDD]
**     Description :
**         This event is called when I2C is in master mode and finishes
**         the reception of the data successfully. This event is not
**         available for the SLAVE mode and if MasterReceiveBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2C_Kompass_OnMasterBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  I2C_Kompass_OnError (module Events)
**
**     Component   :  I2C_Kompass [I2C_LDD]
**     Description :
**         This event is called when an error (e.g. Arbitration lost)
**         occurs. The errors can be read with GetError method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2C_Kompass_OnError(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  US_Rechts_HeckListener_OnInterrupt (module Events)
**
**     Component   :  US_Rechts_HeckListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void US_Rechts_HeckListener_OnInterrupt(void)
{
	atual_US_ticks = US_Referenztimer_GetCounterValue(MyFakeUSRefrenzTimerPtr);
	distanceRechtsHeck=(((atual_US_ticks-old_US_ticks)*1000)/DEVIDER)-DISTANCEOFFSET;
	US_Triger_SetBit(3);
	US_Rechts_HeckListener_Disable();
	bussy = 0;
}

/*
** ===================================================================
**     Event       :  US_Rechts_FrontListener_OnInterrupt (module Events)
**
**     Component   :  US_Rechts_FrontListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void US_Rechts_FrontListener_OnInterrupt(void)
{
	        atual_US_ticks = US_Referenztimer_GetCounterValue(MyFakeUSRefrenzTimerPtr);
			distanceRechtsFront=(((atual_US_ticks-old_US_ticks)*1000)/DEVIDER)-DISTANCEOFFSET;
			US_Triger_SetBit(2);
			US_Rechts_FrontListener_Disable();
			bussy = 0;
}

/*
** ===================================================================
**     Event       :  US_HeckListener_OnInterrupt (module Events)
**
**     Component   :  US_HeckListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void US_HeckListener_OnInterrupt(void)
{
	    atual_US_ticks = US_Referenztimer_GetCounterValue(MyFakeUSRefrenzTimerPtr);
		distanceHeck=(((atual_US_ticks-old_US_ticks)*1000)/DEVIDER)-DISTANCEOFFSET;
		US_Triger_SetBit(1);
		US_HeckListener_Disable();
		bussy = 0;
}

/*
** ===================================================================
**     Event       :  US_FrontListener_OnInterrupt (module Events)
**
**     Component   :  US_FrontListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void US_FrontListener_OnInterrupt(void)
{
	atual_US_ticks = US_Referenztimer_GetCounterValue(MyFakeUSRefrenzTimerPtr);
	distanceFront=(((atual_US_ticks-old_US_ticks)*1000)/DEVIDER)-DISTANCEOFFSET;
	US_Triger_SetBit(0);
	US_FrontListener_Disable();
	bussy = 0;
}

/*
** ===================================================================
**     Event       :  US_Referenztimer_OnCounterRestart (module Events)
**
**     Component   :  US_Referenztimer [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void US_Referenztimer_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
	if (freqwentUSactive){
	timepast++;
	if(timepast>=8){
		US_Triger_PutVal(0xF);
		bussy=0;
	}
	if((timepast>=APTASTRATE) && !bussy){
		switch (actifUScomponent) {
			case 1:
				mesureUSHeck();
				break;
			case 2:
				mesureUSRechts_Front();			
				break;
			case 3:
				mesureUSRechts_Heck();						
				break;
			case 4:
				mesureUSFront();									
				break;			
			default:
				break;
		}
		
		timepast=0;
	  }
   }
}

/*
** ===================================================================
**     Event       :  RegelungReferenztimer_OnCounterRestart (module Events)
**
**     Component   :  RegelungReferenztimer [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void RegelungReferenztimer_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
	int newIntensityEngineA;
	int newIntensityEngineB;
	
	PIDinterruptCounter++;
	
	if(PIDinterruptCounter>= regelverzoegerung){		
		if(PIDA_Activated){
      calcAritmeticMidleA(iA);
	  PIDA_Testresault =pidA(PIDA_Testsollwert, tiksA_am);
	  newIntensityEngineA = intensityEngineA_HR - (PIDA_Testresault);
	  if(newIntensityEngineA>=0){
		  setMotorA_HR(newIntensityEngineA);
	  }
	  if(newIntensityEngineA<0){
	  		  setMotorA_HR(0);
	  	  }
	 }
	if(PIDB_Activated){
		calcAritmeticMidleB(iB);
		PIDB_Testresault =pidB(PIDB_Testsollwert, tiksB_am);
		newIntensityEngineB = intensityEngineB_HR - (PIDB_Testresault);
		if(newIntensityEngineB>=0){
		setMotorB_HR(newIntensityEngineB);
		}
		if(newIntensityEngineB<0){
			 setMotorB_HR(0);
		}
	}
		
		 PIDinterruptCounter=0;
	}
	
	if((PIDinterruptCounter>=0)&& frekwentMotortestON){
		setMotorA((int)(distanceFront) -255);
		setMotorB((int)(distanceFront) -255);
	    PIDinterruptCounter=0;
	}

}

/*
** ===================================================================
**     Event       :  ResInterrupt_OnInterrupt (module Events)
**
**     Component   :  ResInterrupt [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ResInterrupt_OnInterrupt(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  EInt2_OnInterrupt (module Events)
**
**     Component   :  EInt2 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void EInt2_OnInterrupt(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  EInt1_OnInterrupt (module Events)
**
**     Component   :  EInt1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void EInt1_OnInterrupt(void)
{
  /* Write your code here ... */
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
