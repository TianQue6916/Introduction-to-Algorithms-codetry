#include<iostream>
using namespace std;

int main() {
	//while
	cout << "法1" << endl;
	
	int num = 0;
	cout << num << endl;

	num++;
	cout << num << endl;


	num++;
	cout << num << endl;

	num++;
	cout << num << endl;

	num++;
	cout << num << endl;

	num++;
	cout << num << endl;

	num++;
	cout << num << endl;

	num++;
	cout << num << endl;

	num++;
	cout << num << endl;

	num++;
	cout << num << endl;

	num++;
	cout << num << endl;

	cout << "法2" << endl;
	num = 0;
	while (num <= 10) {//()中填入循环条件  符合表达式就循环（1）  不符合就输出（0）
		cout << num << endl;
		num++;
	}//注意：要避免死循环的出现
	system("pause");
	return 0;
}