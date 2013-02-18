#ifndef Q4_H
#define Q4_H
#define FIB_MAX 20

unsigned int fib[FIB_MAX];

/**
 * builds the Fibonacci sequence in the fib array;
 * 
 * 
 */
void buildFib() {
	
	fib[0] = 0;
	fib[1] = 1;

	unsigned int i;

	for (i=2; i < FIB_MAX; i++) {

		fib[i] = fib[i-1] + fib[i-2];

	}
}
 
/**
 * return the specifiede element of fibonacci array
 * idx: the index of element we want to return
 * return the value of fib[idx]
 *
 * NOTICE: before you return fib[idx], you have to build fibonacci array first
 * you only need to build the first 20 elements in Fib-Array
 */
int Fibonacci(int idx)
{
	// Builds the sequence if it is not already built.
	if (fib[2] != 1) buildFib();
	
	return fib[idx];
}

#endif
