#include <stdio.h>

void main()
{
	int userinput=1;
	int out;

	while(userinput==1)
	{
		printf("insert the value of out \n");
		scanf("%d", &out);

		out = out % 16;
		
		printf("after modulo we get the following, \n %d  \n", out);
		
		printf("continue? put 1 \n");
		scanf("%d", &userinput);
	}
}
