#include <stdio.h>
#include <stdbool.h>


int alu(unsigned int in1, unsigned int in2, unsigned int cntrl, int* sum, bool* carry)
//could improve ALU here through using the last two bits to decide operations aswell keep in mind S (the third from the right of the schedule) is being used.
{
	// carry in only used for subtraction
	// carry out only used for jumps
	unsigned int out;
	//unsigned int carry_out;
	
	*carry = 0;
	if(in1 > 15 || in2 >15)
	{
		//printf("\n input 1 or input 2 are out of range \n");	
		return 1;
		//out = out % 16;
		//output_arr[0]=out;
		//output_arr[1]=carry_out;
	//	return output_arr;
	}
	if(!(cntrl == 0 || cntrl ==1))
	{
		return 2;
	//	printf("\n The control input is wrong \n");
	///	out = out % 16;
	//	output_arr[0]=out;
	//	output_arr[1]=carry_out;
	//	return output_arr;
	}

	//out = out % 16;
	//output_arr[0]=out;
	//output_arr[1]=carry_out;

	if(cntrl == 0)
	{
		out = in1+in2;
	}
	else
	{
		out = in1+ ~in2+1;
	}
	if(out > 15)
	{
		*carry=1;
	}

	*sum = out%16;

	return 0;
}
