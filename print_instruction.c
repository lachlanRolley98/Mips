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
    uint32_t intL = instruction & 63;        // got last 6 bits as 63 = 00000000000000000000000111111
    uint32_t intM = (instruction >> 16) & 63;  //this the middle bits, not the middle left but middle all moved to left hand size

    
    char *string1 = "didnt go through :(";
    //since multiple instructions start with 000000, gota check the last 6 too differentiate them
    if (intF == 0){
        if (intL == 32){ 
            string1 = "add";
        }
        else if (intL == 34){
            string1 = "sub";
        }
        else if (intL == 36){
            string1 = "and";
        }
        else if (intL == 37){
            string1 = "or";
        }
        else if (intL == 38){
            string1 = "xor";
        }
        else if (intL == 4){
            string1 = "sllv";
        }
        else if (intL == 6){
            string1 = "srlv";
        }
        else if (intL == 42){
            string1 = "slt";
        }
        else if (intL == 0){
            string1 = "sll";
        }
        else if (intL == 2){
            string1 = "srl";
        }
        else if (intL == 8){
            string1 = "jr";
        }
        else if (intL == 12){
            string1 = "syscall";
        }
        

    }    
    //with this we are checking the front (F) of the bitpatterns for the instruction  
    if (intF != 0){
        if (intF == 28){ 
            string1 = "mul";
        }
        else if (intF == 8){
            string1 = "addi";
        }
        else if (intF == 12){
            string1 = "andi";
        }
        else if (intF == 13){
            string1 = "ori";
        }
        else if (intF == 14){
            string1 = "xori";
        }
        else if (intF == 10){
            string1 = "slti";
        }
        else if (intF == 15){
            string1 = "lui";
        }
        else if (intF == 32){
            string1 = "lb";
        }
        else if (intF == 33){
            string1 = "lh";
        }
        else if (intF == 35){
            string1 = "lw";
        }
        else if (intF == 40){
            string1 = "sb";
        }
        else if (intF == 41){
            string1 = "sh";
        }
        else if (intF == 43){
            string1 = "sw";
        }
        else if (intF == 4){
            string1 = "beq";
        }
        else if (intF == 5){
            string1 = "bne";
        }
        else if (intF == 6){
            string1 = "blez";
        }
        else if (intF == 7){
            string1 = "bgtz";
        }
        else if (intF == 1){   // there are two of these so gota check middle digits 
            string1 = "bgez";
            if(intM == 0){
                string1 = "bltz"; 
            }            
        }
        else if (intF == 2){
            string1 = "j";
        }
        else if (intF == 3){
            string1 = "jal";
        }
       

    } 
    return string1;
}


