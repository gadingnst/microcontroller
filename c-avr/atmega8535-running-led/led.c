#include <mega8535.h>
#include <delay.h>

const int LED[] = {
    0b00000000,0b00000001,0b00000011,0b00000111,
    0b00001111,0b00011111,0b00111111,0b01111111,
    0b11111111,0b11111110,0b11111100,0b11111000,
    0b11110000,0b11100000,0b11000000,0b10000000,
};

void runled(){
    int i;
    for(i=0; i<=15; i++){
        PORTC = LED[i];
        delay_ms(500);
    }
}

void main(void){
    DDRC = 0xFF;
    while (1){
        runled();
    }
}
