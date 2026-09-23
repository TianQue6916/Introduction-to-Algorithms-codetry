# include <stdio.h>
//
//
//
//int len_try(int todo[]) {
//	int size = sizeof(todo);
//
//	int size_one = sizeof(todo[0]);
//
//	int len = size / size_one;
//
//	printf("%d", len);
//	return len;
//
//}
//
//int main() {
//
//	int a[] = { 1,2,3,4,5,6,7,8,9,0 };
//	for (int j = 0; j < 10; j++) {
//		printf("%d ", a[j]);
//		
//
//	}
//	int len = len_try(a);
//	printf("%d", len);
//	//for(int i=0;i<)
//
//
//
//
//
//
//
//
//	return 0;
//}
void print(int m) {
	printf("%d", m);
}



int main() {

	int a[15] = { 1,2,3,4,5,6,7,8,9,0 };





	//我们需要如何去插入一个数呢

	int b;
	scanf_s("%d", &b);
	int j = 9;
	if (b > a[9]) {
		a[10] = b;

	}

	else {
		for (int i = 0; i < 15; i++) {
			if (a[i] < b) {
				continue;
			}
			else {
				for (j = 14; j >= i; j--) {

					a[j + 1] = a[j];

				}
				a[j] = b;
			}
		}

	}

	for (int i = 0; i < 15; i++) {
		print(a[i]);
		printf("\n");
	}

	return 0;






}