/*
Gabriel Coyote
TTU CS3375 Fall-2021
Project 1
*/

#include <stdio.h>
#include <stdlib.h>

extern int extract_fields(int instruction, int mode);


int main() {

    /* Given Instruction is ALWAYS R-type */
    /* 7[funct7], 5[rs2], 5[rs1], 3[funct3], 5[rd], 7[opcode] */

    int instruction = 0x015A04B3; 	/* Given Instruction A */
    //int instruction = 0x00578833; /* Given Instruction B */
    //int instruction = 0x001080B3; /* HW2   Instruction C */

    printf("Instruction: 0x%x \n", instruction);
    printf("opcode field: 0x%x \n", extract_fields(instruction, 0));
    printf("rd field: 0x%x \n", extract_fields(instruction, 1));
    printf("rs1 field: 0x%x \n", extract_fields(instruction, 2));

    exit(0);
}
