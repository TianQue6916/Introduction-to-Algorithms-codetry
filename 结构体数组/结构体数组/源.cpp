#include<iostream>
using namespace std;
#include<string>
//结构体数组
struct student {
	string name;
	int age;
	int score;
};

int main() {
	struct student stuarray[3] = {
		{"张三",18,100},
		{"四",28,99},
		{"五",38,66}
	};
	//还可以赋值
	stuarray[2].name = "六";


	for (int i = 0; i < 3; i++) {
		cout << stuarray[i].name 
			<< stuarray[i].age 
			<< stuarray[i].score 
			<< endl;
	}


	system("pause");
	return 0;
}