/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : EncoderMotorB.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : ExtInt
**     Version     : Component 02.104, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-02-28, 09:55, # CodeGen: 56
**     Abstract    :
**         This component "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The component uses one pin which generates interrupt on 
**         selected edge.
**     Settings    :
**         Interrupt name              : INT_PORTD
**         User handling procedure     : EncoderMotorB_OnInterrupt
**
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       76            |  PTD3/SPI0_MISO/UART2_TX/TPM0_CH3/SPI0_MOSI
**             ----------------------------------------------------
**
**         Port name                   : PTD
**
**         Bit number (in port)        : 3
**         Bit mask of the port        : 0x0008
**
**         Signal edge/level           : both
**         Priority                    : 2
**         Pull option                 : off
**         Initial state               : Enabled
**
**
**         Port data register          : GPIOD_PDOR [0x400FF0C0]
**         Port control register       : GPIOD_PDDR [0x400FF0D4]
**     Contents    :
**         Enable  - void EncoderMotorB_Enable(void);
**         Disable - void EncoderMotorB_Disable(void);
**         GetVal  - bool EncoderMotorB_GetVal(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE EncoderMotorB. */

#include "Events.h"
#include "EncoderMotorB.h"

/*
** ===================================================================
**     Method      :  EncoderMotorB_Enable (component ExtInt)
**
**     Description :
**         Enable the component - the external events are accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void EncoderMotorB_Enable(void)

**  This method is implemented as a macro. See EncoderMotorB.h file.  **
*/

/*
** ===================================================================
**     Method      :  EncoderMotorB_Disable (component ExtInt)
**
**     Description :
**         Disable the component - the external events are not accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void EncoderMotorB_Disable(void)

**  This method is implemented as a macro. See EncoderMotorB.h file.  **
*/

/*
** ===================================================================
**     Method      :  EncoderMotorB_GetVal (component ExtInt)
**
**     Description :
**         Returns the actual value of the input pin of the component.
**     Parameters  : None
**     Returns     :
**         ---             - Returned input value. Possible values:
**                           <false> - logical "0" (Low level) <true> -
**                           logical "1" (High level)
** ===================================================================
*/
/*
bool EncoderMotorB_GetVal(void)

**  This method is implemented as a macro. See EncoderMotorB.h file.  **
*/

/*
** ===================================================================
**     Method      :  EncoderMotorB_OnInterrupt (component ExtInt)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void ExtIntLdd2_OnInterrupt(LDD_TUserData *UserDataPtr)
{
  (void)UserDataPtr;                   /* Parameter is not used, suppress unused argument warning */
  EncoderMotorB_OnInterrupt();         /* Invoke OnInterrupt event */
}

/* END EncoderMotorB. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
