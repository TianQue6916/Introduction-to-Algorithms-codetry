#include<iostream>
using namespace std;
//内存四区的意义

//代码区


//全局区
	//全局变量，静态变量，常量
//创建普通局部点亮1

int a, b;//全局变量


const int e, f;//全局常量   除了局部的剩下的都在一块存放


//栈区注意事项
//数据由编译器管理


int * func(int b) {//形参也会放在栈区
	int a = 10;//存放在栈区
	return &a;
	//在堆区开辟数据
	//利用1 new
	int* p = new int(10);//堆区随去随用
	return p;
}


//有操作原来做到开辟还有调用








int main() {
	
	cout << &a << &b << endl;


	int c, d;//局部变量

	cout << &c << &d << endl;

	static int s_a, s_b;//静态变量////全局和静态变量是一起保存的
	//const int i;//局部常量，和局部变量保存位置差不多

	//常量
		//字符串常量还有const引起来的变量
	//只要使用引号括起来的都是字符串常量
	//看起来和全局变量和静态变量保存的位置差不多
	cout << &s_a << &s_b << endl;
	
	int* p = func(a);
	
	
	cout << *p << endl;//第一次可以打印是因为做了保留
	cout << *p << endl;//第二次就不行了，被清空了；


	cout << *p << endl;




	

	
	
	
	
	
	
	system("pause");
	return 0;
}