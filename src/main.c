#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EPARAM 1
#define EFILE 2

int main (int argc, char ** argv)
{
	if(argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return EPARAM;
	}

	// open story file
	FILE * storyFile;
	storyFile = fopen(argv[1], "r");
	if(storyFile == NULL){
		printf("The file does not exist.\n");
		return EPARAM;
	}

	// read story file header
	char * buffer = malloc(7*sizeof(char));
	fgets(buffer, 6, storyFile);
	if(strcmp(buffer, "#book\n") != 0){
		printf("This file is not a valid story file.\n");
		return EFILE;
	}

	//read story
	printf("Found a valid story file.\n");
	return 0;
}
