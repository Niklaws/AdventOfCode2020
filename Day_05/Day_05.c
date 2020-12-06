#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 805
#define BUFSIZE 12

int getInput(char input[NUM][BUFSIZE]);
int partOne(char input[NUM][BUFSIZE]);
int partTwo(int *input);
int cmpfunc (const void * a, const void * b);

int main(int argc, char **argv)
{
	char input[NUM][BUFSIZE];
	getInput(input);
	partOne(input);
	return 0;
}

int getInput(char input[NUM][BUFSIZE])
{
	FILE *file = fopen("input", "r");
	char buf[BUFSIZE];
	for(int i=0; i<NUM; i++)
	{
		strcpy(input[i], fgets(buf, BUFSIZE, file));
	}
	fclose(file);
	return 0;
}

int partOne(char input[NUM][BUFSIZE])
{
	int low, high;
	int row, col, id;
	int highest = 0;
	int output[NUM];
	for(int i=0; i<NUM; i++)
	{
		low = 0;
		high = 127;
		for(int j=0; j<7; j++)
		{
			if(input[i][j] == 'F')
			{
				high = (high-low) / 2 + low;
			}
			else if(input[i][j] == 'B')
			{
				low = (high-low) / 2 + 1 + low;
			}
		}
		row = low;
		low = 0;
		high = 7;
		for(int j=7; j<10; j++)
		{
			if(input[i][j] == 'L')
			{
				high = (high-low) / 2 + low;
			}
			else if(input[i][j] == 'R')
			{
				low = (high-low) / 2 + 1 + low;
			}
		}
		col = low;
		id = row * 8 + col;
		output[i] = id;
		if(highest<id)
		{
			highest = id;
		}
	}
	printf("highest id: %d\n", highest);
	partTwo(output);
}

int partTwo(int *input)
{
	qsort(input, NUM, sizeof(int), cmpfunc);
	int curid = input[0];
	for(int i=0; i<NUM; i++)
	{
		if(input[i] != curid)
		{
			printf("found it: %d\n", curid);
			break;
		}
		curid++;
	}
}

int cmpfunc (const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}