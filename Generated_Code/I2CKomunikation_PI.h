/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : I2CKomunikation_PI.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : I2C_LDD
**     Version     : Component 01.011, Driver 01.06, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-03-14, 12:03, # CodeGen: 83
**     Abstract    :
**          This component encapsulates the internal I2C communication
**          interface. The implementation of the interface is based
**          on the Philips I2C-bus specification version 2.0.
**          Interface features:
**          MASTER mode
**            - Multi master communication
**            - The combined format of communication possible
**              (see SendStop parameter in MasterSend/ReceiveBlock method)
**            - 7-bit slave addressing (10-bit addressing can be made as well)
**            - Acknowledge polling provided
**            - No wait state initiated when a slave device holds the SCL line low
**            - Holding of the SCL line low by slave device recognized as 'not available bus'
**            - Invalid start/stop condition detection provided
**          SLAVE mode
**            - 7-bit slave addressing
**            - General call address detection provided
**     Settings    :
**          Component name                                 : I2CKomunikation_PI
**          I2C channel                                    : I2C0
**          Interrupt service                              : Enabled
**            Interrupt                                    : INT_I2C0
**            Interrupt priority                           : medium priority
**          Settings                                       : 
**            Mode selection                               : SLAVE
**            MASTER mode                                  : Disabled
**            SLAVE mode                                   : Enabled
**              Address mode                               : 7-bit addressing
**              Slave address                              : 9
**              General call address                       : Disabled
**              Empty character                            : 0
**              Second slave address                       : Disabled
**              Alert response address                     : Disabled
**              Slave baud rate control                    : Disabled
**              Wake-up                                    : Disabled
**            Pins                                         : 
**              SDA pin                                    : 
**                SDA pin                                  : CMP0_IN3/PTC9/I2C0_SDA/TPM0_CH5
**                SDA pin signal                           : 
**              SCL pin                                    : 
**                SCL pin                                  : CMP0_IN2/PTC8/I2C0_SCL/TPM0_CH4
**                SCL pin signal                           : 
**              High drive select                          : Disabled
**              Input Glitch filter                        : 0
**            Internal frequency (multiplier factor)       : 20.97152 MHz
**            Bits 0-2 of Frequency divider register       : 001
**            Bits 3-5 of Frequency divider register       : 100
**            SCL frequency                                : 109.227 kHz
**            SDA Hold                                     : 0.811 us
**            SCL start Hold                               : 4.482 us
**            SCL stop Hold                                : 4.625 us
**            Control acknowledge bit                      : Enabled
**              Delay loop cycle number                    : 200
**            Low timeout                                  : Disabled
**          Initialization                                 : 
**            Enabled in init code                         : no
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnMasterBlockSent                          : Disabled
**              OnMasterBlockReceived                      : Disabled
**              OnMasterByteReceived                       : Disabled
**              OnSlaveBlockSent                           : Enabled
**              OnSlaveBlockReceived                       : Enabled
**              OnSlaveByteReceived                        : Disabled
**              OnSlaveRxRequest                           : Disabled
**              OnSlaveTxRequest                           : Disabled
**              OnSlaveGeneralCallAddr                     : Disabled
**              OnSlaveSmBusCallAddr                       : Disabled
**              OnSlaveSmBusAlertResponse                  : Disabled
**              OnError                                    : Enabled
**              OnBusStopDetected                          : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**     Contents    :
**         Init              - LDD_TDeviceData* I2CKomunikation_PI_Init(LDD_TUserData *UserDataPtr);
**         Deinit            - void I2CKomunikation_PI_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable            - LDD_TError I2CKomunikation_PI_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable           - LDD_TError I2CKomunikation_PI_Disable(LDD_TDeviceData *DeviceDataPtr);
**         SlaveSendBlock    - LDD_TError I2CKomunikation_PI_SlaveSendBlock(LDD_TDeviceData *DeviceDataPtr,...
**         SlaveReceiveBlock - LDD_TError I2CKomunikation_PI_SlaveReceiveBlock(LDD_TDeviceData...
**         SendAcknowledge   - LDD_TError I2CKomunikation_PI_SendAcknowledge(LDD_TDeviceData *DeviceDataPtr,...
**         GetError          - LDD_TError I2CKomunikation_PI_GetError(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __I2CKomunikation_PI_H
#define __I2CKomunikation_PI_H

/* MODULE I2CKomunikation_PI. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited components */
#include "PE_LDD.h"

#include "Cpu.h"

#define I2CKomunikation_PI_EMPTY_CHAR 0x00U /* Empty character */
#define I2CKomunikation_PI_SLAVE_ADDRESS 0x09U /* Slave address value */

/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define I2CKomunikation_PI_PRPH_BASE_ADDRESS  0x40066000U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define I2CKomunikation_PI_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_I2CKomunikation_PI_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define I2CKomunikation_PI_Init_METHOD_ENABLED
#define I2CKomunikation_PI_Deinit_METHOD_ENABLED
#define I2CKomunikation_PI_Enable_METHOD_ENABLED
#define I2CKomunikation_PI_Disable_METHOD_ENABLED
#define I2CKomunikation_PI_SlaveSendBlock_METHOD_ENABLED
#define I2CKomunikation_PI_SlaveReceiveBlock_METHOD_ENABLED
#define I2CKomunikation_PI_SendAcknowledge_METHOD_ENABLED
#define I2CKomunikation_PI_GetError_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define I2CKomunikation_PI_OnSlaveBlockSent_EVENT_ENABLED
#define I2CKomunikation_PI_OnSlaveBlockReceived_EVENT_ENABLED
#define I2CKomunikation_PI_OnError_EVENT_ENABLED



LDD_TDeviceData* I2CKomunikation_PI_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  I2CKomunikation_PI_Init (component I2C_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Pointer to the device data structure. 
** ===================================================================
*/

void I2CKomunikation_PI_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  I2CKomunikation_PI_Deinit (component I2C_LDD)
**
**     Description :
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/

LDD_TError I2CKomunikation_PI_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  I2CKomunikation_PI_Enable (component I2C_LDD)
**
**     Description :
**         Enables I2C component. Events may be generated
**         ("DisableEvent"/"EnableEvent").
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError I2CKomunikation_PI_Disable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  I2CKomunikation_PI_Disable (component I2C_LDD)
**
**     Description :
**         Disables I2C component. No events will be generated.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError I2CKomunikation_PI_SlaveSendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, LDD_I2C_TSize Size);
/*
** ===================================================================
**     Method      :  I2CKomunikation_PI_SlaveSendBlock (component I2C_LDD)
**
**     Description :
**         This method writes a block of characters to the I2C bus
**         after the master starts the communication. If no character
**         is ready for a transmission (user's output slave buffer is
**         empty or method SlaveSendBlock is not call), the "Empty
**         character" will be sent (see "Empty character" property). In
**         SLAVE mode the data are not copied to an internal buffer and
**         remains in the original location. Therefore the content of
**         the buffer should not be changed until the transmission is
**         complete. If the method returns ERR_OK, it doesn't mean that
**         transmission was successful. The state of transmission is
**         detectable by means of events (OnSlaveBlockSent or OnError).
**         This method is available only for the SLAVE or MASTER -
**         SLAVE mode.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BufferPtr       - Pointer to the block of data
**                           to send.
**         Size            - Size of the data block.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_BUSY - The I2C device is busy
** ===================================================================
*/

LDD_TError I2CKomunikation_PI_SlaveReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, LDD_I2C_TSize Size);
/*
** ===================================================================
**     Method      :  I2CKomunikation_PI_SlaveReceiveBlock (component I2C_LDD)
**
**     Description :
**         This method receives a block of characters of the I2C bus
**         after the master starts the communication. In SLAVE mode the
**         data are not copied to an internal buffer and remains in the
**         original location. Therefore the content of the buffer
**         should not be changed until the transmission is complete. If
**         the method returns ERR_OK, it doesn't mean that transmission
**         was successful. The state of transmission is detectable by
**         means of events (OnSlaveBlockReceived or OnError). State
**         LDD_I2C_SLAVE_TX_UNDERRUN of method GetError is return, when
**         no character is ready for a reception  (user's input slave
**         buffer is empty). This method is available only for the
**         SLAVE or MASTER - SLAVE mode.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BufferPtr       - Pointer to A buffer where
**                           received characters will be stored.
**         Size            - The size of the block.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_BUSY - The I2C device is busy
** ===================================================================
*/

LDD_TError I2CKomunikation_PI_SendAcknowledge(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TAckType AckType);
/*
** ===================================================================
**     Method      :  I2CKomunikation_PI_SendAcknowledge (component I2C_LDD)
**
**     Description :
**         This method send acknowledge/not acknowledge for current
**         receiving byte. This method is available only if control
**         acknowledge bit is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         AckType         - Specify type of receiving byte
**                           answer.
**                           LDD_I2C_ACK_BYTE - The values of
**                           acknowledge bit correspond to successful
**                           byte receiving (receiver send ACK bit value
**                           automatically according the I2C
**                           specification).
**                           LDD_I2C_NACK_BYTE - The values of
**                           acknowledge bit correspond to not
**                           successful byte receiving (receiver send
**                           NACK bit value and terminate reception).
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  The device is disabled.
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           ERR_PARAM_MODE -  Invalid acknowledge type
**                           answer.
** ===================================================================
*/

LDD_TError I2CKomunikation_PI_GetError(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TErrorMask *ErrorMaskPtr);
/*
** ===================================================================
**     Method      :  I2CKomunikation_PI_GetError (component I2C_LDD)
**
**     Description :
**         Returns value of error mask, e.g. LDD_I2C_ARBIT_LOST.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * ErrorMaskPtr    - Pointer to a variable
**                           where errors value mask will be stored.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
** ===================================================================
*/

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(I2CKomunikation_PI_Interrupt);
/*
** ===================================================================
**     Method      :  I2CKomunikation_PI_Interrupt (component I2C_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END I2CKomunikation_PI. */

#endif
/* ifndef __I2CKomunikation_PI_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
