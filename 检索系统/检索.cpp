#include <stdio.h>

int main() {
	char first, second;

	printf("请输入星期名称的第一个字母（小写）: ");
	first = getchar();

	switch (first) {
	case 'm':
		printf("monday\n");
		break;
	case 'w':
		printf("wednesday\n");
		break;
	case 'f':
		printf("friday\n");
		break;
	case 't':
		printf("请输入第二个字母: ");
		// 清除输入缓冲区中的换行符
		getchar();  // 注意：这里可能有多余的换行符
		second = getchar();
		if (second == 'u')
			printf("tuesday\n");
		else if (second == 'h')
			printf("thursday\n");
		else
			printf("输入错误，无法识别星期\n");
		break;
	case 's':
		printf("请输入第二个字母: ");
		getchar();
		second = getchar();
		if (second == 'a')
			printf("saturday\n");
		else if (second == 'u')
			printf("sunday\n");
		else
			printf("输入错误，无法识别星期\n");
		break;
	default:
		printf("输入错误，无法识别星期\n");//default一定是要写的
		break;
	}

	return 0;
}