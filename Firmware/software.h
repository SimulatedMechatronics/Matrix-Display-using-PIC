#include <18F4550.h>
#device adc=8

#FUSES NOMCLR                   //Master Clear pin used for I/O
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES EC                       //External clock with CLKOUT

#use delay(clock=20000000)

