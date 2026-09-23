# include <stdio.h>

int main() {
	float h = 100;
	float s = 100;
	int i;

	for (i = 2; i <= 10; i++) {
		s = s + h * 2;
		h = h / 2;
	}



	return 0;
}