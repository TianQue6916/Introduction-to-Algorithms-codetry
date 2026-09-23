#include<iostream>
using namespace std;
//冒泡排序函数
void bubblesort(int *arr,int len) {
	//可以直接修改数组，作用在全局
	//数组作为参数的时候会退化为指针
	//应为要修改数组，所以就使用指针直接修改数组内部
	//不然还需要创建一个新数组
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//打印数组
void printarray(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << " "<<arr[i];
	}
}


int main() {
	//1.先创建一个数组
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };

	int len = sizeof(arr) / sizeof(arr[0]);


	//2.创建一个函数，实现冒泡排序

	bubblesort(arr, len);

	//3.打印排序后的数组

	printarray(arr, len);



	system("pause");
	return 0;
}