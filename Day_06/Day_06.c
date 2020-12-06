#include <stdio.h>

#define NUM 456

int getInput(char input[NUM][BUFSIZE]);

int main(int argc, int **argv)
{
	char input[NUM][BUFSIZE]
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