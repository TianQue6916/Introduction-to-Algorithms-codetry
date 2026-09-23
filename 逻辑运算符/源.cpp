#include <iostream>
using namespace std;

int main() {
	//逻辑运算符
	//1.非
	int a;
	a= 10;
	cout << !a << endl;//原数不为0都为真，取非就为假

	cout << !!a << endl;//可以叠加

	//2.或||
	int b;
		//对于两个条件其中一个可以满足时就为真
	a = 10, b = 10;

	cout <<"a||b"<< (a || b) << endl;

	a = 0, b = 0;
	cout << (a || b) << endl;//同假必假，一真全真；

	





	//3.与
	a = 10;
 b = 10;//两个需要同时成立
	cout <<"ab"<< (a && b) << endl;



	a = 0, b = 10;
	cout << (a && b) << endl;




	system("pause");
	return 0;
	
}