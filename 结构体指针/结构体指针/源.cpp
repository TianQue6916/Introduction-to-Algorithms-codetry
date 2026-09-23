#include<iostream>
using namespace std;
struct student {
	string name;
	int age;
	int score;
};
int main() {
	//创建变量
	student s = { "三",18,100 };
	student* p = &s;


	//通过指针访问
	cout << p->name << p->age << p->score << endl;
	
	//是用箭头访问而不是*
	system("pause");
	return 0;
}