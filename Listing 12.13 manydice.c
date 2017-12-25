/*
	Name: 赵子豪(ZiHao Zhao)
	Date: 2017年12月13日
*/
/*	manydice.c -- mutiple dice rolls	*/
/*	compile with diceroll.c	*/
#include <stdio.h>
#include <stdlib.h>			/*	for library srand()	*/
#include <time.h>			/*	for time()	*/
#include "diceroll.h"			/*	for roll_n_dice()	*/
/*	and for roll_count	*/
int main(void)
{
	int dice, roll;
	int sides;

	srand((unsigned int) time(0));			/*	randomize seed	*/
	printf("Enter  the number of sides per die, 0 to stop.\n");
	while (scanf("%d", &sides) == 1 && sides > 0)
	{
		int status;

		printf("How many dices!\n");
		if (( status = scanf("%d", &dice)) != 1)
		{
			if (status == EOF)
				break;
			else
			{
				printf("You should have entered an integer.");
				printf(" Let's begin again.\n");
				while (getchar() != '\n')
					continue;			//	dispose of bad input
				printf("How many sides? Enter 0 to stop.\n");
				continue;			/*	new loop cycle	*/
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("You have rolled a %d using %d %d_sides dice.\n", roll, dice, sides);
		printf("How many sides? Enter 0 to stop.\n");
	}
	printf("The rollem() function was called %d times\n",
			roll_count);			/*	use extern variable	*/
	printf("GOOD FORTUNE TO YOU!\n");

	return 0;
}