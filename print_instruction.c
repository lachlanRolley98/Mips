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
int find_reg_7_11(uint32_t instruction);
int find_reg_11_16(uint32_t instruction);
int find_reg_17_21(uint32_t instruction);
int find_dec_end(uint32_t instruction);
int find_dec_mid(uint32_t instruction);
uint32_t find_4_bit_hex_end(uint32_t instruction);
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


void print_instruction(uint32_t instruction) {
    int a = 0;
    int b = 0;
    int c = 0;
    uint32_t d = 0;
    char *check123 = get_instruction(instruction); // get the name of the instruction
    int repi = get_num_repi(check123); // get number representation of intruction to make shit easier
    //printf("%s\n", check123);     
    //int b = strcmp("add", check123); // b = 0 if they match, 1 if they dont
    //if(b == 0){
    //  printf("%d\n", repi); 
    //}
    // this does  [ add, sub, mul, and, or, xor, sllv, srlv, slt]
    if(repi == 1 || repi == 2 || repi == 3 || repi == 4 || repi == 5 || repi == 6 || repi == 7 || repi == 8 || repi == 9){
        a = find_reg_17_21(instruction);
        b = find_reg_7_11(instruction);
        c = find_reg_11_16(instruction);
        printf("%s $%d, $%d, $%d",check123 ,a ,b ,c);
    }
    // this does  [ addi, andi, ori, xori, slti]
    else if(repi == 10 || repi == 11 || repi == 12 || repi == 13 || repi == 16 ){    
        a = find_reg_11_16(instruction);
        b = find_reg_7_11(instruction);
        c = find_dec_end(instruction);
        printf("%s $%d, $%d, %d",check123 ,a ,b ,c);
    }
    // this does  [ssl, srl ]
    else if(repi == 14 || repi == 15 ){   
        a = find_reg_17_21(instruction); 
        b = find_reg_11_16(instruction);
        c = find_dec_mid(instruction);
        printf("%s $%d, $%d, %d",check123 ,a ,b ,c);
    }
    // this does  [ lui ]
    else if(repi == 17 ){   
        a = find_reg_11_16(instruction); 
        b = find_dec_end(instruction);
        printf("%s $%d, %d",check123 ,a ,b);
    }
    // this does  [ beq, bne ]
    else if(repi == 24 || repi == 25){    
        a = find_reg_7_11(instruction);       
        b = find_reg_11_16(instruction);
        c = find_dec_end(instruction);
        printf("%s $%d, $%d, %d",check123 ,a ,b ,c);
    }
    // this does  [ blez, bgtz, bltz, bgez ]
    else if(repi == 26 || repi == 27 || repi == 28 || repi == 29){   
        a = find_reg_7_11(instruction); 
        b = find_dec_end(instruction);
        printf("%s $%d, %d",check123 ,a ,b);
    }
    // this does  [ jr ]
    else if(repi == 32){   
        a = find_reg_7_11(instruction); 
        printf("%s $%d",check123 ,a);
    }
    // this does  [ syscall ]
    else if(repi == 33){    
        printf("syscall");
    }
    // this does  [ lb, lh, lw, sb, sh, sw ]
    else if(repi == 18 || repi == 19 || repi == 20 || repi == 21 || repi == 22 || repi == 23){    
        a = find_reg_11_16(instruction);              
        b = find_dec_end(instruction);
        c = find_reg_7_11(instruction); 
        find_dec_end(instruction);
        printf("%s $%d, %d($%d)",check123 ,a ,b ,c);
    }
    else if(repi == 30 || repi == 31){   
        d = find_4_bit_hex_end(instruction); 
        printf("%s 0x%04x",check123 ,d);
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
    if (strcmp("add", check123) == 0){ // change these ifs to else if probs //
        aa = 1;
    }
    else if (strcmp("sub", check123) == 0){//
        aa = 2;
    }
    else if (strcmp("mul", check123) == 0){//
        aa = 3;
    }
    else if (strcmp("and", check123) == 0){//
        aa = 4;
    }
    else if (strcmp("or", check123) == 0){//
        aa = 5;
    }
    else if (strcmp("xor", check123) == 0){//
        aa = 6;
    }
    else if (strcmp("sllv", check123) == 0){//
        aa = 7;
    }
    else if (strcmp("srlv", check123) == 0){//
        aa = 8;
    }
    else if (strcmp("slt", check123) == 0){//
        aa = 9;
    }
    else if (strcmp("addi", check123) == 0){//
        aa = 10;
    }
    else if (strcmp("andi", check123) == 0){//
        aa = 11;
    }
    else if (strcmp("ori", check123) == 0){//
        aa = 12;
    }
    else if (strcmp("xori", check123) == 0){//
        aa = 13;
    }
    else if (strcmp("sll", check123) == 0){//
        aa = 14;
    }
    else if (strcmp("srl", check123) == 0){//
        aa = 15;
    }
    else if (strcmp("slti", check123) == 0){//
        aa = 16;
    }
    else if (strcmp("lui", check123) == 0){//
        aa = 17 ;
    }
    else if (strcmp("lb", check123) == 0){//
        aa = 18;
    }
    else if (strcmp("lh", check123) == 0){//
        aa = 19;
    }
    else if (strcmp("lw", check123) == 0){//
        aa = 20;
    }
    else if (strcmp("sb", check123) == 0){//
        aa = 21;
    }
    else if (strcmp("sh", check123) == 0){//
        aa = 22;
    }
    else if (strcmp("sw", check123) == 0){//
        aa = 23;
    }
    else if (strcmp("beq", check123) == 0){//
        aa = 24;
    }
    else if (strcmp("bne", check123) == 0){//
        aa = 25;
    }
    else if (strcmp("blez", check123) == 0){//
        aa = 26;
    }
    else if (strcmp("bgtz", check123) == 0){//
        aa = 27;
    }
    else if (strcmp("bltz", check123) == 0){//
        aa = 28;
    }
    else if (strcmp("bgez", check123) == 0){//
        aa = 29;
    }
    else if (strcmp("j", check123) == 0){
        aa = 30;
    }
    else if (strcmp("jal", check123) == 0){
        aa = 31;
    }
    else if (strcmp("jr", check123) == 0){//
        aa = 32;
    }
    else if (strcmp("syscall", check123) == 0){//
        aa = 33;
    }
    
    return aa;
}    

int find_reg_7_11(uint32_t instruction){
    int wawa = (instruction >> 21) & 31;
    return wawa;
}
int find_reg_11_16(uint32_t instruction){
    int bawa = (instruction >> 16) & 31;
    return bawa;
}
int find_reg_17_21(uint32_t instruction){
    int kawa = (instruction >> 11) & 31;
    return kawa;
}
int find_dec_end(uint32_t instruction){
    int tawa = instruction & 65535;
    return tawa;
}
int find_dec_mid(uint32_t instruction){
    int vawa = (instruction >> 6) & 31;
    return vawa;
}
uint32_t find_4_bit_hex_end(uint32_t instruction){
    uint32_t zawa = 67108863 & instruction;
    return zawa;
}