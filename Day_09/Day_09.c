#include <stdio.h>
#include <stdlib.h>

#define NUM 1000

int getInput(long *input);
int partOne(long *input);

int main(int argc, char **argv)
{
	long input[1000];
	getInput(input);
	partOne(input);
	return 0;
}

int getInput(long *input)
{
	FILE *file = fopen("input", "r");
	char buf[64];
	for(long i=0; i<NUM; i++)
	{
		fgets(buf, 64, file);
		input[i] = atol(buf);
	}
	fclose(file);
	return 0;
}

int partOne(long *input)
{
	int valid = 0;
	for(int i=25; i<NUM; i++)
	{
		valid = 0;
		for(int j=i-25; j<i && valid==0; j++)
		{
			for(int k=i-25; k<i && valid==0; k++)
			{
				if(input[j] + input[k] == input[i])
				{
					valid = 1;
				}
			}
		}
		if(valid == 0)
		{
			printf("invalid number detected: %ld\n", input[i]);
		}
	}
}