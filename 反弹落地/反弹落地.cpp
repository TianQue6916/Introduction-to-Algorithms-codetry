# include <stdio.h>

int main() {
	long double h = 100;
	long double s = 100;
	int i;

	for (i = 2; i <= 10; i++) {
		h = h / 2;
		s = s + h * 2;
		
	}
	printf("%llf", s);


	return 0;
}