#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
	int count=0;
	for (int i = 0; i <= n; i++) {
		count = 0;
		while (n) {
			count++;
			n &= (n - 1);

		}
		returnSize[i] = count;
	}


}