#include <stdio.h>
#include <math.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
	int min = 0, max = 0,flag_max=0;
	
	if (ASize <= BSize) {
		min = ASize;
		max = BSize;
		flag_max = 'B';
	}
	else {
		min = BSize;
		max = ASize;
		flag_max = 'A';

	}
	int* arr = (int*)malloc(max * sizeof(int));
	if (arr == NULL) {

		return -1;
	}
	int count = 0;

	for (int i = 0; i < min; i++) {
		if (A[i] == B[i]) {
			count++;
			arr[i] = count;
		}
		
	}
	for (int i = min; i < max; i++) {
		for (int j = 0; j < min; j++) {
			if (flag_max == 'A') {
				if (A[i] == B[j]) {
					count++;
					arr[i] = count;
				}
				 
			}
			else {
				if (B[i] == A[j]) {
					count++;
					arr[i] = count;
				}
			}
			
		}
	}

	return arr;



}



