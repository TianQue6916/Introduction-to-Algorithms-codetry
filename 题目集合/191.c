#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <stdbool.h>

int hammingWeight(int n) {
	int count = 0;

	while (n) {
		if (n & (n - 1))
		{
			count++;
		}
	}





	return count;
}


