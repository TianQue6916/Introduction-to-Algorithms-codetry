#include<iostream>
using namespace std;
int& test01()
	{
		int a = 10;//存放在栈区
		return a;//局部变量还是不要去做函数的返回值了
	}

int& test02()
{
	static int a = 10;//存放在栈区的全局区，程序结束后才会释放
	return a;
}



int main() {
	//引用做函数返回值
		//1.不反回局部变量的引用
	
	int& ref = test01();
	cout << ref << endl;
	cout << ref << endl;
	cout << ref << endl;//X86系统会导致消失，X64不会

	int& ref2 = test02();
	cout << ref2 << endl;
	cout << ref2 << endl;
	cout << ref2 << endl;



		//2.函数的调用可以作为左值

	test02() = 1000;//test02 相当于将变量a中做为返回值返回了
					//相当于指针，直接通过别名来操控原变量，避免值传递的复制操作
	cout << ref2 << endl;
	cout << ref2 << endl;
	cout << ref2 << endl;


	system("pause");
	return 0;
}