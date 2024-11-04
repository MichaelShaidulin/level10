#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width.
	int capacity = COLS;
	char (*arr)[COLS] = malloc(capacity * COLS * sizeof(char));

	// The size should be the number of entries in the array.
	char buffer[COLS];
	*size = 0;
	// Read the file line by line into a buffer.
	while (fgets(buffer, sizeof(buffer), in)) {
    //   Trim newline.
		buffer[strcspn(buffer, "\n")] = 0;
	//   Expand array if necessary (realloc).
		if (*size >= capacity) {
			capacity *= 2;
			arr = realloc(arr, capacity * COLS * sizeof(char));
		}
	//   Copy each line from the buffer into the array (use strcpy).
		strcpy(arr[*size], buffer);
		(*size)++;
	}

    // Close the file.
	fclose(in);

	
	// Return pointer to the array.
	return arr;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
	for (int i = 0; i < size; i++){
		if(strstr(lines[i], target)){
			return lines[i];
		}
	}
    return NULL;
}


void free2D(char (*arr)[COLS])
{
	free(arr);
}