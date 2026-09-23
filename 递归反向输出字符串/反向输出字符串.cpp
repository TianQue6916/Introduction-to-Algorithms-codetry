# include <stdio.h>
void input(int n) {

	char c;
	if (n == 1) {//  ÖÕÖ¹Ìõ¼ş
		c = getchar();
		putchar(c);


	}
	else {
		
		c = getchar();
		input(n - 1);
		putchar(c);



	}
		
}


int main() {
	void input(int n);
	input(5);





	return 0;
}