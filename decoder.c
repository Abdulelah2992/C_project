#include <stdio.h>
#include <stdbool.h>
int decoder(bool in1, bool in2, int* out1,int* out2,int* out3,int* out4)
{
	*out1=0;
	*out2=0;
	*out3=0;
	*out4=0;
	switch (in1+in2*10)
	{
	case 0:
		*out1=1;
		break;
	case 10:
		*out2=1;
		break;
	case 1:
		*out3=1;
		break;
	case 11:
		*out4=1;
		break;
	default:
		return 1;
	}
	return 0;
}

