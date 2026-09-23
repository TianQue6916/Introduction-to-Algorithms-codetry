#include<iostream>
using namespace std;
#include <string>
struct student {
	string name;
	int age;
	int score;

};
struct teacher {
	int id;
	string name;
	int age;
	struct student stu;

};


int main() {
	teacher t;
	t.id = 10000;
	t.name = "王";
	t.age = 50;
	t.stu.name = "小";
	t.stu.age = 20;
	t.stu.score = 60;//用点来链接

	cout << t.id 
		<< t.name 
		<< t.age 
		<< t.stu.name 
		<< t.stu.age 
		<< t.stu.score 
		<< endl;

	system("pause");
	return 0;
}