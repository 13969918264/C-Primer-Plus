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

#define SIZE 31			/*	the max size of the file name	*/
#define OFFSET 48			/*	number in ascii	*/

char * s_gets(char *, int);			/*	read a string with size given	*/
int display(int rows, int cols, char (*) [cols], FILE *);			/*	display the strings to a file	*/
int copy(int rows, int cols, char (*) [cols], int (*) [cols - 1]);				/*	copy a int array to a string	*/

int main(void)
{
	FILE * fpr, * fpw;
	int i, j;
	int rows, cols;
	char name[SIZE];
	char ch;

	/*	get number of row and columns to create VLA_array	*/
	puts("Enter the number of rows.");
	while (scanf("%d", &rows) != 1)
		fprintf(stderr, "Enter an integer");
	puts("Now enter the numbef of columns.");
	while (scanf("%d", &cols) != 1)
		fprintf(stderr, "Emter an integer");
	while (getchar() != '\n')
		continue;

	/*	write to a file	*/
	puts("Enter a name of a file which store the digitals generated by rand() function");
	s_gets(name, SIZE);
	if ((fpw = fopen(name, "w")) == NULL)			/*	with a comma, it is wrong	*/
	{
		fprintf(stderr, "Can't open %s as a write file.\n", name);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < rows * (cols - 1); i++)
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
	int digit[rows][cols - 1];

	if ((fpr = fopen(name, "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s as a read file.\n", name);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < rows; i++)
	{
		j = 0;
		while (j < cols - 1)
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
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols - 1; j++)
			printf("%d ", digit[i][j]);
		putchar('\n');
	}
	puts("Display all of the array!");

	/*	copy the digit to str	*/
	char str[rows][cols];

	copy(rows, cols, str, digit) ? fputs("\nSuccessfully copy.\n", stdout) : fputs("Bad luck", stderr);
	puts("Copy all of the array to a string.\n");

	/*	display str	*/
	puts("Display the string.");
	for (i = 0; i < rows; i++)
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
	display(rows, cols, str, fpw) ? fputs("Successfully display.\n", stdout) : fputs("Bad luck.\n", stderr);
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
int copy(int rows, int cols, char (* str)[cols], int (* digit)[cols - 1])
{
	int flag = 0;
	int i, j, num;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols - 1; j++)
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
		str[i][cols - 1] = '\0';
	}
	i == rows ? (flag = 1) : flag;			/*	Is it sensible?	*/

	return flag;
}



/*	display a picture which represented by strings to a file	*/
int display(int rows, int cols, char (* st) [cols], FILE * out)
{
	int flag = 0;
	int i;

	for  (i = 0; i < rows; i++, st++)
	{
		fputs(*st, out);
		putc('\n', out);
	}
	i == rows ? (flag = 1) : flag;

	return flag;
}