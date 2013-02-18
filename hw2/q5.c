#include <stdio.h>
#include <stdlib.h>
#include "q5.h"

int main(int argc, char **argv)
{
	int nTestcase = 0;
	int i = 0;
	char inputstr[100];
	char *reversedStr = NULL;
	scanf("%d\n", &nTestcase);
	for (i = 0; i < nTestcase; i++)
	{
		fgets(inputstr, 100, stdin);
		reversedStr = reverse(inputstr);
		printf("%s\n", reversedStr);
		free(reversedStr);
		memset(inputstr, 0, 100);
	}
	return 0;
}
