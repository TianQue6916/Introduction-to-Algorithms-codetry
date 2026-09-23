#include <iostream>
using namespace std;

int main() {
	//查表式运算，只能是一个数值，不能是bool表达式——switch
	cout << "打分" << endl;
	int score = 0;
	cin >> score;
	cout << "您打得分为" << endl;

	switch (score) {
	case 10:cout << "经典电影" << endl;
		break;//跳出分支
	case 9:cout << "经典电影" << endl;
		break;
	case 8:cout << "一般电影" << endl;
		break;
	case 7:cout << "一般电影" << endl;//注意break跳出
		break;
	case 6:cout << "一般电影" << endl;
		break;
	case 5:cout << "一般电影" << endl;
		break;
	default:
		cout << "烂片" << endl;
	}//switch只能是整形或者字符型，if可以是表达式判断（bool）
	//执行效率很高


	system("pause");
	return 0;
}