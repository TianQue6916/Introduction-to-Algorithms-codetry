#include<iostream>
using namespace std;
#include<string>
//结构体做函数参数
struct student {
	string name;
	int age;
	int score;
};
//



//将学生传入一个参数，打印学生的信息
void printstudent1(struct student s) {
	s.name = 100;//这里修改不会导致实参修改
	cout << "子函数中" << s.name << s.age << s.score << endl;
}//值传递

void printstudent2(struct student *p) {
	p->name = 200;
	cout<<"2" << p->name << p->age << p->score << endl;
}//这里修改会导致实参改变

int main() {



	//创建结构体变量
	student s;
	s.name = "三";
	s.age = 20;
	s.score = 85;
	cout << "main=" << s.name << s.age << s.score << endl;

	printstudent1(s);
	printstudent2(&s);

	system("pause");
	return 0;
}