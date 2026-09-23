#include<iostream>
using namespace std;






int main() {
	int a = 10;
	int& b = a;//引用：给变量起别名








	
	cout << b << " " << a << endl;



	//引用的注意事项
	int a = 10;
	//1.必须要初始化
	//		int& b = ;这里错误，没有初始化




	//2.初始化后就不可以更改
	int c = 20;


	int & b = c;


















	system("pause");
	return 0;
}