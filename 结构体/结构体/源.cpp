#include<iostream>
using namespace std;
#include<string>
//结构体的使用还有创建


//如何创建学生类型
struct student {
	string name;
	int age;
	int score;
	//一些类型的集合
}s3 //这里可以顺便创建结构体变量
;


int main() {
//具体：struct student s1
struct  student s1;
s1.name = "张三";
s1.age = 18;
s1.score = 100;
cout << s1.name << s1.age << s1.score << endl;
//struct student s2={.......}
//定义变量的时候可以省略
/*struct*/  student s2 = {"李四",19,80};
cout << s2.name << s2.age << s2.score << endl;


//s3.......
//同上

//         要用.来访问


 //创建的时候顺便做下定义


	system("pause");
	return 0;
}