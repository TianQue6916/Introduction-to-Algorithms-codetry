#include <iostream>
using namespace std;

int main() {
	//三只小猪称体重问题
	//先判断谁重  A B C 之间比大小
	int numa = 0, numb = 0, numc = 0;//创建体重变量
	cout << "a=" << endl;
	cin >> numa;
	cout << "b=" << endl;
	cin >> numb;
	cout << "c=" << endl;
	cin >> numc;


	//判断环节
	if (numa > numb) {
		if (numa > numc) {
			cout << "a最重" << endl;
		}
		else {
			cout << "c最重" << endl;
		}
	}
	else {
		if (numb > numc) {
			cout << "b最重" << endl;
		}
		else {
			cout << "c最重" << endl;
		}
	}
	system("pause");
	return 0;
}
