
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

	//ensure proper arguments
	if(argc != 2)
	{
		printf("ERROR: improper arguments.");
		return 0;
	}
	//create file to read into
	FILE *file = fopen(argv[1], "r");
	//ensure legible file
	if (file == NULL)
	{
		printf("ERROR: incorrect webpage");
		return 0;
	}
	//determine length of file in chars based on notes
	int count;
	fseek (file, 0, SEEK_END);
	count = ftell(file);
	rewind(file);

	//printf("%d", count);
	//create an array the size of the file
	char content[count+1];
	//read the entire file into the new array
	fread(content, 1, count+1, file);
	//initialize the end of the array to marker \0 since fread doesnt automatically
	content[count] = '\0';
	//create an entry point to the array for further utility and to keep track of location
	char *point = content;
	//scan through the entire array of chars (all the content in the page)
	while (point != NULL)
	{
		//find the appropriate beginning of the links
		point = strstr(point, "<a href=\"/wiki/");
		//if there are no links, break
		if (point == NULL)
		{
			break;
		}
		//now with link found, isolate the chars to print with pointers at beginning and end of sequence
		char *titleSequenceBeginning = strstr(point, "title=\""); //pointer to begining of title
		char *titleSequenceFinish = strstr(titleSequenceBeginning, "\">"); //pointer to end of title sequence
		//must use from titleSequenceBeginning since point will detect the \" from the latter first, so set problem area as starting point to avoid error
		char *finish = strstr(point, "</a>"); //pointer to end of hyperlink
		int lengthToTitle =  titleSequenceBeginning - point; //distance to title start
		int lengthHyperlink = finish - point; //size of the entire sequence is the difference
		//the 1 bit chars stored in continuous memory

		if(lengthToTitle < lengthHyperlink) //ensure that the title is actually within said hyperlink
		{

			//acquire the length of the page title
			//measured from end of title declaration to the end of title sequence
			char *endTitleDeclaration = strstr (titleSequenceBeginning, "\"");
			int pageNameLength = titleSequenceFinish - endTitleDeclaration;
			//fill array of the size of the title with the chars
			char pageName[pageNameLength+1];
			//copy in the string
			//numbers tested to adjust for printing 1 out of bounds
			strncpy(pageName, endTitleDeclaration+1, pageNameLength-1);
			//add the end of the array declaration since starts at 0, one more spot empty
			pageName[pageNameLength] = '\0';

			//print the title with separation
			printf("%s\n", pageName);
		}
		//skip over the beginning of the hyperlink sequence in the data array to begin looking for the next
		point = point + 15;
	}
	//end program
	return 0;
}
