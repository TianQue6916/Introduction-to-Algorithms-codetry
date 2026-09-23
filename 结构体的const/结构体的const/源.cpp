#include<iostream>
using namespace std;
//使用const来防止误操作
#include <string>
struct student {
	string name;
	int age;
	int score;

};
void printstudent(student s) {//这里是值传递，不改变实参
	s.age = 150;
	cout << s.name << s.age << s.score << endl;
}
void printstudent1(const student* s) {//这里是指针传递，改变实参
	//虽然这样可以节省空间，但是会改变结构体参数本身
	//这时候就可以使用 const
	//s->age = 150;  这里就不可以改变了，方便报错
	//引用的时候，使用值传递会导致大批流量的数据，但是值传递可以修改副本，指针不行（const
	cout << s->name << s->age << s->score << endl;
}
int main() {

	student s = { "3",15,70 };
	printstudent(s);

	system("pause");
	return 0;
}