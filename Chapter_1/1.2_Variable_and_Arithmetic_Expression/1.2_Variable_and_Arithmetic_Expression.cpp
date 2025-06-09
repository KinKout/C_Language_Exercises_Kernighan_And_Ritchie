/*
* 
* File: 1.2_Variable_and_Arithmetic_Expression.cpp
* 
* Author: KinKout, kinkout@yahoo.com
* Date: 9-nov_2024
* Purpose: The program uses the formula C=(5/9)(F-32) to print the a table of Fahrenheit
*			temperatures and their centigrade or Celsius equivalents.
* 
* Exercise 1.3: Modify the temperature conversion program to print a heading above the table.
* 
* Exercise 1.4: Write a program to print the corresponding Celsius to Fahrenheit table.
*
*
* Note: These exercises are based on examples from "The C Programming Language" by Kernighan and Ritchie,
*		but the code has been written independently as personal practice.
*/


#include <stdio.h>

int main()
{
	float fahr, celsius;
	float lower, upper, step;
	float celsius_max;
	float celsius_min;

	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;


	// Exercise 1.3: Modify the temperature conversion program to print a heading above the table.

	printf("This table show the conversion from Fahrenheit to Celsius\n\n");
	printf("    F\t   C\n");

	while (fahr <= upper)
	{
		celsius = (5.0f / 9.0f) * (fahr - 32.0f);
		printf("%6.0f\t%6.1f\n", fahr, celsius);
		if (fahr == 0)
		{
			celsius_min = celsius;
		}

		fahr = fahr + step;
	}

	printf("\n");


	// Exercise 1.4: Write a program to print the corresponding Celsius to Fahrenheit table.

	celsius_max = celsius;
	celsius = celsius_min;
	step = 5;

	printf("This table show the conversion from Celsius to Fahrenheit\n\n");
	printf("   C\t\t F\n");

	while (celsius <= celsius_max)
	{
		fahr = (celsius) / (5.0f / 9.0f) + 32.0f;
		printf("%6.1f\t\t%3.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
}