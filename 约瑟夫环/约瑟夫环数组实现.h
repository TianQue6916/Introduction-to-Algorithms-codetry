#pragma once
#pragma once
# include<stdio.h>

void print(int array[]) {
	for (int i = 0; i < 100; i++) {
		printf("%d", array[i]);
	}
}
void give_value(int array[]) {
	for (int i = 0; i < 100; i++) {
		array[i] = 1;
	}
}
int main() {
	int a, b;
	printf("putchar your people num and will kill num\n ");
	scanf_s("%d %d", &a, &b);
	int people = a;//the num of people
	int num = b;//the number of will kill

	int people_array[100] = { 0 };

	give_value(people_array);
	print(people_array);















	return 0;
}