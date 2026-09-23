#include <iostream>
using namespace std;
int main(){
	//表达式1?表达式2:表达式3
	int a=10, b=20, c=0;

	c = (a > b ? a : b);//前判断  真输出左假输出右
	cout << "c=" << c << endl;
	
	
	//运算符输出结果是‘变量’，可以继续赋值
	(a > b ? a : b) = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;//这里b被赋值了





	 
	system("pause");
	return 0;
	}