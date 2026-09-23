#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {

	if (n % 2 == 0) {
		while (n) {
			if (n % 2 != 0) {
				return false;
			}
			n >>= 1;
		}
		return true;
	}
	else if (n == 1) {
		return true;
	}
	return false;
}