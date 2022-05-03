/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F27Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set Strip aliases
#define Strip_TRIS                 TRISAbits.TRISA0
#define Strip_LAT                  LATAbits.LATA0
#define Strip_PORT                 PORTAbits.RA0
#define Strip_WPU                  WPUAbits.WPUA0
#define Strip_OD                   ODCONAbits.ODCA0
#define Strip_ANS                  ANSELAbits.ANSELA0
#define Strip_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define Strip_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define Strip_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define Strip_GetValue()           PORTAbits.RA0
#define Strip_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define Strip_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define Strip_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define Strip_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define Strip_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define Strip_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define Strip_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define Strip_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set DEBUG_LED aliases
#define DEBUG_LED_TRIS                 TRISAbits.TRISA3
#define DEBUG_LED_LAT                  LATAbits.LATA3
#define DEBUG_LED_PORT                 PORTAbits.RA3
#define DEBUG_LED_WPU                  WPUAbits.WPUA3
#define DEBUG_LED_OD                   ODCONAbits.ODCA3
#define DEBUG_LED_ANS                  ANSELAbits.ANSELA3
#define DEBUG_LED_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define DEBUG_LED_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define DEBUG_LED_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define DEBUG_LED_GetValue()           PORTAbits.RA3
#define DEBUG_LED_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define DEBUG_LED_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define DEBUG_LED_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define DEBUG_LED_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define DEBUG_LED_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define DEBUG_LED_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define DEBUG_LED_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define DEBUG_LED_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSELA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set analog1 aliases
#define analog1_TRIS                 TRISBbits.TRISB0
#define analog1_LAT                  LATBbits.LATB0
#define analog1_PORT                 PORTBbits.RB0
#define analog1_WPU                  WPUBbits.WPUB0
#define analog1_OD                   ODCONBbits.ODCB0
#define analog1_ANS                  ANSELBbits.ANSELB0
#define analog1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define analog1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define analog1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define analog1_GetValue()           PORTBbits.RB0
#define analog1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define analog1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define analog1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define analog1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define analog1_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define analog1_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define analog1_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define analog1_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set CLK aliases
#define CLK_TRIS                 TRISBbits.TRISB1
#define CLK_LAT                  LATBbits.LATB1
#define CLK_PORT                 PORTBbits.RB1
#define CLK_WPU                  WPUBbits.WPUB1
#define CLK_OD                   ODCONBbits.ODCB1
#define CLK_ANS                  ANSELBbits.ANSELB1
#define CLK_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define CLK_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define CLK_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define CLK_GetValue()           PORTBbits.RB1
#define CLK_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define CLK_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define CLK_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define CLK_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define CLK_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define CLK_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define CLK_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define CLK_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set LATCH aliases
#define LATCH_TRIS                 TRISBbits.TRISB2
#define LATCH_LAT                  LATBbits.LATB2
#define LATCH_PORT                 PORTBbits.RB2
#define LATCH_WPU                  WPUBbits.WPUB2
#define LATCH_OD                   ODCONBbits.ODCB2
#define LATCH_ANS                  ANSELBbits.ANSELB2
#define LATCH_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define LATCH_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define LATCH_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define LATCH_GetValue()           PORTBbits.RB2
#define LATCH_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define LATCH_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define LATCH_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define LATCH_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define LATCH_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define LATCH_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define LATCH_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define LATCH_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set DATAIN aliases
#define DATAIN_TRIS                 TRISBbits.TRISB3
#define DATAIN_LAT                  LATBbits.LATB3
#define DATAIN_PORT                 PORTBbits.RB3
#define DATAIN_WPU                  WPUBbits.WPUB3
#define DATAIN_OD                   ODCONBbits.ODCB3
#define DATAIN_ANS                  ANSELBbits.ANSELB3
#define DATAIN_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define DATAIN_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define DATAIN_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define DATAIN_GetValue()           PORTBbits.RB3
#define DATAIN_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define DATAIN_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define DATAIN_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define DATAIN_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define DATAIN_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define DATAIN_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define DATAIN_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define DATAIN_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set MOTOR1 aliases
#define MOTOR1_TRIS                 TRISBbits.TRISB4
#define MOTOR1_LAT                  LATBbits.LATB4
#define MOTOR1_PORT                 PORTBbits.RB4
#define MOTOR1_WPU                  WPUBbits.WPUB4
#define MOTOR1_OD                   ODCONBbits.ODCB4
#define MOTOR1_ANS                  ANSELBbits.ANSELB4
#define MOTOR1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define MOTOR1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define MOTOR1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define MOTOR1_GetValue()           PORTBbits.RB4
#define MOTOR1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define MOTOR1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define MOTOR1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define MOTOR1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define MOTOR1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define MOTOR1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define MOTOR1_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define MOTOR1_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set MOTOR2 aliases
#define MOTOR2_TRIS                 TRISBbits.TRISB5
#define MOTOR2_LAT                  LATBbits.LATB5
#define MOTOR2_PORT                 PORTBbits.RB5
#define MOTOR2_WPU                  WPUBbits.WPUB5
#define MOTOR2_OD                   ODCONBbits.ODCB5
#define MOTOR2_ANS                  ANSELBbits.ANSELB5
#define MOTOR2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define MOTOR2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define MOTOR2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define MOTOR2_GetValue()           PORTBbits.RB5
#define MOTOR2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define MOTOR2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define MOTOR2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define MOTOR2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define MOTOR2_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define MOTOR2_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define MOTOR2_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define MOTOR2_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSELB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set IO_RC2 aliases
#define IO_RC2_TRIS                 TRISCbits.TRISC2
#define IO_RC2_LAT                  LATCbits.LATC2
#define IO_RC2_PORT                 PORTCbits.RC2
#define IO_RC2_WPU                  WPUCbits.WPUC2
#define IO_RC2_OD                   ODCONCbits.ODCC2
#define IO_RC2_ANS                  ANSELCbits.ANSELC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define IO_RC2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/