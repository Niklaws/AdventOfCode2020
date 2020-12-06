#include <stdio.h>

#define NUM 1000

struct line
{
	int low;
	int high;
	char c;
	char passwd[64];
};

int getInput(struct line *l);
int count(char c, char *str);
int part_1(struct line *l);
int part_2(struct line *l);

int main(int argc, char **argv)
{
	struct line line[NUM];
	getInput(line);
	part_1(line);
	part_2(line);
	return 0;
}

int getInput(struct line *l)
{
	FILE *file = fopen("input", "r");
	char buf[64];
	for(int i=0; i<NUM; i++)
	{
		fgets(buf, 64, file);
		sscanf(buf, "%d-%d %c: %s", &l[i].low, &l[i].high, &l[i].c, l[i].passwd);
	}
	fclose(file);
	return 0;
}

int count(char c, char *str)
{
	int count = 0;
	for(int i=0; str[i]; i++)
	{
		count += (str[i] == c);
	}
	return count;
}

int part_1(struct line *l)
{
	int tmp;
	int cnt = 0;
	for(int i=0; i<NUM; i++)
	{
		tmp = count(l[i].c, l[i].passwd);
		if(tmp<=l[i].high && tmp>=l[i].low)
		{
			cnt++;
		}
	}
	printf("%d passwords are valid\n", cnt);
	return 0;
}

int part_2(struct line *l)
{
	int cnt = 0;
	for(int i=0; i<NUM; i++)
	{
		if((l[i].passwd[l[i].low-1] == l[i].c) != (l[i].passwd[l[i].high-1] == l[i].c))
		{
			cnt++;
		}
	}
	printf("%d passwords are valid\n", cnt);
	return 0;
}