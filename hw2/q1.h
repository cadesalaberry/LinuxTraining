#ifndef Q1_H
#define Q1_H

/**
 * Make sure to synchronise the values of Y_MAX and X_MAX.
 * The program had a weird behaviour when Y_MAX=X_MAX, so I had to
 * set X_MAX to a different value.
 * (note that a lower value works as well)
 */ 
#define Y_MAX 100
#define X_MAX 101

int pascalTriangle[Y_MAX][X_MAX];
int GetPTElement(int level, int eleIdx);

/**
 * in this function your supposed to build the pascal triangle,
 * (filling element values to the global variable pascalTriangle
 * notice that you have to fill all 100 rows
 */
void buildPascalTriangle()
{
	// Builds the first line.
	pascalTriangle[0][0] = 1;
	int level, index;

	for (level = 1; level <= Y_MAX; level++)
	{
		for (index = 0; index <= level && index <= X_MAX; index++)
		{
			int left = GetPTElement(level-1, index-1);
			// If the element does not exist, replace by zero.
			if (left < 0) left = 0;

			int right = GetPTElement(level-1, index);
			// If the element does not exist, replace by zero.
			if (right < 0) right = 0;
			
			pascalTriangle[level][index] = left + right;
		}
		//printf("\n");
	}
}

/**
 * in this function, you are supposed to return the element
 * specified by level, and eleidx, 
 *
 * e.g. GetPTElement(2, 1) will return 2
 * if (level, eleIdx) is referring to a 'non-exist' element, return -1;
 */
int GetPTElement(int level, int eleIdx)
{
	if (0 <= level && level <= Y_MAX) {
		if (0 <= eleIdx && eleIdx <= level && eleIdx <= X_MAX) {
			
			return pascalTriangle[level][eleIdx];
		}
	}
	return -1;
}
#endif
