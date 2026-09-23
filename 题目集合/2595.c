#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* returnSize) {
	int even = 0,odd=0;
	int bit = 0;
	while (n) {
		if (n & 1) {
			if ( bit % 2 == 0||bit==0) {
				even++;
			}
			else {
				odd++;
			}
		}


		n >>= 1;
		bit++;
	}
	int array[2] = { 0,0 };
	array[0] = even;
	array[1] = odd;
	return array;




}