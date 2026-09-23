#include <stdio.h>
#include "myTesthead.h"
#include "transform.h"
#include "transform.c"





//条件编译
int main() {
#define A 1
#if(A>1)
	printf("A>1\n");
#elif(A==1)
	printf("A==1\n");//这里还是会亮起来的
#endif


# ifdef Max
	printf("实验\n");
#else
	printf("else\n");
#endif


	//逻辑运算符
	/*
	按位与
	按位或
	按位异或
	*/

	//按位与  0&0=0  1&0=0	1&1=1
	int  a = 6, b = 5;
	transform(a);
	printf("\n");

	transform(b);
	printf("\n");
	int c = a & b;
	printf("%d's transform is ", c);
	transform(c);
	printf("\n");

	//按位或 0|0=0  0|1=1  1|1=1




	//按位异或  0^0=0  0^1=1  1^0=1  1^1=0




	return 0;
}