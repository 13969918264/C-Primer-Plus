/*
	Name: 赵子豪
	Date: 2017年6月16号
*/



//	talkback.c -- nosy, iformative program
#include <stdio.h>
#include <string.h>			//	for strlen() prototype
#define DENSITY 62.4			//	human dessity in lbs per cu ft
int main()
{
	float weight, volume;
	int size, letters;
	char name[40];			//	name is an array of 40 chars

	printf("Hi! what's your name?\n");
	scanf("%s", name);
	printf("%s, what's your weight in pounds?\n", name);
	scanf("%f", &weight);			// You must write the char & in front of the variable
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
	printf("Also, your first name has %d letters,\n", letters);
	printf("and we have %d bytes to store it.\n", size);

	return 0;
}
