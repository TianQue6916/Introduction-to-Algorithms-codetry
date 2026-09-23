#include<stdio.h>
#include<math.h>

int transfer2_10(int n) {
	int result = 0;
	int inter = n;
	int mod;
	int count = 0;
	while (1) {
		mod = inter % 10;
		inter = inter / 10;
		result = result + mod * pow(2, count);
		if (inter == 1) {
			break;
		}
		if (inter == 0) {
			return result;
		}
		count++;
	}
	return result + pow(2, count + 1);
}


int main() {
	int x = 0;
	
	x = transfer2_10(1100110);
	printf("%d", x);

	return 0;
}