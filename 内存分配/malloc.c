#include <stdio.h>
#include<stdlib.h>

int main() {



	int* p = malloc(100 * sizeof(int));

	//赋值
	for (int i = 0; i < 100; i++) {
		*(p + i) = (i + 1) * 10;//1'

	}

	//遍历
	for (int i = 0; i < 100; i++) {
		printf("%d\n", *(p + i));
	}
	int number = 1024 * 1024 * 1024;

	int count = 0;
	while (1) {
		int* p = malloc(number);
		count++;
		if (p == NULL) {
			printf("fair");
			break;
		}

		printf("allocation%dsuccess%p\n", count, p);
	}
	


	
	 




	return 0;
}