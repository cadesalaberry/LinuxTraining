#include <stdio.h>
#include <stdlib.h>
#include "q3.h"

int main(int argc, char **argv)
{
	int nTestcase = 0;
	int aryLength = 0;
	int ele = 0;
	int *array = NULL;
	int *output = NULL;
	int i = 0, j = 0;
	scanf("%d", &nTestcase);
	output = (int *) malloc(sizeof(int) * nTestcase);
	for (i = 0; i < nTestcase; i++)
	{
		scanf("%d", &aryLength);
		array = (int *) malloc(sizeof(int) * aryLength);
		for (j = 0; j < aryLength; j++)
		{
			scanf("%d", &array[j]);
		}
		scanf("%d", &ele);
		output[i] = BinarySearch(ele, array, 0, aryLength);
		free(array);
	}
	for (i = 0; i < nTestcase; i++) printf("%d\n", output[i]);
	free(output);
	return 0;
}
