#include <iostream>
using namespace std;

int main() {


	//float 4 7有效数字
	//double 8 15/16有效
	//默认情况下 输出一个小数，会显出六位有效数字
	//更多的有效数字会很复杂，不管单精度双精度都是六位有效数字，只要是输出的是小数
	float f1 = 3.14159265358f;

	

	cout << "f1=" <<f1<< endl;

	double d1 = 3.14159265358;//太长的数据类型就不能再显示了

		cout << "d1=" <<d1<< endl;


	//统计他们占用的内存空间

		cout << "float占用的空间为：" << sizeof(float)<<endl;//占用四字节
		
		
		cout << "double占用的空间为：" << sizeof(d1) << endl;//占用八字节

		//科学计数法
		float f2 = 3e2;//e后面是正数的时候，是3*10^2//e

		cout << "f2=" << f2 << endl;

		float f3 = 3e-2;//后面是一个负数，就是3*0.1^2

		cout << "f3=" << f3 << endl;




		system("pause");

		
return 0;
}