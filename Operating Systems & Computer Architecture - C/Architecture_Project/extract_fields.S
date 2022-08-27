.section .text
.global extract_fields
.type extract_fields @function


extract_fields:

    /* a0 & a1 corresponds to the passed argurements */
    /* a0 := 32 bit instruction   &   a1 := mode */


    /* Temporary Register x5 for bne condition */
    /* x5 = 1                                  */
    addi x5, x0, 1



    /* If mode != 0; branch to CASE1    */
    /* Else continue with instructions  */
    /* Returning opcode field           */
    bne a1, x0, CASE1
    slli a0, a0, 25
    srli a0, a0, 25
    beq x0, x0, DONE


    /* If mode != 1; branch to CASE2 */
    /* Else do CASE2 instructions    */
    /* Returning rd field            */
CASE1:
    bne a1, x5, CASE2
    slli a0, a0, 20
    srli a0, a0, 27
    beq x0, x0, DONE


    /* No need to test this case since mode != 0 || 1 */
    /* So mode has to be = 2                          */
    /* Returning rs1 field                            */
CASE2:
    slli a0, a0, 12
    srli a0, a0, 27
    beq x0, x0, DONE

DONE:
    ret
