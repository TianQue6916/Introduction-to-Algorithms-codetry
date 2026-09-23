#include<iostream>
using namespace std;

//常量的定义方式
//1.#define 宏常量
//2.const 修饰的变量


//1.#define 宏常量
#define Day 7

int main() {

	//Day = 14;//day是一个常量，不能进行修改
	cout << "一周总共有：" << Day << "天" << endl;


	system("pause");


		return 0;

}