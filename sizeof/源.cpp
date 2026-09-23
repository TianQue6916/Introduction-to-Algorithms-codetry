//sizeof(数据类型/变量）

#include <iostream>
using namespace std;

int main() {

	//语法:sizeof(数据类型/变量）——统计内存空间


	short num1 = 10;
		cout << "short占用的内存空间为：" << sizeof(num1) << endl;
		int num2 = 10;
		cout << "int占用的内存空间为：" << sizeof(num2) << endl;

		long num3 = 10;
		cout << "long占用的内存空间为：" << sizeof(num3) << endl;

		long long num4 = 10;
		cout << "long long占用的内存空间为：" << sizeof(num4) << endl;
		system("pause");


		//整形：short<int<=long<=long long
		//用int
			return 0;


}