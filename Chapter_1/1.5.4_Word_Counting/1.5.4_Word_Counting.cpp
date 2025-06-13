/*
* 
* File:		1.5.4_Word_Counting.cpp
* 
* Author:	KinKout, kinkout@yahoo.com
* Date:		03-Jan-2025
* 
* Purpose: Count the number of lines, words, and characters in the input.
*          A word is considered as any sequence of characters separated by spaces, tabs, or newlines.
* 
* 
* Exercise 1.11:	How would you test the word count program?
*					What kinds of input are most likely to uncover bugs if there are any?
* 
* Exercise 1.12:	Write a program that prints its input one word per line.
* 
* 
* Note: These exercises are based on examples from "The C Programming Language" by Kernighan and Ritchie,
*		but the code has been written independently as personal practice.
* 
*/


#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0


int main()
{
	printf("Simple lines, words and characters counting using getchar() until EOF:\n"
		"Type some text, press Enter for a new line and finally signal EOF to see the result.\n\n"
		"\t! To signal EOF (End Of File), press Ctrl+Z (Windows) or Ctrl+D (Linux/macOS) and then Enter !\n\n\n");

	// count lines, words and characters in input

	printf("Counting until EOF (press Ctrl+Z/Ctrl+D to see the result and move on to exercise 1.11).\n\n");

	int c, nl, nw, nc, state;
	char s;

	state = OUT_WORD;
	nl = nw = nc = s = 0;

	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT_WORD;
		else if (state == OUT_WORD)
		{
			state = IN_WORD;
			++nw;
		}
	}

	printf("In your input there are:");

	s = (nl == 1) ? '\0' : 's';
	printf("%6i new line%c\n", nl, s);
	s = (nw == 1) ? '\0' : 's';
	printf("\t\t\t%6i word%c\n", nw, s);
	s = (nc == 1) ? '\0' : 's';
	printf("\t\t\t%6i character%c\n\n\n", nc, s);


	// Exercise 1.11:	How would you test the word count program?
	//					What kinds of input are most likely to uncover bugs if there are any?
	 
	 printf("Exercise 1.11:\tHow would you test the word count program?\n"
		 "\t\tWhat kinds of input are most likely to uncover bugs if there are any?\n\n");

	 printf("To properly test the word count program, I would use the following input cases:\n"
		 "- Normal text with words separated by single spaces.\n"
		 "- Text with multiple consecutive spaces, tabs, or newlines between words.\n"
		 "- Empty input or input containing only whitespace characters.\n"
		 "- A single word without any separators.\n"
		 "- Text starting or ending with whitespace characters.\n"
		 "- Mixed input with letters, numbers, and punctuation (e.g., hello, world!123).\n"
		 "- Very long input to test program stability.\n"
		 "- Input with only newlines (empty lines).\n\n"
		 "Edge cases that might reveal bugs:\n"
		 "- Input where EOF occurs immediately after whitespace vs. after a word.\n"
		 "- Unicode or extended ASCII input, which may not be handled correctly.\n\n"
		 "These test cases help verify the state transitions between 'inside a word'\n"
		 "and 'outside a word', which is the core logic of the program.\n\n");

	printf("(press Ctrl+Z/Ctrl+D to move on to exercise 1.12).\n");

	while (getchar() != EOF);

	printf("\n\n\n");


	// Exercise 1.12:	Write a program that prints its input one word per line.

	printf("Exercise 1.12:\tWrite a program that prints its input one word per line.\n"
		"\t\t(press Ctrl + Z / Ctrl + D to terminate the program).\n\n");

	bool in_blank;

	c = 0;
	in_blank = false;

	while ((c = getchar()) != EOF)
	{
		if ((c == ' ' || c == '\t' || c == '\n') && in_blank)
		{
			continue;
		}
		else
		{
			if (c == ' ' || c == '\t' || c == '\n')
			{
				in_blank = true;
				c = '\n';
				putchar(c);
				continue;
			}
			else
			{
				putchar(c);
				in_blank = false;
			}
		}
	}

	return 0;
}