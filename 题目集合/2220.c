#include <stdio.h>
#include <math.h>
#include<stdlib.h>


int min_num(int x, int y) {
	int count=0;
	int deff = x ^ y;
	while (deff) {
		deff = deff & (deff - 1);
		count++;
	}






	return count;
}