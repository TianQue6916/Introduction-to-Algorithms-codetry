#include<iostream>
using namespace std;
void swap1(int a, int b) {
	int temp = a;//值传递
		//不会修改实际参数
	a = b;
	b = temp;
	cout << a << endl;
	cout << b << endl;
}
void swap2(int* p1, int* p2) {//地址传递
	//会改变实际参数，直接操作地址改变实际参数
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	cout << *p1 << endl;
	cout << *p2 << endl;

}



int main() {
	int a = 10;
	int b = 20;
	swap1(a, b);
	swap2(&a, &b);//为什么这里只需要地址呢

	






	system("pause");
	return 0;
}