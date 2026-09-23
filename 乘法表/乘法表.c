# include <stdio.h>

int main() {




	int i = 10;

	for (int j = 1; j <= 9; j++) {
		for (i = 1; i <= j; i++) {
			printf("%d*%d=%-2d  ", j, i, j * i);//加一个负号表示左对齐
		}printf("\n");
	}

	return 0;
}