/*
* File: 1.5.1_File_Copying.cpp
* 
* Author: KinKout, kinkout@yahoo.com
* Date: 19-dec-2024
* Purpose: learn getchar(), putchar() & File copying untill EOF (End Of File)
* 
* Exercise 1.6: Verify that the expression getchar() != EOF is 0 or 1.
* 
* Exercise 1.7: Write a program to print the value of EOF.
* 
* 
* Note: These exercises are based on examples from "The C Programming Language" by Kernighan and Ritchie,
*		but the code has been written independently as personal practice.
*/


#include <stdio.h>

int main()
{
	printf("Simple file copy using getchar() and putchar(): ");
	printf("Type some text, then press Enter.\n\n");
	printf("\t! To signal EOF (end of input), press Ctrl+Z (Windows) or Ctrl+D (Linux/macOS) and then Enter !\n\n\n");

	// 1st version
	// Read a character before the loop and keep reading until c is EOF.
	// This version has an explicit read at the top and bottom of the loop.

	int c;

	printf("1st version — reading until EOF (press Ctrl+Z/Ctrl+D to switch to the 2nd version).\n\n");

	c = getchar();
	while (c != EOF)
	{
		putchar(c);
		c = getchar();
	}


	// 2nd version
	// Read and test in one line using assignment in the condition.
	// More compact and commonly used in practice.

	c = 0;

	printf("2nd version — reading until EOF (press Ctrl+Z/Ctrl+D to switch to the exercise 1.6).\n\n");

	while ((c = getchar()) != EOF)
		putchar(c);


	// Exercise 1.6: Verify that the expression getchar() != EOF is 0 or 1.

	c = 0;
	int expression;

	printf("Exercise 1.6: Verify that the expression getchar() != EOF is 0 or 1.\n\n");

	while ((expression = ((c = getchar()) != EOF)) == 1)
	{
		printf("\n\texpression = %i\t\t", expression);
		putchar(c);
	}

	printf("\n expression = %i\n\n", expression);


	// Exercise 1.7: Write a program to print the value of EOF.

	c = 0;
	int EOF_value = 0;

	printf("Exercise 1.7: Write a program to print the value of EOF.\n\n");

	while ((c = getchar()) != EOF)
	{
		EOF_value = EOF;
		printf("\n\tEOF value = %i\t", EOF_value);
		putchar(c);
	}

	printf("\n\tEOF value = %i\n", EOF_value);
}