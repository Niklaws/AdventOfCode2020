#include <stdio.h>
#include <string.h>

#define NUM 613
#define BUFSIZE 128

int getInput(char input[NUM][BUFSIZE]);
int partOne(char input[NUM][BUFSIZE]);
int partTwo(char input[NUM][BUFSIZE]);

int main(int argc, char **argv)
{
	char input[NUM][BUFSIZE];
	getInput(input);
	partOne(input);
	partTwo(input);
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
}

int partOne(char input[NUM][BUFSIZE])
{
	int acc = 0;
	int pc = 0;
	char inst[BUFSIZE];
	int val;
	int visited[NUM];
	int nsinst;
	int csinst;
	int done = 0;
	for(int i=0; i<NUM; i++)
	{
		visited[i] = 0;
	}
	while(1)
	{
		visited[pc]++;
		if(visited[pc] == 2)
		{
			break;
		}
		sscanf(input[pc], "%s %d", inst, &val);
		if(strcmp(inst, "acc") == 0)
		{
			acc = acc + val;
			pc++;
		}
		else if(strcmp(inst, "jmp") == 0)
		{
			pc = pc + val;
		}
		else if(strcmp(inst, "nop") == 0)
		{
			pc++;
		}
	}
	printf("%d\n", acc);
}

int partTwo(char input[NUM][BUFSIZE])
{
	int acc = 0;
	int pc = 0;
	char inst[BUFSIZE];
	int val;
	int visited[NUM];
	int nsinst = 0;
	int csinst = 0;
	int done = 0;
	while(done == 0)
	{
		for(int i=0; i<NUM; i++)
		{
			visited[i] = 0;
		}
		while(1)
		{
			visited[pc]++;
			if(visited[pc] == 2)
			{
				printf("loop: %d\n", acc);
				break;
			}
			if(pc == NUM)
			{
				done = 1;
				printf("exited: %d\n", acc);
				break;
			}
			sscanf(input[pc], "%s %d", inst, &val);
			if(strcmp(inst, "acc") == 0)
			{
				acc = acc + val;
				pc++;
			}
			else if(strcmp(inst, "jmp") == 0 && nsinst != csinst)
			{
				pc = pc + val;
				csinst++;
			}
			else if(strcmp(inst, "jmp") == 0 && nsinst == csinst)
			{
				pc++;
				csinst++;
			}
			else if(strcmp(inst, "nop") == 0 && nsinst != csinst)
			{
				pc++;
				csinst++;
			}
			else if(strcmp(inst, "nop") == 0 && nsinst == csinst)
			{
				pc = pc + val;
				csinst++;
			}
		}
		nsinst++;
		csinst = 0;
		acc = 0;
		pc = 0;
	}
}