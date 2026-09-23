#include <stdio.h>
#include <math.h>
#include<stdlib.h>


int num476(void) {
	int count = 0, mod = 0, result = 0;;
	int x = 5;
	int n = ~x;
	while (n) {
		mod = n ^ 1;
		if (mod) {
			result += mod * (1 << count);
		}
		count++;
	}
	printf("%d", result);







	return 0;
}

