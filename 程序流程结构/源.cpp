#include <iostream>
using namespace std;

int main() {

	//if 语句
	//单行语句
	int score = 0;
	cout << "请输入你的分数：" << endl;
	cin >> score;


	cout << "您输入的分数为" << score << endl;


	//条件判断  --单行语句

	if (score > 600) {//if 后面不可以加分号，这是同一个语句
		//条件为真时执行
		cout << "恭喜您考上了一本大学" << endl;//单行
	}
	else cout << "请继续加油" << endl;//多行


	//多行复合语句
	int fen = 0;
	
	cout << "请输入你的分数：" << endl;
	cin >> fen;
	
	cout << "您输入的分数为" << fen << endl; 
	if (750>= fen > 600) {
		cout << "一本大学" << endl;
	}
	else if (600>= fen > 500) {


		cout << "二本" << endl;

	}
	else if (500>= fen > 400) {
		cout << "三本" << endl;
	}
	else cout << "您没有考上大学" << endl;


	//顺序执行





	system("pause");
	return 0;
}