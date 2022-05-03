#include "mcc_generated_files/mcc.h"
#include "RGB.h"

uint8_t convertedValue = 0;
int shiftedval[8] = {0, 0, 0, 0, 0, 0, 0, 0};

uint8_t rx2Data;
uint8_t rx1Data; //variable

void ANALOG_ISR(){
    
}

void UART4_HW4_Receive_ISR(void) //initializing
{
    UART4_Receive_ISR();

    if (UART4_is_rx_ready()) //checking if receiver is ready to receive data
    {
        rx2Data = UART4_Read(); // reading and save in variable

        while (!UART3_is_tx_ready()); //checking if transmitter is ready to transmit data

        UART3_Write(rx2Data); //printing transmitted data
        while (!UART3_is_tx_done());

        if (rx1Data == 49) {
            DEBUG_LED_SetHigh(); //disable for 2
            //PORTBbits.RB4 = 0;
            //PORTBbits.RB5 = 1;
            //MOTOR1_SetHigh();
            //MOTOR2_SetLow();
        } else if (rx1Data == 50) {
            DEBUG_LED_SetLow(); //disable for 2
            //PORTBbits.RB4 = 1;
            //PORTBbits.RB5 = 0;
            //MOTOR1_SetHigh();
            //MOTOR2_SetLow();
        }

        //LED_0_Toggle();  //disable for 2
    }
    //LED_0_Toggle();  //disable for 2
}

void UART3_HW4_Receive_ISR(void) //initializing
{
    UART3_Receive_ISR();

    if (UART3_is_rx_ready()) //checking if receiver is ready to receive data
    {
        rx1Data = UART3_Read(); // reading and save in variable

        while (!UART4_is_tx_ready()); //checking if transmitter is ready to transmit data

        UART4_Write(rx1Data); //printing transmitted data
        while (!UART4_is_tx_done());

        if (rx1Data == 49) {
            DEBUG_LED_SetHigh(); //disable for 2
            //PORTBbits.RB4 = 0;
            //PORTBbits.RB5 = 1;
            //MOTOR1_SetHigh();
            //MOTOR2_SetLow();
        } else if (rx1Data == 50) {
            DEBUG_LED_SetLow(); //disable for 2
            //PORTBbits.RB4 = 1;
            //PORTBbits.RB5 = 0;
            //MOTOR1_SetHigh();
            //MOTOR2_SetLow();
        }

    }
    //LED_0_Toggle();  
}

void main(void) {
    // Initialize the device
    SYSTEM_Initialize();

    UART4_SetRxInterruptHandler(UART4_HW4_Receive_ISR); //initailize 
    UART3_SetRxInterruptHandler(UART3_HW4_Receive_ISR);

    // Initialize ADC for Moisture sensor
    ADCC_Initialize();
    ADCC_DisableContinuousConversion();

    // Declare and initialize variables for Elizabeth's LED subsystem
    int counter = 0;
    int LEDS = 60; // Number of LEDS that will be turned on

    //DEBUG_LED_SetHigh();

    // Declare and initialize variables for Chloe's subsystem

    INTERRUPT_GlobalInterruptEnable();
    
    ADCC(ANALOG_ISR);

    //INTERRUPT_PeripheralInterruptEnable();

    int ii = 7;
    float value = 0;

    // Infinite loop
    while (1) {
        //ADCC_StartConversion(analog1);
        convertedValue = ADCC_GetSingleConversion(analog1);
        
        //value=ii/10;
        //printf("%d\r", ii);

        if (convertedValue < 90) {
            for (int i = 0; i < LEDS; i++) {
                red();
            }
        } 
        
        // If moisture high then proceed with everything else
        else {
            //DEBUG_LED_SetHigh();
            //__delay_ms(500);
            //DEBUG_LED_SetLow();
            // Set shift register PL so it loads
            LATCH_SetLow();
            __delay_us(1);
            LATCH_SetHigh();

            for (int i = 7; i >= 0; i--) {
                CLK_SetLow();
                __delay_us(1);
                shiftedval[i] = DATAIN_GetValue();
                if (shiftedval[2] == 1) {
                    //DEBUG_LED_SetHigh();
                }
                else {
                    //DEBUG_LED_SetLow();
                }
                CLK_SetHigh();
                __delay_us(1);
            }

        }
        if (shiftedval[1] == 0) {
            for (int i = 0; i < LEDS; i++) {
                red();
            }
        } else if (shiftedval[2] == 0) {
            for (int i = 0; i < LEDS; i++) {
                green();
            }
        } else if (shiftedval[3] == 0) {
            for (int i = 0; i < LEDS; i++) {
                blue();
            }
        }


        /*
            switch(counter)
            {
                case 0: // Sets LEDS RED
                    for(int i = 0; i < LEDS; i++)
                        red();
                    break;
                case 1: // Sets LEDS GREEN
                    for(int i = 0; i < LEDS; i++)
                        green();
                    break;
                case 2: // Sets LEDS BLUE
                    for(int i = 0; i < LEDS; i++)
                        blue();
                    break;
            }
         */

        // if the entire strip is connected this sets the rest of the lights off
        for (int i = 0; i < (numLEDs - LEDS); i++)
            clear();

        counter++;

        __delay_ms(500);
        
        printf("%d\r", convertedValue);
        
        __delay_ms(500);
    }
}
