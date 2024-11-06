#include <stdio.h>

int mux(int in1, int in2, int cntrl)
{
	int out;
	if(cntrl==0)
	{
		out=in1;
	}else
	{
		out=in2;
	}
	return out;
}
