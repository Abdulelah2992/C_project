#include <stdio.h>

int decoder(int in1, int in2, int* out1,int* out2,int* out3,int* out4)
{
	
	switch (in1*10+in2)
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
		return;
	}
	return 0;
}
