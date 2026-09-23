#include<iostream>
using namespace std;

int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << arr[0] << endl;
	int* p = arr;//首地址
	cout << "利用指针" << *p << endl;
	p++;//偏移一次，放到下一个
	
	
	//做一个循环
	cout << "2=" << *p << endl;
	for (int i = 0; i < 9; i++) {
		cout << *p << endl;
		p++;
	}


	system("pause");
	return 0;
}