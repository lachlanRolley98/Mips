// If you use C library functions add includes here.

#include "emu.h"
#include "ram.h"
#include "registers.h"
#include <string.h>


char *get_instructionEXE(uint32_t instruction);
int find_reg_7_11EXE(uint32_t instruction);
int find_reg_11_16EXE(uint32_t instruction);
int find_reg_17_21EXE(uint32_t instruction);
int16_t find_dec_endEXE(uint32_t instruction);
int find_dec_midEXE(uint32_t instruction);
uint32_t find_4_bit_hex_endEXE(uint32_t instruction);


/**
 * execute a MIPS instruction
 *
 * This function should:
 *
 * get register values by calling `get_register(register_type register_number)`
 * change registers by calling `set_register(register_type register_number, uint32_t value)`
 *
 * get memory values by `calling get_byte(uint32_t address)`
 * changes memory by `set_byte(uint32_t address, uint8_t value)`
 *
 * updates program_counter to address of next instruction
 *
 * returns 1 if an exit syscall is executed, 0 otherwise
 */
int execute_instruction(uint32_t instruction, uint32_t *program_counter) {   
    char *checkEXE = get_instructionEXE(instruction);
    int a = 0;
    int b = 0;
    int c = 0;
    //uint32_t d = 0;
    //int16_t e = 0;
    
    if (strcmp("add", checkEXE) == 0){        //done
    
        a = find_reg_17_21EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        c = find_reg_11_16EXE(instruction);

        uint32_t x = get_register(b);
        uint32_t y = get_register(c);
        uint32_t sum = x + y;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0;   
    }
    else if (strcmp("sub", checkEXE) == 0){        //done
    
        a = find_reg_17_21EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        c = find_reg_11_16EXE(instruction);

        uint32_t x = get_register(b);
        uint32_t y = get_register(c);
        uint32_t sum = x - y;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0;   
    }
    else if (strcmp("mul", checkEXE) == 0){        //done
    
        a = find_reg_17_21EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        c = find_reg_11_16EXE(instruction);

        uint32_t x = get_register(b);
        uint32_t y = get_register(c);
        uint32_t sum = x * y;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0;   
    }
    else if (strcmp("and", checkEXE) == 0){        //done
    
        a = find_reg_17_21EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        c = find_reg_11_16EXE(instruction);

        uint32_t x = get_register(b);
        uint32_t y = get_register(c);
        uint32_t sum = x & y;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0;   
    }
    else if (strcmp("or", checkEXE) == 0){         //done
    
        a = find_reg_17_21EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        c = find_reg_11_16EXE(instruction);

        uint32_t x = get_register(b);
        uint32_t y = get_register(c);
        uint32_t sum = x | y;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0;   
    }
    else if (strcmp("xor", checkEXE) == 0){        //done
    
        a = find_reg_17_21EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        c = find_reg_11_16EXE(instruction);

        uint32_t x = get_register(b);
        uint32_t y = get_register(c);
        uint32_t sum = x ^ y;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0;   
    }
    else if (strcmp("sllv", checkEXE) == 0){       //done
    
        a = find_reg_17_21EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        c = find_reg_11_16EXE(instruction);

        uint32_t x = get_register(b);
        uint32_t y = get_register(c);
        uint32_t sum = y << x;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0;   
    }
    else if (strcmp("srlv", checkEXE) == 0){       //done
    
        a = find_reg_17_21EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        c = find_reg_11_16EXE(instruction);

        uint32_t x = get_register(b);
        uint32_t y = get_register(c);
        uint32_t sum = y >> x;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0;   
    }
    else if (strcmp("slt", checkEXE) == 0){ 
    
        a = find_reg_17_21EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        c = find_reg_11_16EXE(instruction);

        uint32_t x = get_register(b);
        uint32_t y = get_register(c);
        uint32_t sum = (x < y);
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0;   
    }
    return 0;  
}

// PUT EXTRA FUNCTIONS HERE
char *get_instructionEXE(uint32_t instruction){

    uint32_t intF = instruction >> 26;      // got first 6 bits moved to the front now
    uint32_t intL = instruction & 63;        // got last 6 bits as 63 = 00000000000000000000000111111
    uint32_t intM = (instruction >> 16) & 31;  //this the middle 5 bits, not the middle left but middle all moved to left hand size

    
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
int find_reg_7_11EXE(uint32_t instruction){
    int wawa = (instruction >> 21) & 31;
    return wawa;
}
int find_reg_11_16EXE(uint32_t instruction){
    int bawa = (instruction >> 16) & 31;
    return bawa;
}
int find_reg_17_21EXE(uint32_t instruction){
    int kawa = (instruction >> 11) & 31;
    return kawa;
}
int16_t find_dec_endEXE(uint32_t instruction){
    uint32_t tawa = instruction & 65535;
    int16_t hawa = tawa ;                      //this makes it signed
    return hawa;
}
int find_dec_midEXE(uint32_t instruction){
    int vawa = (instruction >> 6) & 31;        // doesnt have to be signed cos only used in shift algebra which always poss
    return vawa;
}
uint32_t find_4_bit_hex_endEXE(uint32_t instruction){
    uint32_t zawa = 67108863 & instruction;
    return zawa;
}