#include <stdio.h>
#include <stdlib.h>
#include "q2.h"

int main(int argc, char **argv)
{
	char binstr[10];
	int nTestcase = 0;
	int *output = NULL;
	int i = 0;
	scanf("%d", &nTestcase);
	output = (int *) malloc(sizeof(int) * nTestcase);
	for (i = 0; i < nTestcase; i++)
	{
		scanf("%s", binstr);
		output[i] = binTodec(binstr);
	}
	for (i = 0; i < nTestcase; i++) printf("%d\n", output[i]);
	free(output);
	return 0;
}
