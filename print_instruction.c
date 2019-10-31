// If you use C library functions add includes here.

#include "emu.h"
#include "ram.h"
#include "registers.h"

/*
 * print a MIPS instruction (no newline)
 * run reference implementation if unsure what to print
 */
///////////////////////////////////////////////////////
/// FUNCTION FOREWARNINGS                    //////////
///////////////////////////////////////////////////////
char *get_instruction(uint32_t instruction);

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


void print_instruction(uint32_t instruction) {
    
    char *check123 = get_instruction(instruction);
    printf("%s\n", check123); 
    
    //char *add = "add";
    //int b = (add == check123); //b = 1 if they match, 0 if they dont
    
}



////////////////////////////////////////////////////////////
// PUT YOUR FUNCTIONS HERE        //////////////////////////
////////////////////////////////////////////////////////////
char *get_instruction(uint32_t instruction){

    uint32_t intF = instruction >> 26;      // got first 6 bits moved to the front now
    //uint32_t intL = instruction & 63;        // got last 6 bits as 63 = 00000000000000000000000111111

    
        char *string1 = "didnt go through :(";
    
     
    if (intF != 0){
        if (intF == 1){ 
            string1 = "1 works cunt";
        }
        else if (intF == 2){
            string1 = "2 works cunt";
        }
        else if (intF == 3){
            string1 = "3 works cunt";
        }
    } 
    return string1;
}


