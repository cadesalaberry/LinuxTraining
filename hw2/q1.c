#include <stdio.h>
#include <stdlib.h>
#include "q1.h"

int main(int argc, char **argv)
{
	int level = 0; 
	int eleIdx = 0;
	int nTestcase = 0;
	int *output = NULL;
	int i = 0;

	buildPascalTriangle();
	scanf("%d", &nTestcase);
	output = (int *) malloc(sizeof(int) * nTestcase);
	for (i = 0; i < nTestcase; i++)
	{
		scanf("%d%d", &level, &eleIdx);
		output[i] = GetPTElement(level, eleIdx);
	}
	for (i = 0; i < nTestcase; i++) printf("%d\n", output[i]);
	free(output);
	return 0;
}
