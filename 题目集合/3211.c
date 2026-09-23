#include <stdio.h>
#include <math.h>
#include<stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** validStrings(int n, int* returnSize) {
	int zero = 0,  one = 0;
	while (n) {

		if (n & 1) {
			one++;
		}
		else {
			zero++;
		}
		


		n >>= 1;

	}
	






}
