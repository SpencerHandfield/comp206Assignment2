
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void simpleRowPrint(int H, int index)
{
	//similar to simple diamond from part a, but based on arriving at L 1 and H with the current index
	int starCounter = (index*2) + 1; //add 2 stars on the sides per row
	int rowCounter = (H - index) - 1; //keep in mind which row at based on height
	for (int i = 0; i < rowCounter; i++)
	{
		printf(" "); // add spaces when needed
	}
	for (int j = 0; j < starCounter; j++) //based on row, print # of stars
	{
		printf("*");
	}
	for (int k = 0; k < rowCounter; k++) //print rest of spaces
	{
		printf(" ");
	}
}

void recursivePrint (int H, int L, int index) //recursive print based on H, L and the current row
{
	if (L == 1) //as per assignment restriction, print the simple row
	{
		simpleRowPrint(H, index); //pass the height of diamond and the current row index
	}
	else if (index < (H/2))
	{
		//print the spaces
		for (int i=0; i<(H/2); i++)
			printf(" ");
		//print the recursion based pattern again
		recursivePrint((H/2), (L-1), index);
		//fill rest of spaces
		for (int i=0; i<(H/2); i++)
			printf(" ");
	}
	else if (index >= (H/2))
	{
		//begin with recursive portion since still too large to determine pattern
		recursivePrint((H/2), (L-1), index-(H/2));
		printf(" ");//separate the separate recursion portions based on pattern
		recursivePrint((H/2), (L-1), index-(H/2));
	}
}


int main(int argc, char *argv[]) {

		//ensure correct arguments input
		if (argc != 3)
		{
			printf("ERROR: Wrong   of arguments. Two required.");
			return 0;
		}

		//declare variables
		int H;
		H = atoi(argv[1]);
		int L;
		L = atoi (argv[2]);

		//ensure proper height input
		if (H <= 0)
		{
			printf("ERROR: Bad argument. Height must be positive odd integer.");
			return 0;
		}
		//L check
		if (L <= 0)
		{
			printf("ERROR: Bad argument. Length must be positive integer");
			return 0;
		}

		//ensure proper L input based on height (assignment description)
		int tri_height = ceil(H/2);
		if ((tri_height%2) == 0 || (tri_height <= (2^(L-1))))
		{
			printf("ERROR: Height does not allow evenly dividing requested number of levels.");
			return 0;
		}
		//FIX H TO APPROPRIATE VALUE FOR TRIANGLES (not diamond!!)
		H = ((H/2)+1);
		for (int i = 0; i < H; i++) //print top of diamond, call recursion
		{
			recursivePrint(H, L, i); //call recursion
			printf("\n"); //
		}
		for (int i = (H-2); i >= 0; i--) //descending count starting from where top left on (took care of some rows)
		{
			recursivePrint(H, L, i); //initiate recursion
			printf("\n");
		}
}
