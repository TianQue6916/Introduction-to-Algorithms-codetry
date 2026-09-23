#include <stdio.h>
#include <string.h>

int main() {


	char s[] = "0123456789";
	int len = 0;
	len = strlen(s);
	printf("%d\n", len);
	printf("%s\n", s);


	int i;
	for (i = 0; i < (len / 2 ); i++) {
		char temp;
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - 1 - i] = temp;



	}
	printf("%s", s);

	return 0;
}