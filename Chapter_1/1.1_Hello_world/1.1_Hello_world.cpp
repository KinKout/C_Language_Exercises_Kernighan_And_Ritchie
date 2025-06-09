/*
* 
* File: 1.1_Hello_world.cpp
* 
* Author: KinKout, kinkout@yahoo.com
* Date: 8-nov-2024
* Purpose: Introduction to C programming
* 
* Exercise 1.1: Run the ``hello, world'' program on your system. Experiment with leaving
*               out parts of the program, to see what error messages you get.
*
* Exercise 1.2: Experiment to find out what happens when prints's argument string contains
*               \c, where c is some character not listed above.
* 
* 
* Note: These exercises are based on examples from "The C Programming Language" by Kernighan and Ritchie,
*       but the code has been written independently as personal practice.
*/



#include <stdio.h>

int main()
{
    printf("hello, world\n");
    printf("\n");

    // Exercise 1.2: Experiment to find out what happens when prints's argument string contains
    //                  *\c, where c is some character not listed above.

    printf("hello\a");      // audible alert
    printf("world\b");      // backspace
    //printf("hello\c");
    //printf("world\d");
    //printf("hello\e");
    printf("world\f");      // from feed
    //printf("hello\g");
    //printf("world\h");
    //printf("hello\i");
    //printf("world\j");
    //printf("hello\k");
    //printf("world\l");
    //printf("hello\m");
    printf("world\n");      // newline
    //printf("hello\o");
    //printf("world\p");
    //printf("hello\q");
    printf("world\r");      // carriage return
    //printf("hello\s");
    printf("world\t");      // tab
    //printf("hello\u");
    printf("world\v");      // vertical tab
    //printf("hello\w");
    //printf("world\x");
    //printf("hello\y");
    //printf("world\z");

}
