#include<stdio.h>
#include <stdbool.h>

#include "mux.h"// (input1, input2, control)
#include "alu.h"// (A, B, control) 
#include "decoder.h"// int decoder(int in1, int in2, int* out1,int* out2,int* out3,int* out4)
#include "decoderfunction.h"

//int error= decoder(int 3, int in2, int* out1,int* out2,int* out3,int* out4);
int main(int argc, char *argv[])
{

	int sum;
	bool carry;
	char infile[100];

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

	bool j,c,d1,d0,sreg,s,custom1,custom0;//definition of each bit
	int counter=0;// initializing
	int rega= 0;
	int regb= 0;
	int reg0= 0;
	int regc= 0;
	int custom_input=0;
	int rega_temp=0;
	//Defining the ra, rb, r0 activation
	
	int activate_ra=0;
	int activate_rb=0;
	int activate_r0=0;
	int activate_nothing=0;
	int custom_or_alu_output;
	int z;
	

//	printf("mem0 is:%08b \n ", mem[0]);
//	printf("mem1 is:%08b \n ", mem[1]);
//	printf("mem2 is:%08b \n ", mem[2]);
//	printf("mem3 is:%08b \n ", mem[3]);
//	printf("mem4 is:%08b \n ", mem[4]);
//	printf("mem5 is:%08b \n ", mem[5]);
//*	printf("mem6 is:%08b \n ", mem[6]);
//	printf("mem7 is:%08b \n ", mem[7]);
//	printf("mem8 is:%08b \n ", mem[8]);


	#include "mux.h"// (input1, input2, control)
	#include "alu.h"// (A, B, control) 
	#include "decoder.h"// int decoder(int in1, int in2, int* out1,int* out2,int* out3,int* out4)
	int x_x=0;
	int erroralu;

	
	char oldfile[256];
	sprintf(oldfile,"%s.asm",argv[1]);
        FILE* codefile = fopen(oldfile, "r");
	//infile to oldfile, and code
	

	int MAX_LINES=200;
	int MAX_LINE_LENGTH=100;
	char lines[MAX_LINES][MAX_LINE_LENGTH]; // 2D array to store the lines
    	int line_count = 0;
	char ifcontinue;

    	// Read each line from the file and store it in the 2D array
	while (fgets(lines[line_count], MAX_LINE_LENGTH, codefile) != NULL) 
	{
		line_count++;
		if (line_count >= MAX_LINES) {//////////////////////////////////////////////////////////////////////////
	    	break;
		}
	}
	fclose(codefile);

	

	printf("insert s for step by step and r for run \n");
	char run_step;
	scanf("%c", &run_step);
	while(counter < 9*2)
	{
		
		decoder_function(mem[counter], &j, &c, &d1, &d0, &sreg, &s, &custom1, &custom0); //This for getting the code to 
												 //a control signal
		//////////////printf("j=%d c=%d d1=%d d0=%d sreg=%d s=%d custom1=%d custom0=%d\n",
		//////////////		j, c, d1, d0, sreg, s, custom1, custom0);

		custom_input=4*s+2*custom1+custom0;//Take the new value of custom input

		if(j || (c && regc))//If jump or conditional jump(we need regc of the previous) is activated
		{
			counter=custom_input;
			counter=counter*2;
			continue;
		}
		

		//int decoder(int in1, int in2, int* out1,int* out2,int* out3,int* out4)
		//This decoder is for activating which register
		decoder(d0, d1, &activate_ra, &activate_r0, &activate_rb, &activate_nothing);
		///////////////printf("activate_ra is: %d, activate_rb is: %d,activate_r0 is: %d", activate_ra, activate_rb, activate_r0);	
		// Take values of rega and regb to alu
		// These are the values of sum and carry
		erroralu = alu(rega,regb,s,&sum,&carry);//alu will get the value of the old rega and regb which is what we want
		//////////////printf("\n sum is %d\n", sum);

		if(erroralu !=0)
		{
			printf("There is an error in ALU\n");
		}
		custom_or_alu_output= mux(sum, custom_input, sreg);// 0 for sum 1 for sreg, function will output sum or cust inpt
		//////////////printf("output of mux is %d \n", custom_or_alu_output);
		
		if(activate_ra)
		{
		rega = activate_ra * custom_or_alu_output;
		}
		if(activate_rb)
		{
		regb = activate_rb * custom_or_alu_output;
		}
		//////////////printf("value of reg b is: %d \n", regb);
		//////////////printf("value of reg a is: %d \n", rega);
		if(run_step=='s')
		{
			printf("instruction %d: %s", x_x, lines[counter/2]);
			printf("   press enter to continue \n");
			scanf("%c", &ifcontinue);
			if(ifcontinue!= '\n')
			{
				printf("finished running");
				break;
			}
			
		}
		if(activate_r0 && run_step=='r')
		{
		reg0 = activate_r0 * rega;// we could change this things position before the rega and regb new def, but "register to store the final result after all the processing"//
		printf("reg0=%d \n", reg0);
		}
		else if(activate_r0 && run_step=='s')
		{
		reg0 = activate_r0 * rega;// we could change this things position before the rega and regb new def, but "register to store the final result after all the processing"//
		printf("reg0=%d \n", reg0);
		} 
		else if(run_step != 's' && run_step != 'r')
		{
			printf("wrong input maybe check caps\n");
			break;
		}
		
		counter++;
		counter++;
		x_x++;
		if(x_x == 88)
		{
			break;
		}
		regc=carry;// what if jump what to do with regc? IDK but I guess we keep it
	}
	
	
	
    	return 0;
}
