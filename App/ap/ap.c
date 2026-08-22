#include "ap.h"

static void ledUpdata();

void apInit(){
    cliOpen(_DEF_UART1, 115200);
    cliLogo();
}

void apMain(){
    while(1)
    {
        ledUpdata();
        cliMain();
    }   
}
void ledUpdata(){
    static uint32_t pre_time = 0;
    
    if (millis()-pre_time >= 500)
    {
       pre_time = millis();
       ledToggle(_DEF_LED1);
    }
}

void cliLoopIdle(){
    ledUpdata();
}