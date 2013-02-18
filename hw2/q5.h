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
void swap(char *first,char *second)
{
	char temp;
	while(first < second)
	{
		temp = *first;
		*first++ = *second;
		*second-- = temp;
	}
}

char *reverse(char const *input)
{
	char *ret = (char *)malloc(sizeof(char) * strlen(input));
	//TODO:preprocess
	//the input may end with a \n, so you have to strip that
	
	int size = strlen(ret)-1;
	int cursor=0;
	while(cursor < size) {
		if (input[cursor] == '\n') {
			ret[cursor] = ' ';
		} else {
			ret[cursor] = input[cursor];
		}
	}
	
	int i, j;
	for (i = size, j=0 ; 0 <= i, j < size; i--, j++) {
		swap(&ret[i], &ret[j]);
	}
	
	printf("%s", ret);
	//TODO:reverse input, and save the result in ret
	
	return ret;
}

#endif
