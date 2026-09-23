#include <iostream>
#include<string>
using namespace std; 



int main() {

	//整形
	int a = 0;
	cout << "赋值" << endl;//假设想修改a，并且是面向用户；
	cin >> a;
	cout << "a" << a << endl;
	//浮点型
	float f = 3.14f;
	cout << "赋值" << endl;
	cin >> f;
	cout << "f" << f << endl;
	//字符型
	char ch = a;
		cout << "ment" << endl;
	cin >> ch;
	cout << "ch" << ch << endl;
	//字符串型
	string str = "hello";
	cout << "ment" << endl;
	cin >> str;
	cout << "str" << str << endl;

	//一定要注意头文件
	 
	
	//布尔类型
	bool flag = false;
	cout << "赋值" << endl;
	cin >> flag;//除了0是假，剩下的数字都是真
	cout << "flag" << flag << endl;

	system("pause");
	return 0;
}