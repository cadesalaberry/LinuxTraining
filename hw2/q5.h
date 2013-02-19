#ifndef Q5_H
#define Q5_H
#include <string.h>
/**
 * reverse the words in input, 
 * input: input string
 * return the reversed string
 */

/**
 * Swapes the position of 2 letters.
 */ 
void swap(char *string, int start, int end)
{
	char temp;
	while(start < end)
	{
		temp = string[start];
		string[start++] = string[end];
		string[end--] = temp;
	}
}

char *reverse(char const *input)
{
	char *ret = (char *)malloc(sizeof(char) * strlen(input));
	//TODO:preprocess
	//the input may end with a \n, so you have to strip that
	
	int size = strlen(input);
	
	// Copies the string.
	strcpy(ret,input);
	
	// Strips the '\n' character.
	int i;
	for(i = 0; i < size; i++) {
		if (ret[i] == '\n') ret[i] = ' ';
	}
	
	// Swaps the entire string.
	swap(ret, 0, size-2);

	// Swaps back the words one by one.
	int old = 0;
	for(i = 1; i <= size; i++) {
		
		if (!(i < size)) {
			// Checks for the last word
			swap(ret, old+1, size-1);
			
		} else if (ret[i] == ' ') {
			swap(ret, old, i);
			old = i;
		}
	}

	return ret;
}

#endif
