/** ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-03, 21:43, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "TU1.h"
#include "MotorA_PWM.h"
#include "PwmLdd1.h"
#include "MotorB_PWM.h"
#include "PwmLdd2.h"
#include "EncoderRefrenztimer.h"
#include "EncoderMotorA.h"
#include "ExtIntLdd1.h"
#include "EncoderMotorB.h"
#include "ExtIntLdd2.h"
#include "MotortreiberIN1_IN4.h"
#include "BitsIoLdd1.h"
#include "I2CKomunikation_PI.h"
#include "US_Triger.h"
#include "BitsIoLdd2.h"
#include "Lichtschranke.h"
#include "BitIoLdd1.h"
#include "LED1_4.h"
#include "BitsIoLdd3.h"
#include "IO_Res_Lueft.h"
#include "BitsIoLdd4.h"
#include "RegelungReferenztimer.h"
#include "US_Referenztimer.h"
#include "I2C_Kompass.h"
#include "US_FrontListener.h"
#include "ExtIntLdd4.h"
#include "US_HeckListener.h"
#include "ExtIntLdd5.h"
#include "US_Rechts_FrontListener.h"
#include "ExtIntLdd6.h"
#include "US_Rechts_HeckListener.h"
#include "ExtIntLdd7.h"
#include "ResInterrupt.h"
#include "ExtIntLdd3.h"
#include "ResIO.h"
#include "BitIoLdd2.h"
#include "EInt1.h"
#include "ExtIntLdd8.h"
#include "EInt2.h"
#include "ExtIntLdd9.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Encoder.h"
#include "EasyRider.h"
#include "US.h"
#include "Raspberry_I2C.h"

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  /* Write your code here */
  
  
  //testMotor();
  testCalibratePID_A(1000,1,0,0,1000,20);
  for(;;) {
	  
	  

	  }
	  

  
 
  

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
