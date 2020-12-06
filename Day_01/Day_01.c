#include <stdio.h>
#include <stdlib.h>

#define TARGET 2020
#define NUM 200

int getInput(int *input);
int findpair(int *inputs);
int findtriple(int *input);
int cmpfunc (const void * a, const void * b);

int main(int argc, char **argv)
{
	int input[NUM];
	getInput(input);
	qsort(input, NUM, sizeof(int), cmpfunc);
	findpair(input);
	findtriple(input);
}

int getInput(int *input)
{
	FILE *file = fopen("input", "r");
	char buf[16];
	for(int i=0; i<NUM; i++)
	{
		input[i] = atoi(fgets(buf, 16, file));
	}
	fclose(file);
	return 0;
}

int findpair(int *input)
{
	for(int i=0; i<NUM; i++)
	{
		for(int j=NUM-1; j>=0; j--)
		{
			if(input[i] + input[j] == TARGET)
			{
				printf("%d + %d\n", input[i], input[j]);
				printf("%d\n", input[i]*input[j]);
				return 0;
			}
		}
	}
}

int findtriple(int *input)
{
	for(int i=0; i<NUM; i++)
	{
		for(int j=0; j<NUM; j++)
		{
			for(int k=0; k<NUM; k++)
			{
				if(input[i] + input[j] + input[k] == TARGET)
				{
					printf("%d + %d + %d\n", input[i], input[j], input[k]);
					printf("%d\n", input[i] * input[j] * input[k]);
					return 0;
				}
			}
		}
	}
}

int cmpfunc (const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}