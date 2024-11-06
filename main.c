#include<stdio.h>
#include <stdbool.h>

#include "mux.h"// (input1, input2, control)
#include "alu.h"// (A, B, control) 
#include "decoder.h"// int decoder(int in1, int in2, int* out1,int* out2,int* out3,int* out4)


void main(int argc, char *argv[])
{

	printf("should print 20 %d \n", mux(10, 20, 2));
	
	int sum;
	printf("conflict");
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
	
	int out1=0;
	int out2=0;
	int out3=0;
	int out4=0;

	int error= decoder(int 3, int in2, int* out1,int* out2,int* out3,int* out4);
	printf()

}
