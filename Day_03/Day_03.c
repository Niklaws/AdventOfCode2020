#include <stdio.h>
#include <string.h>

#define NUM 323
#define BUFSIZE 32

int getInput(char input[NUM][BUFSIZE]);
int find(char input[NUM][BUFSIZE], int x, int y);
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
	char buf[BUFSIZE+1];
	for(int i=0; i<NUM; i++)
	{
		strncpy(input[i], fgets(buf, BUFSIZE+1, file), BUFSIZE-1);
	}
	fclose(file);
	return 0;
}

int find(char input[NUM][BUFSIZE], int ax, int ay)
{
	int cnt = 0;
	int x = 0;
	int y = 0;
	while(y<NUM)
	{
		x = (x + ax) % (BUFSIZE-1);
		y = y + ay;
		if(input[y][x] == '#')
		{
			cnt++;
		}
	}
	return cnt;
}

int partOne(char input[NUM][BUFSIZE])
{
	int result = find(input, 3, 1);
	printf("%d\n", result);
}

int partTwo(char input[NUM][BUFSIZE])
{
	long result = (long)find(input, 1, 1) * (long)find(input, 3, 1) * (long)find(input, 5, 1) * (long)find(input, 7, 1) * (long)find(input, 1, 2);
	printf("%ld\n", result);
}