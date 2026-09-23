#include<iostream>
using namespace std;

int main() {
	int a = 10, b = 10;
	const int* p = &a;//指向的值不可以修改
	//*p = 20;///解引用后的指向的值不可以修改
	p = &b;//修改指向


	int* const p = &a;//不能改指向
	*p = 20;
	//p = &b;


	const int* const p = &a;//指向和值都不能修改
	//*p = 20;
	//p = &b;



	//p是指针，*p是值，const写在哪个前面哪个就不能改






	system("pause");
	return 0;
}