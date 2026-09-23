# include <stdio.h>

int main() {

	float a, b, c;
	scanf("%f,%f,%f", a, b, c);
	printf(a, b, c, "\n");


	int result = (a < b ? a : b) < c ? (a < b ? a : b) : c;
	printf(result);//这里求的是最大的



	return 0;
}