# include<stdio.h>

int AGE(int age) {
	int a = 0;
	if (age == 1) {

		a = 10;
		printf("1  %d\n", a);
	}
	else {
		a = AGE(age - 1) * 2;
		printf("2  %d\n", a);

	}
	return a;


}

int main() {

	int AGE(int age);
	printf("age(5)=%d", AGE(19));


	return 0;
}