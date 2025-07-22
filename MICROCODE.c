#include <stdio.h>

//Micro instruction
#define HLT 0b1000000000000000
#define MI  0b0100000000000000
#define RI  0b0010000000000000
#define RO  0b0001000000000000
#define IO  0b0000100000000000
#define II  0b0000010000000000
#define AI  0b0000001000000000
#define AO  0b0000000100000000
#define EO  0b0000000010000000
#define SU  0b0000000001000000
#define BI  0b0000000000100000
#define OI  0b0000000000010000
#define CE  0b0000000000001000
#define CO  0b0000000000000100
#define J   0b0000000000000010
#define FI  0b0000000000000001

#define flags 4
#define instructions 16
#define steps 8

#define JC 0b0111
#define JZ 0b1000

int main()
{
    int microcode_template[instructions][steps] = {
        {MI|CO, RO|II|CE, 0,     0,     0,           0, 0, 0}, // 0000 - NOP
        {MI|CO, RO|II|CE, IO|MI, RO|AI, 0,           0, 0, 0}, // 0001 - LDA
        {MI|CO, RO|II|CE, IO|MI, RO|BI, EO|AI|FI,    0, 0, 0}, // 0010 - ADD
        {MI|CO, RO|II|CE, IO|MI, RO|BI, EO|AI|SU|FI, 0, 0, 0}, // 0011 - SUB
        {MI|CO, RO|II|CE, IO|MI, AO|RI, 0,           0, 0, 0}, // 0100 - STA
        {MI|CO, RO|II|CE, IO|AI, 0,     0,           0, 0, 0}, // 0101 - LDI
        {MI|CO, RO|II|CE, IO|J,  0,     0,           0, 0, 0}, // 0110 - JMP
        {MI|CO, RO|II|CE, 0,     0,     0,           0, 0, 0}, // 0111 - 
        {MI|CO, RO|II|CE, 0,     0,     0,           0, 0, 0}, // 1000 - 
        {MI|CO, RO|II|CE, 0,     0,     0,           0, 0, 0}, // 1001 - 
        {MI|CO, RO|II|CE, 0,     0,     0,           0, 0, 0}, // 1010 - 
        {MI|CO, RO|II|CE, 0,     0,     0,           0, 0, 0}, // 1011 - 
        {MI|CO, RO|II|CE, 0,     0,     0,           0, 0, 0}, // 1100 - 
        {MI|CO, RO|II|CE, 0,     0,     0,           0, 0, 0}, // 1101 - 
        {MI|CO, RO|II|CE, AO|OI, 0,     0,           0, 0, 0}, // 1110 - OUT
        {MI|CO, RO|II|CE, HLT,   0,     0,           0, 0, 0}, // 1111 - HLT
    };

    int microcode[flags][instructions][steps];

    for(int i=0; i<flags; i++)
    {
        for(int j=0; j<instructions; j++)
        {
            for(int k=0; k<steps; k++)
            microcode[i][j][k] = microcode_template[j][k];
        }
    }

    microcode[0b01][JC][2] = IO|J;
    microcode[0b10][JZ][2] = IO|J;
    microcode[0b11][JC][2] = IO|J;
    microcode[0b11][JZ][2] = IO|J;


    // printing on terminal for debbugging

    // for(int address=0;  address<512; address++)
    // {
    //     int flag_value =          (address & 0b110000000) >> 7;
    //     int instrstrution_value = (address & 0b001111000) >> 3;
    //     int step_value =         (address & 0b000000111);

    //     printf("address=%d  %0X\n",address, microcode[flag_value][instrstrution_value][step_value]);
    // }


    // making microcode file

    FILE *fptr;

    fptr = fopen ("microcode", "w");

    if (fptr == NULL)
    {
        printf("error opening file!\n");
        return 1;
    }

    for(int address=0;  address<512; address++)
    {
        int flag_value =          (address & 0b110000000) >> 7;
        int instrstrution_value = (address & 0b001111000) >> 3;
        int step_value =         (address & 0b000000111);

        fprintf(fptr, "%0X\n", microcode[flag_value][instrstrution_value][step_value]);
    }
    

    fclose(fptr);

    return 0;
}