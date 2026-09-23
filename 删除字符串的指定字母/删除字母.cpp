# include <stdio.h>
# include <string.h>

int main() {

	char str[] = "qwqwqqwwwwwwwwwwqqqqqqqqwwwwwww";
	printf("%s\n", str);

	char* p;

	p = str;//本身名字就是地址


	/*int a = 15;      这里就是需要使用地址符号

	int* pa;
	pa = &a;*/


	char s = '0';
	//对于单个变量赋值，如果使用了双引号，就会添加不可见的0；

	//for example
	char strs[] = "0";
	//this will appear a coundn't saw 0 nemed  "\0",have a addition
	for (int i = 0; i < strlen(str); i++) {

		if (i == (strlen(str)) - 1) {
			printf("%c", str[i]);

		}
		else {//这里的条件还是很重要的
			printf("%c->", str[i]);

		}




	}



	return 0;
}