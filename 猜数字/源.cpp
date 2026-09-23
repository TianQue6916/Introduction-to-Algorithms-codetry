#include <iostream>
using namespace std;
#include <ctime>//因为使用了时间
int main() {
	//添加随机数种子，使用当前系统时间来输出随机数
	srand((unsigned int)time(NULL));



	
	//生成随机数
	int num = rand() % 100+1; //生成一个未知数
	   
	//cout << num << endl;



	// 猜测
	int value = 0;
	while (1) {

			cin >> value;
	
	//判断
		if (value > num) {
		cout << "太大了" << endl;
	}
		else if (value < num) {
		cout << "太小了" << endl;
	}
		else {
		cout << "恭喜你猜对了" << endl;
		break;//可以退出循环
	}
		
	}
	
	
	//猜对结束，猜错返回结果
	 
	system("pause");
	return 0;
}








	