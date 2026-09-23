#include <stdio.h>
#include <math.h>
#include<stdlib.h>

int  judge(int n) {
	int last = 0;
	int next = 0;
	int res = 0;
	while (n) {
		last = n & 1;
		n >>= 1;
		next = n & 1;
		
		if (last != next) {
			res = 1;
		}
		else {
			res = 0;
		}

		if (!res) {
			return 0;
		}



	}
	return res;




}



