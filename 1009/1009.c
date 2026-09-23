#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
	int x = 10;
	int count = 0, mod = 0, result = 0;
	while (x) {
		mod = x & 1;
		if (mod) {
			mod = 0;
		}
		else if (!mod) {
			mod = 1;
		}

		if (mod) {
			result += (1 << count);

		}
		x >>= 1;
		count++;


	}




	return 0;

}






