#include <stdio.h>
#include <math.h>
#include<stdlib.h>



int kor(int* num, int numsize, int k) {
	int current = 1;
	int bit = 0;
	int time = 0;
	int* result = (int*)malloc(numsize * 32 * sizeof(int));
	int number = 1;
	int count = 0;
	int countin = 0;
	int maxnum = 0;
	while (maxnum) {


		time = 0;
		for (int i = 0; i < numsize; i++) {
			current = num[i];

			bit = current & number;
			if (bit) {
				time++;
			}
			if (current > maxnum) {
				maxnum = current;
			}


			if (time >= k) {
				result[countin] = time;
				countin++;
				
			}



		}
		count++;
		number <<= 1;

		maxnum <<= count;


		
	}









	return result;
}