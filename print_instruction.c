// If you use C library functions add includes here.

#include "emu.h"
#include "ram.h"
#include "registers.h"
#include <string.h>

/*
 * print a MIPS instruction (no newline)
 * run reference implementation if unsure what to print
 */
///////////////////////////////////////////////////////
/// FUNCTION FOREWARNINGS                    //////////
///////////////////////////////////////////////////////
char *get_instruction(uint32_t instruction);
int get_num_repi(char *check123);
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


void print_instruction(uint32_t instruction) {
    
    char *check123 = get_instruction(instruction); // get the name of the instruction
    printf("%s\n", check123); 
    
    int repi = get_num_repi(check123);
    //int b = strcmp("add", check123); // b = 0 if they match, 1 if they dont
    //if(b == 0){
      printf("%d\n", repi); 
    //}
    if(repi == 1 || repi == 2 || repi == 3 || repi == 4 || repi == 5 || repi == 6 || repi == 7 || repi == 8 || repi == 9){
        printf("i am a coding god\n");
    }

   
    
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

int get_num_repi(char *check123){
    int aa = 0;
    if (strcmp("add", check123) == 0){
        aa = 1;
    }
    if (strcmp("sub", check123) == 0){
        aa = 2;
    }
    if (strcmp("mul", check123) == 0){
        aa = 3;
    }
    if (strcmp("and", check123) == 0){
        aa = 4;
    }
    if (strcmp("or", check123) == 0){
        aa = 5;
    }
    if (strcmp("xor", check123) == 0){
        aa = 6;
    }
    if (strcmp("sllv", check123) == 0){
        aa = 7;
    }
    if (strcmp("srlv", check123) == 0){
        aa = 8;
    }
    if (strcmp("slt", check123) == 0){
        aa = 9;
    }
    
    return aa;
}    