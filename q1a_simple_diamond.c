/*
 ============================================================================
 Name        : q1a_simple_diamond.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	//if isnt exactly just calling the program and giving the single argument
	if (argc != 2)
	{
		printf("ERROR: Wrong   of arguments. One required.");
		return 0;
	}

	//gettting the input from the command line as an integer
	int input;
	input = atoi(argv[1]);

	//if the number is negative or not odd
	if (input <= 0 || (input % 2) == 0)
	{
		printf("ERROR: Bad argument. Height must be positive odd integer.");
		return 0;
	}

	//variables
	int  i;
	int j;
	int rowCounter;
	//since we want the for loop to terminate at the HALF of the count (fills up util half, empties out until after that)
	//will require 2 nested for loops (as seen in the single nested loop in tut)
	//the for loops must complete at the half way of the input to ensure diamond shape
	//one loop will handle the middle row being full thanks to
	input = (input/2)+1;

	//a count to keep track of how far into the row the * should appear, (from left so only decreases by 1 each iteration)
	rowCounter = input;

	    for (j=0; j<input; j++)//handles the row, only doing half the diamond until middle with reduced input
	    {
	        for (i=0; i<rowCounter; i++)//prints appropriate amounts of spaces until right before *
	        {
	            printf(" ");
	        }

	        for (i=0; i<(j*2)-1; i++)//prints appropriate amount of *, depending on row, increasing by 2 each time, starting by 1
	        {
	        printf("*");
	        }
	        //decrease count until beginning of * on next line (ref from left)
	        rowCounter--;
	        printf("\n");
	     }

	    //reset count to do bottom "triangle"
	    //signifies the distance from left asterisks start (first 1 is ignored for middle line)
	    rowCounter = 0;

	     for (j=0; j<input; j++)//handles lower HALF of diamond
	     {

	         for (i=0; i<rowCounter; i++)//prints appropriate spaces from correct distance of left, based on row counter
	         {
	             printf(" ");
	         }

	         for (i=0 ; i<((input-j)*2)-1; i++)//prints asterisk, starting at max (input) decreasing by 2 every time
	         {
	        	 printf("*");
	         }

	         rowCounter++; //increases count as * get further away from left
	         printf("\n");
	      }
	      return 0;

}
