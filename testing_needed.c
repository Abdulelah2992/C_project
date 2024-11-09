Friday edit
#include<stdio.h>
#include <stdbool.h>

#include "mux.h"// (input1, input2, control)
#include "alu.h"// (A, B, control) 
#include "decoder.h"// int decoder(int in1, int in2, int* out1,int* out2,int* out3,int* out4)
#include "decoderfunction.h"
int main(int argc, char *argv[])
{

        printf("should print 10 %d \n", mux(10, 20, 1));




        int sum;
        bool carry;

        int errorCode= alu(12, 1, 0,&sum, &carry);
        printf("should print 13 %d \n", sum);
        printf("should print 0: %d \n", carry);

        int errorCode1= alu(12, 12, 0,&sum,&carry);
        printf("should print 8 %d \n", sum);
        printf("should print 1 %d \n", carry);


        printf("should print the no error thing %d \n", errorCode1);


        int errorCode2= alu(17, 1, 0,&sum,&carry);
        printf("error code for too high input  %d \n", errorCode2);

        int errorCode3= alu(13, 1, 5,&sum,&carry);
        printf("error code for wrong control signal  %d \n", errorCode3);

        char infile[100];

        //int error= decoder(int 3, int in2, int* out1,int* out2,int* out3,int* out4);
        sprintf(infile,"%s.bin",argv[1]);
        FILE* file = fopen(infile, "rb");

        // Buffer to store each line of the file.
        char line[9];
        char mem[9]="";//this is where the magic happens with or operation to alter bits
        int i=0;
        int k;


        // Check if the file was opened successfully.
        if (file != NULL)
        {
                while (fgets(line, sizeof(line), file))
                {
                        mem[i] = 0;
                        for(k=0; k<8; k++)
                        {
                                if (line[k]=='1')
                                {
                                        mem[i] =mem[i] | 1<<(7-k);
                                }
                        }
                        i=i+1;
                }
                fclose(file);
        }
        else
        {
                fprintf(stderr, "Unable to open file!\n");//I read online stderr gives diagnostic 
        }
        printf("%08b \n", mem[0]);

        // Now decode
        bool j,c,d1,d0,sreg,s,custom1,custom0;//definition of each bit

        decoder_function(mem[0], &j, &c, &d1, &d0, &sreg, &s, &custom1, &custom0);

        printf("j=%d c=%d d1=%d d0=%d sreg=%d s=%d custom1=%d custom0=%d \n", j,c,d1,d0,sreg,s,custom1,custom0);
    
} 
