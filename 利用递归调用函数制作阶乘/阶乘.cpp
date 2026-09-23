# include <stdio.h>
#include "½×³Ë.h"


//f(n)=n*f(n-1)//µÝ¹éÈç´Ë
int n_function(int n) {
	
	if (n==1) {
		return 1;
	}
	else {
		return  n * n_function(n - 1);

	}
}


int main() {
	int n_function(int n);
	int m = 5;
	printf("5!=%d", n_function(m));


	return 0;
}