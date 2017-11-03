#include "software.h"

#define TIME_BY_FRAME 1000
int MATRIX[16] = {255,255,255,255,255,255,255,255};
int LINE=0;
#int_TIMER0
void  TIMER0_isr(void) {
   //DRIVER MATRIX
   if(LINE==0){ //linha1
   output_d(0b00000001);
   output_b(MATRIX[0]);
   LINE=1;
   }
   else if(LINE==1){ //linha2
   output_d(0b00000010);
   output_b(MATRIX[1]);
   LINE=2;
   }
   else if(LINE==2){ //linha3
   output_d(0b00000100);
   output_b(MATRIX[2]);
   LINE=3;
   }
   else if(LINE==3){ //linha4
   output_d(0b00001000);
   output_b(MATRIX[3]);
   LINE=4;
   }
   else if(LINE==4){ //linha5
   output_d(0b00010000);
   output_b(MATRIX[4]);
   LINE=5;
   }
   else if(LINE==5){ //linha6
   output_d(0b00100000);
   output_b(MATRIX[5]);
   LINE=6;
   }
   else if(LINE==6){ //linha7
   output_d(0b01000000);
   output_b(MATRIX[6]);
   LINE=7;
   }
   else if(LINE==7){ //linha8
   output_d(0b10000000);
   output_b(MATRIX[7]);
   LINE=0;
   }
   //FIM DRIVER MATRIX
}

void showA(){
      MATRIX[0] = 0b11000011;
      MATRIX[1] = 0b10111101;
      MATRIX[2] = 0b01111110;
      MATRIX[3] = 0b00000000;
      MATRIX[4] = 0b01111110;
      MATRIX[5] = 0b01111110;
      MATRIX[6] = 0b01111110;
      MATRIX[7] = 0b01111110;
      delay_ms(TIME_BY_FRAME);
}
void showI(){
      MATRIX[0] = 0b00000000;
      MATRIX[1] = 0b11101111;
      MATRIX[2] = 0b11101111;
      MATRIX[3] = 0b11101111;
      MATRIX[4] = 0b11101111;
      MATRIX[5] = 0b11101111;
      MATRIX[6] = 0b11101111;
      MATRIX[7] = 0b00000000;
      delay_ms(TIME_BY_FRAME);
}
void showL(){
      MATRIX[0] = 0b01111111;
      MATRIX[1] = 0b01111111;
      MATRIX[2] = 0b01111111;
      MATRIX[3] = 0b01111111;
      MATRIX[4] = 0b01111111;
      MATRIX[5] = 0b01111111;
      MATRIX[6] = 0b01111111;
      MATRIX[7] = 0b00000000;
      delay_ms(TIME_BY_FRAME);
}
void showT(){
      MATRIX[0] = 0b00000000;
      MATRIX[1] = 0b11101111;
      MATRIX[2] = 0b11101111;
      MATRIX[3] = 0b11101111;
      MATRIX[4] = 0b11101111;
      MATRIX[5] = 0b11101111;
      MATRIX[6] = 0b11101111;
      MATRIX[7] = 0b11101111;
      delay_ms(TIME_BY_FRAME);
}
void showO(){
      MATRIX[0] = 0b11000011;
      MATRIX[1] = 0b10111101;
      MATRIX[2] = 0b01111110;
      MATRIX[3] = 0b01111110;
      MATRIX[4] = 0b01111110;
      MATRIX[5] = 0b01111110;
      MATRIX[6] = 0b10111101;
      MATRIX[7] = 0b11000011;
      delay_ms(TIME_BY_FRAME);
}
void showN(){
      MATRIX[0] = 0b01111110;
      MATRIX[1] = 0b00111110;
      MATRIX[2] = 0b01011110;
      MATRIX[3] = 0b01101110;
      MATRIX[4] = 0b01110110;
      MATRIX[5] = 0b01111010;
      MATRIX[6] = 0b01111100;
      MATRIX[7] = 0b01111110;
      delay_ms(TIME_BY_FRAME);
}

void main() {
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_128|RTCC_8_bit);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_timer_3(T3_DISABLED|T3_DIV_BY_1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   while(true) {
      showA();
      showI();
      showL();
      showT();
      showO();
      showN();
   }
}

