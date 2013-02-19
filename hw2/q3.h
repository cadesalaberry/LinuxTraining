#ifndef Q3_H
#define Q3_H

/**
 * in this function you're supposed to recursively search ele in a sorted array, seq
 * ele: the element you want to search
 * seq: the sorted sequence of integers
 * startIdx: the index of the first element in seq
 * endIdx: the index of the last element in seq
 * return the index of ele, if non-exist , return -1
 */
int BinarySearch(int ele, int seq[], int startIdx, int endIdx)
{
	int midpoint = (startIdx+endIdx)/2;
	
	if (startIdx >= endIdx) {
		
		return -1;
	}
	else if (seq[midpoint] > ele) {
		// Considers only the first half of the sequence.
		return BinarySearch(ele, seq, startIdx, midpoint-1);
	}
	else if (seq[midpoint] < ele) {
		// Considers only the second half of the sequence.
		return BinarySearch(ele, seq, midpoint+1, endIdx);
	}
	else if (seq[midpoint] == ele) {
		return midpoint;
	}
	
	return -1;
}

#endif
