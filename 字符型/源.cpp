#include <iostream>

using namespace std;



int main() {

//字符变量创建方式

	char ch = 'A';
	cout << ch << endl;

//所占内存大小

	cout << "char字符型变量所占内存：" << sizeof(char) << endl;//只占一个字节


//常见错误

	char ch2 = 'b';//创建字符型变量一定要用单引号

	char ch3 = 'abcd';//这里虽然可以，但是是整形了，而不是字符型，所以还是保留一个吧
	cout << "ch3的输出：" << ch3 << endl;
	//这样看起来只保留了最后一个字符,而且里面的字符不能超过四个，只能大于等于四个


//对应的ASCLL编码
	cout << (int)ch<< endl;//这里是使用了c语言的方法，更安全的是别的

	//如：int i=static_cast等等，之后再学






	system("pause");
	return 0;
}