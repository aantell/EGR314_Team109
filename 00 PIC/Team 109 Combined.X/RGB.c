#include "RGB.h"

void sendByte (unsigned char b) 
{
    if (b & 0b10000000) { send(1); } else { send(0); }
    if (b & 0b01000000) { send(1); } else { send(0); }
    if (b & 0b00100000) { send(1); } else { send(0); }
    if (b & 0b00010000) { send(1); } else { send(0); }
    if (b & 0b00001000) { send(1); } else { send(0); }
    if (b & 0b00000100) { send(1); } else { send(0); }
    if (b & 0b00000010) { send(1); } else { send(0); }
    if (b & 0b00000001) { send(1); } else { send(0); }
}

// send red, green, and blue values in WS2812 protocol
void sendRGB (unsigned char r, unsigned char g, unsigned char b) 
{
    sendByte(g);
    sendByte(r);
    sendByte(b);
}

// Send Red
void red(void)
{
    sendByte(0);
    sendByte(255);
    sendByte(0);
}

// Send Blue
void blue(void)
{
    sendByte(0);
    sendByte(0);
    sendByte(255);
}

// Send Green
void green(void)
{
    sendByte(255);
    sendByte(0);
    sendByte(0);
}

// Send Yellow
void yellow(void)
{
    sendByte(255);
    sendByte(255);
    sendByte(0);
}

// Send White
void white(void)
{
    sendByte(255);
    sendByte(255);
    sendByte(255);
}

void clear(void)
{
    sendRGB(0,0,0);
}

// Clears the string by sending colour values of 0 to all LEDS
void clearStrip(void)
{ 
    for(int i=0; i < numLEDs; i++)
        sendRGB(0,0,0);
}