#include <mega8535.h>
#include <delay.h>

void main(void){
    DDRD = 0xFF;
    OCR1B = 1000;    
    OCR1A = 1000;
    
    while (1){
        PORTD.0 = 1;
        PORTD.1 = 0;
        PORTD.2 = 1;
        PORTD.3 = 0;
        delay_ms(500);
    }
}
