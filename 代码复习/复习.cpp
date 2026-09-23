# include <stdio.h>



int findresult(int m) {
	
	int sum = 0;
	for (int n = 1; n < m; n++) {
		if (m % n == 0) {
			sum += n;
		}
		else {
			;
		}
	}

	if (m == sum) {
		//printf("%d  perfet\n",m);
		return m;

	}
	else {
		//printf("%d  no\n",m);
		return 0;
	}


}


int main() {
	
	for (int i = 0; i <= 1000; i++) {
		int result=findresult(i);
		if (result) {
			printf("%d  yes\n", result);
		}
	}
	

	return 0;
}