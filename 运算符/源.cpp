#include<iostream>
using namespace std;

int main() {

	//+-*/
	int a = 10, b = 3;

	cout << a + b << endl;
	cout << a - b << endl;   
	cout << a * b << endl;
	cout << a / b << endl;//这边没有小数，因为都是整数，需要小鼠；
	
	int c = 10, d = 20;
	cout << c / d << endl;//!!

	int e = 10, f = 0;
	//cout << e / f << endl;

	double q = 0.5, w = 0.3;
	cout << q / w << endl;//小数相除；


	//算术运算符
	//1.取余运算
	cout << 10 % 3 << endl;//求的是余数：本质



	cout << 10 % 20 << endl;//商0余10；


	//cout << 10 % 0 << endl;  不能对零求模；
	//两个小数不可以做取模运算；
	double d1 = 3.14;
	double d2 = 1.1;

	

	
	//cout << d1 % d2 << endl;编译器会有错误



	
//递减运算

	//1.前置递增
	int a3 =10;
	++a3;//让变量加1；
	cout << "a3=" << a3 << endl;


	//2.后置递增

	int bb = 10;
	bb++;
	cout << "bb=" << bb << endl;



	//3.区别

	//前置会先加1，再运算；后置先运算再加1

	int aaa = 10;
	int bbb = ++aaa * 10;
	cout << bbb << endl;
	int aa1 = 10;
	int aa2 = aa1++ * 10;
	cout << aa2 << endl;
	

	//一定要注意顺序



	

	system("pause");
	return 0;
}