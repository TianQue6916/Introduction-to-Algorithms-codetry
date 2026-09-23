#include <iostream>
using namespace std;

int main() {

	//水仙花数是一个很难特殊的数
	// ，是一个三位数
	// ，每个位上的数字的三次幂之和等于他本身
	//eg.1^3+5^3+3^3=153
	 
	
	
	
	//输出所有的三位数信息
	//获取三个位上的数字
	//遍历所有的三位数
	// ，来找到范围内的所有要求的数字
	
	//使用取模运算
	




	
	
	
	int num = 100;
	int a = 0, b = 0, c = 0;

	do {
		a = num % 10;
		b = (num / 10) % 10;
		c = num / 100;
		if (a* a* a + b * b * b + c * c * c == num) {
			cout << num << endl;
			
		}
		num++;



	} while (num < 1000);


	system("pause");
	return 0;

}