#include<iostream>
using namespace std;
//交换函数


	//1.值传递
void myswap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	cout << a << " 1 " << b << endl;//值传递形参改变
	
}

//2.指针传递
void myswap02(int* a, int* b) {
	int temp = *a;
	*a =* b;
	*b = temp;
	cout << a << " 1 " << b << endl;
}

//3.引用传递
int myswap03(int& a, int& b) {//利用引用的方式作为传递 
	int temp = a;
	a = b;
	b = temp;
	cout << a << " 1 " << b << endl;
}




int main() {
	int a = 10;
	int b = 20;
	myswap01(a, b);

	cout << a << " 2 " << b << endl;//值传递值没有改变
	myswap02(&a, &b);
	cout << a << " 2 " << b << endl;//地址传递会导致实参的改变
	myswap03(a, b);



	system("pause");
	return 0;
}