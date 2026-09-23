#include <stdio.h>

// 查找最大值
int find_max(int find[]) {
	int Max = 0;
	for (int i = 0; i < 5; i++) {
		if (Max < find[i]) {
			Max = find[i];
		}
	}
	return Max;
}

// 查找最小值
int find_min(int find[]) {
	int Min = 12345;
	for (int i = 0; i < 5; i++) {
		if (Min > find[i]) {
			Min = find[i];
		}
	}
	return Min;
}

// 打印数组
void array_print(int find[]) {
	for (int i = 0; i < 5; i++) {
		printf("  %d  ", find[i]);
	}
	printf("\n");
}

// 修改：使用普通指针作为参数（最常用方法）
void transform(int value, int position, int* find) {
	if (position == 1) {  // position=1表示最小值放开头
		find[0] = value;  // 直接使用数组下标语法
	}
	else {  // 其他值表示最大值放结尾
		find[4] = value;
	}
}

int main() {
	int find[5] = { 5, 4, 3, 2, 1 };

	int max = find_max(find);
	printf("max = %d\n", max);

	int min = find_min(find);
	printf("min = %d\n", min);

	printf("原始数组: ");
	array_print(find);

	// 修改：传入数组名，它会自动转换为指针
	transform(min, 1, find);  // 最小值放开头
	transform(max, 2, find);  // 最大值放结尾

	printf("变换后数组: ");
	array_print(find);

	return 0;
}