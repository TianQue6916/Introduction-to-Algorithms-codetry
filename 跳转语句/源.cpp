#include <iostream>
using namespace std;
//break
int main() {
	
	cout << "选择难度" << endl;
	cout << "1" << endl;				//1
	cout << "2" << endl;
	cout << "3" << endl;
	
	int select = 0;
	cin >> select;
	
	switch (select) {
	case 1:
		cout << "普通" << endl;
		break;
	case 2:
		cout << "困难" << endl;
		break;
	case 3:
		cout << "地狱" << endl;
		break;
	}

	for (int i = 0; i < 10; i++) {//2
		
		if (i == 5) {
			break;
		}
		
		cout << i << endl;


	}


	for (int i = 0; i < 10; i++) {
		
		for (int j = 0; j < 10; j++) {
			if (j == 5) {
			break;//结束了内层循环
		}cout << "*";
		}cout << endl;
	}










	system("pause");
	return 0;
}