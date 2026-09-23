//整形
//int 
//数据类型：给变量分割合适的内存空间
//逐一核实的问题
//short 2 int 4 long 4/8 longlong 8
#include<iostream>
using namespace std;


int main() {

	short num1 = 32768;//溢出回到最小值，类似于周期函数
	int num2 = 10;//以下类似
	long num3 = 10;
	long long num4 = 10;

	cout << "num1=" << num1 << endl;
		//短整型最大范围（-32768——32767）
	cout << "num2=" << num2 << endl;
	cout << "num3=" << num3 << endl;
	cout << "num4=" << num4 << endl;



	system("pause");
	return 0;
}