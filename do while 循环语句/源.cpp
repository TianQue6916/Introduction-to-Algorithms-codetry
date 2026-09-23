#include <iostream>
using namespace std;

/*int main() {
	int i = 0;

	while (i < 10) {
		
				cout << i << endl;		//区别在于do while
										//会先执行一次循环语句
				i = i+1;
	}*/

int main(){


	int num = 0;
	do {
		cout << num << endl;//先执行再判断
		num++;

	} while (num <
		10);


	int a = 0;
	while(a<10
		){
		cout << a << endl;//先判断在执行
		a++;
	}



	system("pause");
	return 0;
}