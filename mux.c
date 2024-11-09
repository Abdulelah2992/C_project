#include <stdio.h>

int mux(int in1, int in2, int cntrl)
{
	int out;
	if(cntrl==0)
	{
		out=in1;
	} else if(cntrl==1)
	{
		out=in2;
	} else
	{
		return 100; //error signal in case needed
	}
	return out;
}
