#include <iostream>
using namespace std;

int main() {
	int score = 0;

	cout << "请输入高考分数" << endl;
	cin >> score;

	cout << "您输入的分数是多少分" << score << endl;

	if (score > 600) {
		cout << "一本" << endl;
		if (score > 700) {
			cout << "清华" << endl;
		}
		else if (score > 600) {
			cout << "北大" << endl;
		}
		else {
			cout << "人民大学" << endl;
		}
	}
	else if (score > 500) {
		cout << "二本" << endl;
	}
	else if (score > 400) {
		cout << "三本" << endl;
	}
	else {
		cout << "您没有大学" << endl;
	}





	

	system("pause");
	return 0;

}