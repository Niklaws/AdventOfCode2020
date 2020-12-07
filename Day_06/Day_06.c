#include <stdio.h>
#include <string.h>

#define NUM 456
#define BUFSIZE 128

int getInput(char input[NUM][BUFSIZE]);
int partOne(char input[NUM][BUFSIZE]);
int partTwo(char input[NUM][BUFSIZE]);

int main(int argc, int **argv)
{
	char input[NUM][BUFSIZE];
	getInput(input);
	for(int i=0; i<NUM; i++)
	{
		printf("%s\n", input[i]);
	}
	partOne(input);
	partTwo(input);
	return 0;
}

int getInput(char input[NUM][BUFSIZE])
{
	FILE *file = fopen("input", "r");
	char buf[BUFSIZE];
	char tmp[BUFSIZE];
	for(int i=0; i<NUM; i++)
	{
		while(fgets(buf, BUFSIZE-1, file) != NULL && strcmp(buf, "\n") != 0)
		{
			strcat(tmp, buf);
		}
		strcpy(input[i], tmp);
		tmp[0] = '\0';
	}
	fclose(file);
	return 0;
}

int partOne(char input[NUM][BUFSIZE])
{
	int cnt = 0;
	for(int i=0; i<NUM; i++)
	{
		for(int j=97; j<=122; j++)
		{
			if(strchr(input[i], j) != NULL)
			{
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
}

int partTwo(char input[NUM][BUFSIZE])
{
	int c;
	int cnt = 0;
	for(int i=0; i<5; i++)
	{
		char *t = strchr(input[i], '\n');
		c = 0;
		while(t != NULL)
		{
			t++;
			c++;
			t = strchr(t, '\n');
		}

		char temp[c][BUFSIZE];
		t = input[i];
		printf("c: %d\n", c);
		for(int j=0; j<c; j++)
		{
			sscanf(t, "%s\n", temp[j]);
			t = strchr(t, '\n');
			t = t + 1;
			printf("%d: %s|\n", j, temp[j]);
		}
	}
	printf("%d\n", cnt);
}