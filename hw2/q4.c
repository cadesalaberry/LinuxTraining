#include <stdio.h>
#include <stdlib.h>
#include "q4.h"

int main(int argc, char **argv)
{
	int nTestcase = 0;
	int index = 0;
	int *output = NULL;
	int i = 0;
	scanf("%d", &nTestcase);
	output = (int *) malloc(sizeof(int) * nTestcase);
	for (i = 0; i < nTestcase; i++)
	{
		scanf("%d", &index);
		output[i] = Fibonacci(index);
	}
	for (i = 0; i < nTestcase; i++) printf("%d\n", output[i]);
	free(output);
	return 0;
}
