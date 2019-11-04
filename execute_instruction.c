// If you use C library functions add includes here.

#include "emu.h"
#include "ram.h"
#include "registers.h"
#include <string.h>

//theres gota be a way to use the old print instruction functions, mby throw all in a .h file ??
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
    uint32_t d = 0;
    int16_t e = 0;
    
    if (strcmp("add", checkEXE) == 0){             //done
        
        //find what registers we need (14,11,7)
        a = find_reg_17_21EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        c = find_reg_11_16EXE(instruction);
        
        //now we got the registers, grab vals inside them
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
    else if (strcmp("slt", checkEXE) == 0){        //done
        //find what registers we need (14,11,7)
        a = find_reg_17_21EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        c = find_reg_11_16EXE(instruction);
        //now we got the registers, grab vals inside them
        uint32_t x = get_register(b);
        uint32_t y = get_register(c);
        uint32_t sum = (x < y);
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0;   
    }
    else if(strcmp("addi", checkEXE) == 0 ){       //done ?????*4 neg ints and shit  
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        e = find_dec_endEXE(instruction);

        int16_t x = get_register(b);
        int16_t sum = x + e ;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0; 

    }
    else if(strcmp("andi", checkEXE) == 0){        //done ?negs?
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        e = find_dec_endEXE(instruction);

        int16_t x = get_register(b);
        int16_t sum = x & e ;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0; 
    }
    else if(strcmp("ori", checkEXE) == 0 ){        //done ?negs?
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        e = find_dec_endEXE(instruction);

        int16_t x = get_register(b);
        int16_t sum = x | e ;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0; 
    }
    else if(strcmp("xori", checkEXE) == 0 ){       //done ?negs?
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        e = find_dec_endEXE(instruction);

        int16_t x = get_register(b);
        int16_t sum = x ^ e ;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0; 
    }
    else if (strcmp("sll", checkEXE) == 0){        //done
        //find what registers we need (14,11,7)
        a = find_reg_17_21EXE(instruction);
        c = find_reg_11_16EXE(instruction);
        e = find_dec_midEXE(instruction);
        //now we got the registers, grab vals inside them
        uint32_t x = get_register(c);        
        uint32_t sum = x << e;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0;   
    }  
    else if (strcmp("srl", checkEXE) == 0){        //done
        //find what registers we need (14,11,7)
        a = find_reg_17_21EXE(instruction);
        c = find_reg_11_16EXE(instruction);
        e = find_dec_midEXE(instruction);
        //now we got the registers, grab vals inside them
        uint32_t x = get_register(c);        
        uint32_t sum = x >> e;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0;   
    } 
    else if (strcmp("slti", checkEXE) == 0){       //done     
        //find what registers we need (14,11,7)
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        e = find_dec_endEXE(instruction);

        int16_t x = get_register(b);
        int16_t sum = (x < e) ;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0; 
    } 
    else if (strcmp("lui", checkEXE) == 0){        //done    
        //find what registers we need (14,11,7)
        a = find_reg_11_16EXE(instruction);
        d = find_dec_endEXE(instruction);

        int32_t sum = d << 16 ;
        set_register(a, sum); 
        (*program_counter) += 4;
        return 0; 
    } 
    else if (strcmp("lb", checkEXE) == 0){         //done baby   
        //find what registers we need (14,11,7)
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);   // is the byte ?
        e = find_dec_endEXE(instruction);    // e is signed 16     
        
        //seems you get the address by going get_register(11) + 8 and this will give you the address

        // once the address is got, you throw it in get_byte(address) anf then store it in the new reg
        uint32_t address_take =  get_register(b) + e;  // b is the register in question so you get the address held bye it in get register then add the offset       
        //uint32_t address_store =  get_register(a);
        uint8_t the_byte = get_byte(address_take); // now we have the byte content of from the address
        // gota sign extend or someshit so i think if there is a 1 in the most signif, just bitmask it all with 0xFFFFFF00
        uint32_t sign_extended_byte = the_byte;
        if (the_byte >> 7 == 1){
            sign_extended_byte = the_byte | 0xFFFFFF00;
        }
        set_register(a, sign_extended_byte); // load/store that shit
          
        (*program_counter) += 4;
        return 0; 
    }
    else if (strcmp("lh", checkEXE) == 0){         //done    
        //find what registers we need (14,11,7)
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);   // is the byte ?
        e = find_dec_endEXE(instruction);    // e is signed 16     
        
        //seems you get the address by going get_register(11) + 8 and this will give you the address

        // once the address is got, you throw it in get_byte(address) anf then store it in the new reg
        uint32_t address_take =  get_register(b) + e;  // b is the register in question so you get the address held bye it in get register then add the offset       
        //uint32_t address_store =  get_register(a);
        uint16_t the_right_byte = get_byte(address_take); // now we have half the byte content of from the address
        uint16_t the_left_byte = get_byte(address_take + 1) << 8;
        uint16_t the_byte = the_right_byte | the_left_byte;
        
        
        
        // gota sign extend or someshit so i think if there is a 1 in the most signif, just bitmask it all with 0xFFFFFF00
        uint32_t sign_extended_byte = the_byte;
        if (the_byte >> 15 == 1){
            sign_extended_byte = the_byte | 0xFFFF0000;
        }
        set_register(a, sign_extended_byte); // load/store that shit
          
        (*program_counter) += 4;
        return 0; 
    }
    else if (strcmp("lw", checkEXE) == 0){         //done    
        //find what registers we need (14,11,7)
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);   // is the byte ?
        e = find_dec_endEXE(instruction);    // e is signed 16     
        
        //seems you get the address by going get_register(11) + 8 and this will give you the address

        // once the address is got, you throw it in get_byte(address) anf then store it in the new reg
        uint32_t address_take =  get_register(b) + e;  // b is the register in question so you get the address held bye it in get register then add the offset       
        //uint32_t address_store =  get_register(a);
        uint32_t the_right_byte = get_byte(address_take); // now we have half the byte content of from the address
        uint32_t the_rm_byte = get_byte(address_take + 1) << 8;
        uint32_t the_lm_byte = get_byte(address_take + 2) << 16;
        uint32_t the_left_byte = get_byte(address_take + 3) ;
        the_left_byte = the_left_byte << 24;
        
        uint32_t the_byte = the_right_byte | the_left_byte | the_rm_byte | the_lm_byte;
        
        
        
        // dont have to sign extend
        //uint32_t sign_extended_byte = the_byte;
        //if (the_byte >> 15 == 1){
        //    sign_extended_byte = the_byte | 0xFFFF0000;
        //}
        set_register(a, the_byte); // load/store that shit
          
        (*program_counter) += 4;
        return 0; 
    }
    else if (strcmp("sb", checkEXE) == 0){         //done     
        //find what registers we need (14,11,7)
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);   // is the byte ?
        e = find_dec_endEXE(instruction);    // e is signed 16     
        
        uint8_t the_byte = get_register(a) & 0xFF;
        //uint8_t the_byte = a & 0xff; // now we have the byte content of from the address
        
        uint32_t address_give =  get_register(b) + e;
        set_byte(address_give, the_byte); // load/store that shit
          
        (*program_counter) += 4;
        return 0; 
    }
    else if (strcmp("sh", checkEXE) == 0){         //done    
        //find what registers we need (14,11,7)
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);   // is the byte ?
        e = find_dec_endEXE(instruction);    // e is signed 16     
        
        
        uint8_t the_right_byte = get_register(a) & 0xFF; // now we have the byte content of from the address
        uint8_t the_left_byte = get_register(a) >> 8 & 0xFF; // now we have the byte content of from the address
        uint32_t address_give =  get_register(b) + e;
        set_byte(address_give, the_right_byte); // load/store that shit
        set_byte(address_give + 1, the_left_byte); // load/store that shit
          
        (*program_counter) += 4;
        return 0; 
    }
    else if (strcmp("sw", checkEXE) == 0){         //done  
        //find what registers we need (14,11,7)
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);   // is the byte ?
        e = find_dec_endEXE(instruction);    // e is signed 16     
        
        
        uint8_t the_right_byte = get_register(a) & 0xFF; // now we have the byte content of from the address
        uint8_t the_rm_byte = get_register(a) >> 8 & 0xFF; // now we have the byte content of from the address
        uint8_t the_lm_byte = get_register(a) >> 16 & 0xFF; // now we have the byte content of from the address
        uint8_t the_left_byte = get_register(a) >> 24 & 0xFF; // now we have the byte content of from the address
        uint32_t address_give =  get_register(b) + e;
        set_byte(address_give, the_right_byte); // load/store that shit
        set_byte(address_give + 1, the_rm_byte); // load/store that shit
        set_byte(address_give + 2, the_lm_byte); // load/store that shit
        set_byte(address_give + 3, the_left_byte); // load/store that shit  
        (*program_counter) += 4;
        return 0; 
    }
    else if (strcmp("beq", checkEXE) == 0){        //done     
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        e = find_dec_endEXE(instruction);

        int16_t x = get_register(a);
        int16_t y = get_register(b);
        uint32_t sign_extended_counter = e;
        if (e >> 15 == 1){
            sign_extended_counter = e | 0xFFFF0000;
        }
        if (x == y){
            (*program_counter) += sign_extended_counter << 2 ;
        }
        if ( x!= y){
            (*program_counter) += 4;
        }        
        return 0; 
    } 
    else if (strcmp("bne", checkEXE) == 0){        //done     
        a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        e = find_dec_endEXE(instruction);

        int16_t x = get_register(a);
        int16_t y = get_register(b);
        uint32_t sign_extended_counter = e;
        if (e >> 15 == 1){
            sign_extended_counter = e | 0xFFFF0000;
        }
        if (x != y){
            (*program_counter) += sign_extended_counter << 2 ;
        }
        if ( x == y){
            (*program_counter) += 4;
        }        
        return 0; 
    } 
    else if (strcmp("blez", checkEXE) == 0){       //done     
        //a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        e = find_dec_endEXE(instruction);

        //int16_t x = get_register(a);
        int16_t y = get_register(b);
        uint32_t sign_extended_counter = e;
        if (e >> 15 == 1){
            sign_extended_counter = e | 0xFFFF0000;
        }
        if ( y <= 0 ){
            (*program_counter) += sign_extended_counter << 2 ;
        }
        if ( y > 0 ){
            (*program_counter) += 4;
        }        
        return 0; 
    } 
    else if (strcmp("bgtz", checkEXE) == 0){       //done     
        //a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        e = find_dec_endEXE(instruction);

        //int16_t x = get_register(a);
        int16_t y = get_register(b);
        uint32_t sign_extended_counter = e;
        if (e >> 15 == 1){
            sign_extended_counter = e | 0xFFFF0000;
        }
        if ( y > 0 ){
            (*program_counter) += sign_extended_counter << 2 ;
        }
        if ( y <= 0 ){
            (*program_counter) += 4;
        }        
        return 0; 
    }
    else if (strcmp("bltz", checkEXE) == 0){       //done     
        //a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        e = find_dec_endEXE(instruction);

        //int16_t x = get_register(a);
        int16_t y = get_register(b);
        uint32_t sign_extended_counter = e;
        if (e >> 15 == 1){
            sign_extended_counter = e | 0xFFFF0000;
        }
        if ( y < 0 ){
            (*program_counter) += sign_extended_counter << 2 ;
        }
        if ( y >= 0 ){
            (*program_counter) += 4;
        }        
        return 0; 
    }
    else if (strcmp("bgez", checkEXE) == 0){       //done     
        //a = find_reg_11_16EXE(instruction);
        b = find_reg_7_11EXE(instruction);
        e = find_dec_endEXE(instruction);

        //int16_t x = get_register(a);
        int16_t y = get_register(b);
        uint32_t sign_extended_counter = e;
        if (e >> 15 == 1){
            sign_extended_counter = e | 0xFFFF0000;
        }
        if ( y >= 0 ){
            (*program_counter) += sign_extended_counter << 2 ;
        }
        if ( y < 0 ){
            (*program_counter) += 4;
        }        
        return 0; 
    }
    else if (strcmp("j", checkEXE) == 0){          //done     
        
        
        uint32_t X = 67108863 & instruction;
           
        (*program_counter) = (*program_counter & 0xF0000000) | (X << 2);
                
        return 0; 
    }
    else if (strcmp("jal", checkEXE) == 0){        //done     
        
        
        uint32_t X = 67108863 & instruction;
        set_register(31, *program_counter + 4);   

        (*program_counter) = (*program_counter & 0xF0000000) | (X << 2);
                
        return 0; 
    }
    else if (strcmp("jr", checkEXE) == 0){         //done     
        
        b = find_reg_7_11EXE(instruction);        
        int16_t y = get_register(b);       
        (*program_counter) = y ;              
        return 0; 
    }
    else if (strcmp("syscall", checkEXE) == 0){    //done     
        
        int v_0 = get_register(2);  // $v0
        
        if (v_0 == 1){             //print int
            int a_0 = get_register(4);
            printf("%d",a_0);
            (*program_counter) += 4;
            return 0;
        } 
        if (v_0 == 4){             //print string not working
            int x = 0;
            uint32_t address_takebb =  get_register(4) ;
            
            //if we can grab a single int and print its asccii form
            int aa_0 = get_byte(address_takebb); 
            
            while(aa_0 != '\0'){
                address_takebb =  get_register(4) + x; // will grab the address of the byte next to the byte
                aa_0 = get_byte(address_takebb);
                printf("%c",aa_0);
                x ++;

            }
            (*program_counter) += 4;
            
            return 0;

        } 
        if (v_0 == 5){             //read int
            int h = 0;
            scanf("%d", &h);
            set_register(2, h);
            (*program_counter) += 4;
            return 0;
        } 
        /*if (v_0 == 8){            //read string not working
            //int x = 0;
            //uint32_t address_take =  get_register(4) + x;
            
            //if we can grab a single int and print its asccii form
            int a_0 = get_register(4); // this only works if its a 1 character string
            
            //while(a_0 != '\0'){
                //address_take =  get_register(4) + x;
                //a_0 = get_byte(address_take);
            printf("%c",a_0);
                //x ++;

            //}
            (*program_counter) += 4;
            return 0;

        } */
        if (v_0 == 10){            //exit
            
            return 1;
        }
        if (v_0 == 11){            //print char
            //int x = 0;
            //uint32_t address_take =  get_register(4) + x;
            
            //if we can grab a single int and print its asccii form
            int a_0 = get_register(4); // this only works if its a 1 character string
            
            //while(a_0 != '\0'){
                //address_take =  get_register(4) + x;
                //a_0 = get_byte(address_take);
            printf("%c",a_0);
                //x ++;

            //}
            (*program_counter) += 4;
            return 0;

        } 
        if (v_0 == 11){            //read char
            char q = 0;
            scanf("%c", &q);
            set_register(2, q);
            (*program_counter) += 4;
            return 0;

        } 
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