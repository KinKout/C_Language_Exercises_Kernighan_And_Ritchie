/*
* 
* File: 1.5.3_Line_Counting.cpp
* 
* Author: KinKout, kinkout@yahoo.com
* Date: 20-dec-2024
* Purpose: Practice character-by-character input handling and basic text processing.
* 
* 
* Exercise 1.8: Write a program to count blanks, tabs, and newlines.
* 
* Exercise 1.9: Write a program to copy its input to its output,
*				replacing each string of one or more blanks by a single blank.
* 
* Exercise 1.10: Write a program to copy its input to its output, replacing each tab by \t,
*				each backspace by \b, and each backslash by \\.
*				This makes tabs and backspaces visible in an unambiguous way
* 
* 
* Note: These exercises are based on examples from "The C Programming Language" by Kernighan and Ritchie,
*		but the code has been written independently as personal practice.
* 
*/


#include <stdio.h>


int main()
{
	printf("Simple line counting using getchar() until EOF:\n"
		"Type some text, press Enter for a new line and finally signal EOF to see the result.\n\n"
		"\t! To signal EOF (End Of File), press Ctrl+Z (Windows) or Ctrl+D (Linux/macOS) and then Enter !\n\n\n");

	// Count lines in input

	printf("Counting lines until EOF (press Ctrl+Z/Ctrl+D to see the result and move on to exercise 1.8).\n\n");

	int c, nl;

	c = 0;
	nl = 0;

	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;

	putchar('\n');

	if (nl <= 1)
		printf("In this file there is %d line.\n\n\n", nl);
	else
		printf("In this file there are %d lines.\n\n\n", nl);
	
	
	// Exercise 1.8: Write a program to count blanks, tabs, and newlines.

	printf("Exercise 1.8:\n"
		"\t\tWrite a program to count blanks, tabs, and newlines.\n\n"
		"\t\t(press Ctrl+Z/Ctrl+D to see the result and move on to exercise 1.9).\n\n");

	int bl, tb;

	c = 0;
	nl = 0;
	bl = 0;
	tb = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++bl;
		else if (c == '\t')
			++tb;
		else if (c == '\n')
			++nl;
	}

	putchar('\n');

	printf("In this file there are:"
		"\t%6i blank\n"
		"\t\t\t%6i tab\n"
		"\t\t\t%6i new line\n\n\n", bl, tb, nl);


	// Exercise 1.9: Write a program to copy its input to its output,
	//					replacing each string of one or more blanks by a single blank.

	printf("Exercise 1.9:\n"
		"\t\tWrite a program to copy its input to its output,\n"
		"\t\treplacing each string of one or more blanks by a single blank.\n\n"
		"\t\t(press Ctrl + Z / Ctrl + D to see the result and move on to exercise 1.10).\n\n");

	int bl_count;

	c = 0;
	bl_count = 0;

	while ((c = getchar()) != EOF)
	{
		if (c != ' ')
		{
			putchar(c);
			bl_count = 0;
		}
		else
		{
			++bl_count;
			if (bl_count == 1)
			{
				putchar(c);
			}
		}
	}

	putchar('\n');
	putchar('\n');

	
	// Exercise 1.10: Write a program to copy its input to its output, replacing each tab by \t,
	//					each backspace by \b, and each backslash by \\.
	//					This makes tabs and backspaces visible in an unambiguous way

	printf("Exercise 1.10:\n"
		"\t\tWrite a program to copy its input to its output, replacing each tab by \\t,\n"
		"\t\teach backspace by \\b, and each backslash by \\.\n"
		"\t\tThis makes tabs and backspaces visible in an unambiguous way\n\n"
		"\t\t(press Ctrl + Z / Ctrl + D to see the result and terminate the program).\n\n");

	c = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			c = '\\';
			putchar(c);
			c = 't';
			putchar(c);
		}

		// Note: '\b' (backspace) is usually not captured via keyboard input in standard terminals.
		// // This condition only works if the input contains the literal backspace character, e.g., from a file.

		else if (c == '\b') // getchar can't capture '\b' from keyboard
		{
			c = '\\';
			putchar(c);
			c = 'b';
			putchar(c);
		}

		else if (c == '\\')
		{
			c = '\\';
			putchar(c);
			putchar(c);
		}

		// Backspace ('\b') isn't reliably captured, so newline ('\n') and space (' ') are shown instead.

		else if (c == '\n')
		{
			c = '\\';
			putchar(c);
			c = 'n';
			putchar(c);
		}
			
		else if (c == ' ')
		{
			c = '_';
			putchar(c);
		}

		else
		{
			putchar(c);
		}
	}
	
	putchar('\n');
	putchar('\n');

	return 0;
}