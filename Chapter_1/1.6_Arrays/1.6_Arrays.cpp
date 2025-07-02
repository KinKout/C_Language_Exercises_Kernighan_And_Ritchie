/*
*
* File:		1.6_Arrays.cpp
*
* Author:	KinKout, kinkout@yahoo.com
* Date:		14-Jan-2024
*
* Purpose:	Count the occurrences of digits, whitespace characters
*			(blank, tab, newline), and of all other characters.
*
*
* Exercise 1.13:	Write a program to print a histogram of the lengths of words in its input.
*					It is easy to draw the histogram with the bars horizontal;
*					a vertical orientation is more challenging.
*
* Exercise 1.14:	Write a program to print a histogram of the frequencies of different characters
*					in its input.
*
*
* Note:	These exercises are based on examples from "The C Programming Language" by Kernighan and Ritchie,
*		but the code has been written independently as personal practice.
*/


#include <stdio.h>
#include <stdbool.h>

#define MAX_WORD_LEN 20 
#define MAX_WORDS 20
#define MAX_CHAR 128


int main()
{
	puts( "Simple character frequency and histogram using getchar() until EOF:\n"
		  "Type some text, press Enter for a new line and finally signal EOF to see the result.\n\n"
		  "\t! To signal EOF (End Of File), press Ctrl+Z (Windows) or Ctrl+D (Linux/macOS) and then Enter !\n\n" );
	
	// Count digits, whitespace (space, tab, newline), and other characters

	puts( "Counting until EOF (press Ctrl+Z/Ctrl+D to see the result and move on to exercise 1.13).\n" );

	int c, n_white, n_other;
	int n_digit[10];

	n_white = n_other = 0;

	for( int i = 0; i < 10; ++i )
		n_digit[i] = 0;
	while( (c = getchar()) != EOF )
		if( c >= '0' && c <= '9' )
			++n_digit[c - '0'];
		else if( c == ' ' || c == '\n' || c == '\t' )
			++n_white;
		else
			++n_other;

	printf( "\n%16s| n", "digits" );

	for( int i = 0; i < 10; i++ )
	{
		printf( " %3d", i );
	}

	printf( "\n%16s| =", "frequency" );

	for( int i = 0; i < 10; ++i )
		printf( " %3d", n_digit[i] );

	puts( "\n_____________________________________________________________\n" );

	printf( "%16s  = %3d\n", "white spaces", n_white );
	printf( "%16s  = %3d\n", "others", n_other );

	puts( "_____________________________________________________________\n\n" );


	// Exercise 1.13:	Write a program to print a histogram of the lengths of words in its input.
	//					It is easy to draw the histogram with the bars horizontal;
	//					a vertical orientation is more challenging.

	puts( "Exercise 1.13:\tWrite a program to print a histogram of the lengths of words in its input.\n"
		  "\t\tIt is easy to draw the histogram with the bars horizontal;\n"
		  "\t\ta vertical orientation is more challenging.\n" );

  // Horizontal histogram

	puts( "Horizontal histogram, MAX WORD LENGTH 20 characters.\n" );
	puts( "Type some text, press ENTER to see horizontal histograms (press Ctrl+Z / Ctrl+D to move on to vertical exercise):\n" );

	int c2;
	char word[MAX_WORD_LEN];
	int word_len;
	bool in_word;

	c2 = 0;
	word_len = 0;
	in_word = false;

	for( int i = 0; i < MAX_WORD_LEN; i++ )
		word[i] = '\0';

	while( (c2 = getchar()) != EOF )
	{
		if( (c2 == ' ' || c2 == '\t' || c2 == '\n') && !in_word )
		{
			continue;
		}
		else
		{
			if( c2 == ' ' || c2 == '\t' || c2 == '\n' )
			{
				word[word_len] = '\0';

				printf( "\n%20s\t", word );

				while( word_len != 0 )
				{
					putchar( '*' );
					--word_len;
				}

				for( int i = 0; i < MAX_WORD_LEN; i++ )
					word[i] = '\0';

				if( c2 == '\n' )
					puts( "\n" );

				in_word = false;
				continue;
			}
			else
			{
				if( word_len >= MAX_WORD_LEN - 1 )
					continue;

				word[word_len++] = c2;
				in_word = true;
			}
		}
	}

	// Vertical histogram

	puts( "\n\nVertical histogram, MAX WORD LENGTH 20 characters, MAX WORDS 20 words.\n" );
	puts( "Type some text (press Ctrl+Z / Ctrl+D to see vertical histograms and move on to exercise 1.14):\n" );

	int c3;
	int k;
	char word2[MAX_WORD_LEN] = { 0 };
	int word_len2;
	char words[MAX_WORDS][MAX_WORD_LEN] = { 0 }; // [0] = position counter - [1] = word
	int words_len[MAX_WORD_LEN] = { 0 };
	int words_count;
	int max_letter_count;
	bool in_word2;

	c3 = k = 0;
	word_len2 = 0;
	max_letter_count = 0;
	words_count = 0;
	in_word2 = false;

	for( int i = 0; i < MAX_WORD_LEN; i++ )
		word2[i] = '\0';

	while( (c3 = getchar()) != EOF )
	{
		if( (c3 == ' ' || c3 == '\t' || c3 == '\n') && !in_word2 )
		{
			continue;
		}
		else
		{
			if( c3 == ' ' || c3 == '\t' || c3 == '\n' )
			{
				word2[word_len2] = '\0';

				k = 0;
				while( word2[k] != '\0' )
				{
					words[words_count][k] = word2[k++];
				}
				words[words_count][k] = '\0';

				words_len[words_count] = word_len2;

				if( word_len2 > max_letter_count )
					max_letter_count = word_len2;

				k = 0;
				while( word2[k] != '\0' )
					word2[k++] = '\0';

				if( c3 == '\n' )
					putchar( '\n' );

				word_len2 = 0;
				words_count++;
				in_word2 = false;
				continue;
			}
			else
			{
				if( (word_len2 >= MAX_WORD_LEN - 1)
					|| (words_count >= MAX_WORDS - 1) )
					continue;

				word2[word_len2++] = c3;
				in_word2 = true;
			}
		}
	}

	puts( "\n" );

	for( int i = max_letter_count; i > 0; i-- )
	{
		for( int j = 0; j < words_count; j++ )
		{
			if( words_len[j] >= i )
			{
				fputs( "  *  ", stdout );
				continue;
			}
			fputs( "     ", stdout );
		}
		putchar( '\n' );
	}

	for( int i = 0; i < words_count; i++ )
		fputs( "-----", stdout );

	putchar( '\n' );

	for( int i = 0; i < max_letter_count; i++ )
	{
		for( int j = 0; j < words_count; j++ )
		{
			if( words[j][i] == '\0' )
			{
				fputs( "     ", stdout );
				continue;
			}
			printf( "  %c  ", words[j][i] );
		}
		putchar( '\n' );
	}


	// Exercise 1.14:	Write a program to print a histogram of the frequencies of different characters
	//					in its input.

	puts( "\n\nExercise 1.14:\tWrite a program to print a histogram of the frequencies of different characters in its input.\n" );

	puts( "Type some text (press Ctrl+Z / Ctrl+D to see the frequencies histogram and terminate the program):\n" );

	int c4;
	int c_count;
	char ASCII_char[MAX_CHAR] = { 0 };
	char c_symbol[6] = { 0 };
	char s;

	c4 = 0;
	c_count = 0;
	s = '\\';

	while( (c4 = getchar()) != EOF )
	{
		++ASCII_char[c4];
	}

	puts( "\nDEC\tSYMBOL\tCOUNT" );

	for( int i = 0; i < MAX_CHAR; i++ )
	{
		if( ASCII_char[i] == 0 )
			continue;

		c_count = ASCII_char[i];

		for( int j = 0; j < 5; j++ )
		{
			c_symbol[j] = '\0';
		}

		c_symbol[0] = i;

		if( i < 32 )
		{
			switch( c_symbol[0] )
			{
				case '\0': c_symbol[0] = s; c_symbol[1] = '0'; break;
				case '\a': c_symbol[0] = s; c_symbol[1] = 'a'; break;
				case '\b': c_symbol[0] = s; c_symbol[1] = 'b'; break;
				case '\t': c_symbol[0] = s; c_symbol[1] = 't'; break;
				case '\n': c_symbol[0] = s; c_symbol[1] = 'n'; break;
				case '\v': c_symbol[0] = s; c_symbol[1] = 'v'; break;
				case '\f': c_symbol[0] = s; c_symbol[1] = 'f'; break;
				case '\r': c_symbol[0] = s; c_symbol[1] = 'r'; break;
				default: c_symbol; break;
			}
			c_symbol[2] = '\0';
		}
		else if( i == 32 )
		{
			for( int j = 0; j < 5; j++ )
			{
				char str[] = "SPACE";
				c_symbol[j] = str[j];
			}
			c_symbol[5] = '\0';
		}

		printf( "#%3i:\t%s\t", i, c_symbol );

		for( int k = 0; k < ASCII_char[i]; k++ )
		{
			putchar( '*' );
		}

		putchar( '\n' );
	}

	return 0;
}

