#include <stdio.h>
#include <stdlib.h>

unsigned char Var_01;
unsigned char Var_02;
unsigned char Var_03;
unsigned char Var_04;
unsigned char Var_05;
unsigned char Var_06;
unsigned char Var_07;
unsigned char Var_08;
unsigned char Var_09;
unsigned char Var_10;

void set_regs () {
    //  Modify the value of global variable Var_01, setting
    //  bit 0, and leaving all
    //  other bits unaltered.

    // INSERT CODE HERE.
    Var_01 |= (1<<0);
    //  Modify the value of global variable Var_02, setting
    //  bit 6, and leaving all
    //  other bits unaltered.

    // INSERT CODE HERE.
    Var_02 |= (1<<6);
    //  Modify the value of global variable Var_03, setting
    //  bits 0, 2, and leaving all
    //  other bits unaltered.

    // INSERT CODE HERE.
    Var_02 |= (1<<0)|(1<<2);
    //  Modify the value of global variable Var_04, setting
    //  bits 3, 5, and leaving all
    //  other bits unaltered.

    // INSERT CODE HERE.
    Var_03 |= (1<<3)|(1<<5);
    //  Modify the value of global variable Var_05, setting
    //  bits 0, 2, 3, and leaving all
    //  other bits unaltered.

    // INSERT CODE HERE.
    Var_03 |= (1<<3)|(1<<5);
    //  Modify the value of global variable Var_06, setting
    //  bits 2, 5, 7, and leaving all
    //  other bits unaltered.

    // INSERT CODE HERE.

    //  Modify the value of global variable Var_07, setting
    //  bits 0, 2, 5, 6, and leaving all
    //  other bits unaltered.

    // INSERT CODE HERE.

    //  Modify the value of global variable Var_08, setting
    //  bits 1, 2, 3, 6, and leaving all
    //  other bits unaltered.

    // INSERT CODE HERE.

    //  Modify the value of global variable Var_09, setting
    //  bits 0, 1, 2, 5, 6, and leaving all
    //  other bits unaltered.

    // INSERT CODE HERE.

    //  Modify the value of global variable Var_10, setting
    //  bits 1, 3, 5, 6, 7, and leaving all
    //  other bits unaltered.

    // INSERT CODE HERE.


}


void print_bits( const char * label, unsigned char val){
    printf("%s bits = {", label);

    int deja = 0;

    for (int i = 0; i <= 7; i++) {
        if ( (val & (1 << i)) ) {
            printf("%s%d", (deja ? ", " : ""), i);
            deja = 1;
        }
    }

    printf("}\n");
}

int main(int argc, char * argv[]) {
    unsigned char init_val = 0;

    if (argc > 1) init_val = atoi(argv[1]) & 255;

    Var_01 = init_val;
    Var_02 = init_val;
    Var_03 = init_val;
    Var_04 = init_val;
    Var_05 = init_val;
    Var_06 = init_val;
    Var_07 = init_val;
    Var_08 = init_val;
    Var_09 = init_val;
    Var_10 = init_val;


    set_regs();

    print_bits("Initial", init_val);
    print_bits("Var_01", Var_01);
    print_bits("Var_02", Var_02);
    print_bits("Var_03", Var_03);
    print_bits("Var_04", Var_04);
    print_bits("Var_05", Var_05);
    print_bits("Var_06", Var_06);
    print_bits("Var_07", Var_07);
    print_bits("Var_08", Var_08);
    print_bits("Var_09", Var_09);
    print_bits("Var_10", Var_10);


    return 0;
}
