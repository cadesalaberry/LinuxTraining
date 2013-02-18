#ifndef Q2_H
#define Q2_H
#include <string.h>
/**
 * convert binary representation of integer to decimal representation
 * in this function you're suppose to do convert binary to decimal
 *
 * the maximum length of binstr is 10
 */
int binTodec(const char *binstr)
{
	int ret = 0, i, lenght = strlen(binstr);
	
	// Makes sure the program does not go past 10 digits.
	for(i = 0; i < lenght && i < 10; i++)
    {
		// Transforms the char into an int
		ret = ret * 2 + (binstr[i] - '0');
    }
	return ret;
}
#endif
