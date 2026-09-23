#include <iostream>
using namespace std;

int main() {


	for (int i = 1; i <= 9; i++) {//计数行数
		//cout << i << endl;
		for (int j = 1; j <= i; j++) {//根据每一行的行数计数列数
			//，二行两列，三行三列，依此类推
			cout << j<<"*"<<i<<"="<<j*i<<"   ";
		}cout << endl;
	}


	//



	system("pause");
	return 0;
}