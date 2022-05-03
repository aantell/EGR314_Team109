#include "mcc_generated_files/mcc.h"


//********************************************************************************
// REQUIRES SYSTEM CLOCK TO BE SET TO HFINTOSC 48 MHz WITH A CLOCK DIVIDER OF 1
//********************************************************************************


// Sends data bits to LED strip
// normally high so start and end bits are set high
// b is the value of bit being sent
// number of ops is based on the clock speed and the instruction rate
// NOP is to delay for the correct time for WS2812 protocol
#define send(b) LATAbits.LATA0 = 1; NOP(); NOP(); NOP(); LATAbits.LATA0 = b; NOP(); NOP(); NOP(); NOP(); LATAbits.LATA0 = 0; NOP(); NOP(); NOP(); NOP();

int numLEDs = 60; // number of LEDS in the string



// takes an 8 bit number and masks through sending each bit to send
void sendByte (unsigned char b);

// send red, green, and blue values in WS2812 protocol
void sendRGB (unsigned char r, unsigned char g, unsigned char b);

// Send Red
void red(void);

// Send Blue
void blue(void);

// Send Green
void green(void);

// Send Yellow
void yellow(void);

// Send White
void white(void);

// Clears a single LED
void clear(void);

// Clears the string by sending colour values of 0 to all LEDS
void clearStrip(void);