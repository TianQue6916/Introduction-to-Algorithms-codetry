#include <stdio.h>
#include <math.h>
#include<stdlib.h>
int answer(int n) {

	int count = 0;

	while (n) {

		if (n % 2 == 0) {
			n >>= 1;
			count++;
		}
		else {
			n = n - 1;
			count++;
		}

	}




	return count;
}