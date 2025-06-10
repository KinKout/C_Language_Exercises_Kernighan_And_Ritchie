/*
* 
* File: 1.4_Symbolic_Constants.cpp
* 
* Author: KinKout, kinkout@yahoo.com
* Date: 17-dec-2024
* Purpose: Fahrenheit to Celsius conversion table using symbolic constants (#define) to replace magic numbers
* 
*/


#include <stdio.h>

#define LOWER	0				// lower limit of table
#define UPPER	300				// upper limit
#define STEP	20				// step size
#define CONV_FACTOR (5.0/9.0)	// conversion factor
#define FREEZE_POINT 32			// freezing point of water

int main()
{
	int fahr;

	printf(" F\t   C\n");
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3i\t%6.1f\n", fahr, CONV_FACTOR * (fahr - FREEZE_POINT));

	printf("\n\n");

	fahr = UPPER;

	while (fahr >= LOWER)
	{
		printf("%3i\t%6.1f\n", fahr, CONV_FACTOR * (fahr - FREEZE_POINT));
		fahr = fahr - STEP;
	}
}
