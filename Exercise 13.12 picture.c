/*
	Name: 赵子豪(ZiHao Zhao)
	Date: 2018年1月7日
*/
/*	picture.c -- use digitals to represent a picuture	*/
#include <stdio.h>
#include <string.h>			/*	strchr() prototype	*/
#include <stdlib.h>			/*	exit() prototpye	*/
#include <math.h>			/*	rand() prototype	*/
#include <ctype.h>

#define ROWS 20
#define COLS 31
#define SIZE 31			/*	the max size of the file name	*/
#define OFFSET 48			/*	number in ascii	*/

char * s_gets(char *, int);			/*	read a string with size given	*/
int display(char (*) [COLS], FILE *);			/*	display the strings to a file	*/
int copy(char (*) [COLS], int (*) [COLS - 1]);				/*	copy a int array to a string	*/

int main(void)
{
	FILE * fpr, * fpw;
	int i, j;
	int digit[ROWS][COLS - 1];
	char str[ROWS][COLS];
	char name[SIZE];
	char ch;

	/*	write to a file	*/
	puts("Enter a name of a file which store the digitals generated by rand() function");
	s_gets(name, SIZE);
	if ((fpw = fopen(name, "w")) == NULL)			/*	with a comma, it is wrong	*/
	{
		fprintf(stderr, "Can't open %s as a write file.\n", name);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < ROWS * (COLS - 1); i++)
	{
		if (i != 0 && i % 30 == 0)
			putc('\n', fpw);
		fprintf(fpw, "%d ", rand() % 10);
	}
	puts("\nWrite all into the file!\n");
	if (fclose(fpw) != 0)
		fprintf(stderr, "Error closing file.\n");

	/*	display the content of the file	*/
	puts("Display the file.\n");
	if ((fpr = fopen(name, "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s.\n", name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fpr)) != EOF)
		putc(ch, stdout);
	puts("\nDisplay all of the file!\n");
	if (fclose(fpr) != 0)
		fputs("Error closing file.\n", stderr);

	/*	read a file to a array	*/
	if ((fpr = fopen(name, "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s as a read file.\n", name);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < ROWS; i++)
	{
		j = 0;
		while (j < COLS - 1)
		{
			if((ch = getc(fpr)) != EOF && isdigit(ch))
				digit[i][j] = ch - OFFSET;
			else
				continue;
			j++;
		}
	}
	puts("Read all of the file into an array!\n");
	if (fclose(fpr) != 0)
		fprintf(stderr, "Error closing file.\n");

	/*	display array */
	puts("Display digital array");
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS - 1; j++)
			printf("%d ", digit[i][j]);
		putchar('\n');
	}
	puts("Display all of the array!");

	/*	copy the digit to str	*/
	copy(str, digit) ? fputs("\nSuccessfully copy.\n", stdout) : fputs("Bad luck", stderr);
	puts("Copy all of the array to a string.\n");

	/*	display str	*/
	puts("Display the string.");
	for (i = 0; i < ROWS; i++)
		puts(str[i]);
	puts("Display all of the string.\n");

	/*	display the picture in a text	*/
	puts("Enter the name of file which store the picture.");
	s_gets(name, SIZE);
	if ((fpw = fopen(name, "wb")) == NULL)
	{
		fprintf(stderr, "Can't open %s as a write file.\n", name);
		exit(EXIT_FAILURE);
	}
	display(str, fpw) ? fputs("Successfully display.\n", stdout) : fputs("Bad luck.\n", stderr);
	if (fclose(fpw) != 0)
		fprintf(stderr, "Error closing file.\n");

	/*	Display the picture file	*/
	puts("\nDisplay the file.");
	if ((fpr = fopen(name, "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s.\n", name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fpr)) != EOF)
		putc(ch, stdout);
	puts("Display all of the file!");
	if (fclose(fpr) != 0)
		fputs("Error closing file.\n", stderr);

	return 0;
}



/*	read a string	*/
char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		if (find = strchr(st, '\n'))
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}



/*	copy a int array to a sring	*/
int copy(char (* str)[COLS], int (* digit)[COLS - 1])
{
	int flag = 0;
	int i, j, num;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS - 1; j++)
		{
			num = digit[i][j];
			switch(num)
			{
				case 0 :
						str[i][j] = ')';
						break;
				case 1 :
						str[i][j] = '!';
						break;
				case 2 :
						str[i][j] = '@';
						break;
				case 3 :
						str[i][j] = '#';
						break;
				case 4 :
						str[i][j] = '$';
						break;
				case 5 :
						str[i][j] = '%';
						break;
				case 6 :
						str[i][j] = '^';
						break;
				case 7 :
						str[i][j] = '&';
						break;
				case 8 :
						str[i][j] = '*';
						break;
				case 9 :
						str[i][j] = '(';
						break;
			}
		}
		str[i][COLS - 1] = '\0';
	}
	i == ROWS ? (flag = 1) : flag;

	return flag;
}



/*	display a picture which represented by strings to a file	*/
int display(char (* st) [COLS], FILE * out)
{
	int flag = 0;
	int i;

	for  (i = 0; i < ROWS; i++, st++)
	{
		fputs(*st, out);
		putc('\n', out);
	}
	i == ROWS ? (flag = 1) : flag;

	return flag;
}
