#include <iostream>
using namespace std;

int main() {
	//从数字0打印到数字9
	for (int i = 0; i < 10;i++ ) {//三个表达式都是可以空缺的
									//，只需要写分号就好了
		cout << i << endl;			//这里更加简洁了
		//（前提——只执行一次；判断，符合就走大括号内的；然后走最后的）
	}	//（0；1；3）{2}————顺序：0123123123123



	system("pause");
	return 0;
}