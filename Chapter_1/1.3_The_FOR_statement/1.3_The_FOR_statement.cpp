/*
* 
* File: 1.3_PLEx The FOR statement.cpp
* 
* Author: KinKout, kinkout@yahoo.com
* Date: 17-dec-2024
* Purpose: The FOR statement is a loop, a generalization of the while.
* 
* Exercise 1.5: Modify the temperature conversion program to print the table in reverse order, that is,
*				from 300 degrees to 0.
* 
* Note: These exercises are based on examples from "The C Programming Language" by Kernighan and Ritchie,
*		but the code has been written independently as personal practice.
*/


#include <stdio.h>

int main()
{
	int fahr;

	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%3i %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	printf("\n\n");


	//Exercise 1.5: Modify the temperature conversion program to print the table in reverse order, that is,
	//				from 300 degrees to 0.

	for (fahr = 300; fahr >= 0; fahr = fahr - 20)
	{
		printf("%3i %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
	}
}
