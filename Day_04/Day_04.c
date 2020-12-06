#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 282
#define BUFSIZE 128

int getInput(char input[NUM][BUFSIZE]);
int partOne(char input[NUM][BUFSIZE]);
int partTwo(char input[NUM][BUFSIZE]);

int hgt_check(char *str);
int hcl_check(char *str);
int ecl_check(char *str);
int pid_check(char *str);

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
	char tmp[BUFSIZE];
	for(int i=0; i<NUM; i++)
	{
		while(fgets(buf, BUFSIZE-1, file) != NULL && strcmp(buf, "\n") != 0)
		{
			strcat(tmp, buf);
		}
		while(strchr(tmp, ' ') != NULL)
		{
			*strchr(tmp, ' ') = '\n';
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
		if(strstr(input[i], "byr") != NULL &&
			strstr(input[i], "iyr") != NULL &&
			strstr(input[i], "eyr") != NULL &&
			strstr(input[i], "hgt") != NULL &&
			strstr(input[i], "hcl") != NULL &&
			strstr(input[i], "ecl") != NULL &&
			strstr(input[i], "pid") != NULL)
		{
			cnt++;
		}
	}
	printf("valid pps: %d\n", cnt);
}

int partTwo(char input[NUM][BUFSIZE])
{
	int cnt = 0;
	char *byr, *iyr, *eyr, *hgt, *hcl, *ecl, *pid;//positions or NULL
	int tmp;
	for(int i=0; i<NUM; i++)
	{
		tmp = 1;
		if(strstr(input[i], "byr") != NULL &&
			strstr(input[i], "iyr") != NULL &&
			strstr(input[i], "eyr") != NULL &&
			strstr(input[i], "hgt") != NULL &&
			strstr(input[i], "hcl") != NULL &&
			strstr(input[i], "ecl") != NULL &&
			strstr(input[i], "pid") != NULL)
		{
			if(atoi(strstr(input[i], "byr")+4)<1920 || atoi(strstr(input[i], "byr")+4)>2001 ||
				atoi(strstr(input[i], "iyr")+4)<2010 || atoi(strstr(input[i], "iyr")+4)>2020 ||
				atoi(strstr(input[i], "eyr")+4)<2020 || atoi(strstr(input[i], "eyr")+4)>2030)
			{
				tmp = 0;
			}
			else if(hgt_check(strstr(input[i], "hgt")) == 0)
			{
				tmp = 0;
			}
			else if(hcl_check(strstr(input[i], "hcl")) == 0)
			{
				tmp = 0;
			}
			else if(ecl_check(strstr(input[i], "ecl")) == 0)
			{
				tmp = 0;
			}
			else if(pid_check(strstr(input[i], "pid")) == 0)
			{
				tmp = 0;
			}
			if(tmp)
			{
				cnt++;
			}
		}		
	}
	printf("new valid pps: %d\n", cnt);
}

int hgt_check(char *str)
{
	int h;
	char s[16];
	sscanf(str, "hgt:%d%s\n", &h, s);
	if(strcmp(s, "cm") == 0)
	{
		if(h<150 || h>193)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else if(strcmp(s, "in") == 0)
	{
		if(h<59 || h>76)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

int hcl_check(char *str)
{
	if(*(str+4) != '#')
	{
		return 0;
	}
	for(int i=5; i<11; i++)
	{
		if((*(str+i) < 48 || *(str+i) > 57) && (*(str+i) < 97 || *(str+i) > 102))
		{
			return 0;
		}
	}
	return 1;
}

int ecl_check(char *str)
{
	char tmp[16];
	sscanf(str, "ecl:%s", tmp);
	if(strcmp(tmp, "amb") == 0 ||
		strcmp(tmp, "blu") == 0 ||
		strcmp(tmp, "brn") == 0 ||
		strcmp(tmp, "gry") == 0 ||
		strcmp(tmp, "grn") == 0 ||
		strcmp(tmp, "hzl") == 0 ||
		strcmp(tmp, "oth") == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int pid_check(char *str)
{
	char tmp[16];
	int tmpi;
	sscanf(str, "pid:%s", tmp);
	if(strlen(tmp) == 9)
	{
		for(int i=0; i<9; i++)
		{
			if(tmp[i]>=48 && tmp[i]<=57)
			{
				return 1;
			}
		}
	}
	else
	{
		return 0;
	}
}