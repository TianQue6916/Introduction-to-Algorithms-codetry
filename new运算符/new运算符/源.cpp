#include<iostream>
using namespace std;

int* func() {
	//new返回的是该数据类型的指针
	//前后的数据类型应当保持一致
	int *p=new int(10);

	return p;
}
void test01() {
	int * p = func();
	cout << *p << endl;//解引用给出数值
	//不释放数据就会一直存在
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl; 
	cout << *p << endl; 
	cout << *p << endl; 
	delete p;
	
	//cout << *p << endl;//这里内存被清除掉了
	//cout << *p << endl;


}
void test02() {
	int*arr=new int[10];//创建了一个数组，长度为十；
	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;
		//赋值命令

	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " " ;//打印命令
	}
	//释放数组
	delete[] arr;//需要告诉编译器释放的空间是数组



}




int main() {
	
	test01();
	test02();

	system("pause");
	return 0;
}