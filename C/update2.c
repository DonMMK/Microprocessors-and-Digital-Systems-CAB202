#include <stdio.h>
#include <stdlib.h>

void modify_bits_helper(
  unsigned char out_bit,
  unsigned char *out_reg,
  unsigned char input_mask,
  unsigned char input_reg

) {
  unsigned char output_mask = (1<<out_bit);

  if ( (input_reg & input_mask) == input_mask){
    (*out_reg) |=output_mask;
  }
  else{
    (*out_reg) &= ~output_mask;
  }
}

unsigned char input_reg_01,out_reg_01;
unsigned char input_reg_02,out_reg_02;
unsigned char input_reg_03,out_reg_03;
unsigned char input_reg_04,out_reg_04;
unsigned char input_reg_05,out_reg_05;
unsigned char input_reg_06,out_reg_06;
unsigned char input_reg_07,out_reg_07;
unsigned char input_reg_08,out_reg_08;
unsigned char input_reg_09,out_reg_09;
unsigned char input_reg_10,out_reg_10;

void modify_bits () {
    modify_bits_helper(0 , &out_reg_01, (1<<0), input_reg_01);
    modify_bits_helper(0 , &out_reg_02, (1<<4), input_reg_02);
    modify_bits_helper(4 , &out_reg_03, (1<<0)|(1<<6), input_reg_03);
    modify_bits_helper(0 , &out_reg_04, (1<<1)|(1<<5), input_reg_04);
    modify_bits_helper(5 , &out_reg_05, (1<<0)|(1<<3)|(1<<7), input_reg_05);
    modify_bits_helper(3 , &out_reg_06, (1<<2)|(1<<3)|(1<<4), input_reg_06);
    modify_bits_helper(5 , &out_reg_07, (1<<0)|(1<<3)|(1<<4)|(1<<7), input_reg_07);
    modify_bits_helper(5 , &out_reg_08, (1<<1)|(1<<4)|(1<<6)|(1<<7), input_reg_08);
    modify_bits_helper(6 , &out_reg_09, (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<5), input_reg_09);
    modify_bits_helper(1 , &out_reg_10, (1<<2)|(1<<3)|(1<<4)|(1<<6)|(1<<7), input_reg_10);
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
    unsigned char out_init = 0;

    if (argc > 1) init_val = atoi(argv[1]) & 255;
    if (argc > 2) out_init = atoi(argv[2]) & 255;

    input_reg_01 = init_val;
    out_reg_01 = out_init;

    input_reg_02 = init_val;
    out_reg_02 = out_init;

    input_reg_03 = init_val;
    out_reg_03 = out_init;

    input_reg_04 = init_val;
    out_reg_04 = out_init;

    input_reg_05 = init_val;
    out_reg_05 = out_init;

    input_reg_06 = init_val;
    out_reg_06 = out_init;

    input_reg_07 = init_val;
    out_reg_07 = out_init;

    input_reg_08 = init_val;
    out_reg_08 = out_init;

    input_reg_09 = init_val;
    out_reg_09 = out_init;

    input_reg_10 = init_val;
    out_reg_10 = out_init;

    modify_bits();

    print_bits("Input Value         ", init_val);
    print_bits("Initial output Value", out_init);

    printf("\nSearch for bit 0.\n");
    printf("Set or clear bit 0:\n");
    print_bits("out_reg_01", out_reg_01);

    printf("\nSearch for bit 4.\n");
    printf("Set or clear bit 0:\n");
    print_bits("out_reg_02", out_reg_02);

    printf("\nSearch for bits 0, 6.\n");
    printf("Set or clear bit 4:\n");
    print_bits("out_reg_03", out_reg_03);

    printf("\nSearch for bits 1, 5.\n");
    printf("Set or clear bit 0:\n");
    print_bits("out_reg_04", out_reg_04);

    printf("\nSearch for bits 0, 3, 7.\n");
    printf("Set or clear bit 5:\n");
    print_bits("out_reg_05", out_reg_05);

    printf("\nSearch for bits 2, 3, 4.\n");
    printf("Set or clear bit 3:\n");
    print_bits("out_reg_06", out_reg_06);

    printf("\nSearch for bits 0, 3, 4, 7.\n");
    printf("Set or clear bit 5:\n");
    print_bits("out_reg_07", out_reg_07);

    printf("\nSearch for bits 1, 4, 6, 7.\n");
    printf("Set or clear bit 5:\n");
    print_bits("out_reg_08", out_reg_08);

    printf("\nSearch for bits 0, 1, 2, 3, 5.\n");
    printf("Set or clear bit 6:\n");
    print_bits("out_reg_09", out_reg_09);

    printf("\nSearch for bits 2, 3, 4, 6, 7.\n");
    printf("Set or clear bit 1:\n");
    print_bits("out_reg_10", out_reg_10);

    return 0;
}
