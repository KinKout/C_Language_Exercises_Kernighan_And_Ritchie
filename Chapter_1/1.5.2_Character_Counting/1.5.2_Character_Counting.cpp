/*
* 
* File: 1.5.2_Character_Counting.cpp
* 
* Author: KinKout, kinkout@yahoo.com
* Date: 19-dec-2024
* Purpose: Learn how to count characters using getchar() and explore different loop structures.
* 
* Note: These exercises are based on examples from "The C Programming Language" by Kernighan and Ritchie,
*		but the code has been written independently as personal practice.
*/


#include <stdio.h>

int main()
{
	printf("Simple character counting using getchar() until EOF: ");
	printf("Type some text, then press Enter.\n\n");
	printf("\t! To signal EOF (end of input), press Ctrl+Z (Windows) or Ctrl+D (Linux/macOS) and then Enter !\n\n\n");

	// 1st version
	// Uses a while loop and an explicit counter.

	long nc;

	printf("1st version — counting until EOF (press Ctrl+Z/Ctrl+D to switch to the 2nd version).\n\n");

	nc = 0;
	while (getchar() != EOF)
		++nc;

	printf("Total characters counted: %ld\n\n", nc);


	// 2nd version
	// Uses a for loop for brevity.

	double nc2;

	printf("2nd version — counting until EOF.\n\n");

	for (nc2 = 0; getchar() != EOF; ++nc2)
		;

	printf("Total characters counted: %.0f\n", nc2);
}
