#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

//  Define a parameterless function called led_setup which returns nothing.
//
//  The function must enable digital output to a LED connected to the I/O pin 
//  labelled "13" on an Arduino Uno board.
//
//  The function must update only those bits required to enable digital output 
//  to that LED. The function must achieve the required side effect regardless 
//  of the prior state of all registers. In particular, **do not assume** that 
//  memory has previously been initialised with some value, zero or otherwise. 
 
void led_setup(void){
    DDRB |= (1<<5);
}

//  Define a parameterless function called turn_led_on which returns nothing.
//
//  The function must turn on a LED connected to the I/O pin labelled "13" 
//  on an Arduino Uno board.
//
//  The function must update only those bits required to turn on the LED. The 
//  function must achieve the required side effect regardless of the prior 
//  state of all registers. 

void turn_led_on(void){
    PORTB |= (1<<5); // PORTB = PORTB | 0b00001000
}

//  Define a parameterless function called light_off which returns nothing.
//
//  The function must turn off a LED connected to the I/O pin labelled "13" 
//  on an Arduino Uno board.
//
//  The function must update only those bits required to turn off the LED. The 
//  function must achieve the required side effect regardless of the prior 
//  state of all registers. 

void light_off(void){
    PORTB &= ~(1<<5); // PORTB = PORTB & 0b11110111
}

void simulate_other_setup();

int main(void) {
    simulate_other_setup();
    led_setup();

    while(1) {
        turn_led_on();
        _delay_ms(500);

        light_off();
        _delay_ms(500);
    } 
}

void simulate_other_setup(void) {
    //  Simulate situation where other important setup actions have been 
    //  performed prior to calling our functions.
    srand(854);
     DDRB = rand() & 255;
     PINB = rand() & 255;
    PORTB = rand() & 255;
     DDRC = rand() & 255;
     PINC = rand() & 255;
    PORTC = rand() & 255;
     DDRD = rand() & 255;
     PIND = rand() & 255;
    PORTD = rand() & 255;
}
