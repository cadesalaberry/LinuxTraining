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
	if (seq[startIdx] == ele) {
		
		return startIdx;
	}
	else if (startIdx == endIdx) {
		
		return -1;
	}
	else {
		
		return BinarySearch(ele, seq, startIdx + 1, endIdx);
	}
}

#endif
