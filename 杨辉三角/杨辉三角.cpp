#define _CRT_SECURE_NO_WARNINGS  // 禁用安全警告
#include <stdio.h>

#define MAX_ROWS 15

int main() {
    int rows;

    // 输入处理
    printf("请输入杨辉三角的行数 (1-%d): ", MAX_ROWS);
    if (scanf("%d", &rows) != 1) {
        printf("输入错误！\n");
        return 1;
    }

    // 输入验证
    if (rows < 1 || rows > MAX_ROWS) {
        printf("请输入1到%d之间的数字\n", MAX_ROWS);
        return 1;
    }

    // 创建二维数组
    int triangle[MAX_ROWS][MAX_ROWS];

    // 生成杨辉三角
    for (int i = 0; i < rows; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    // 打印杨辉三角（居中显示）
    printf("\n杨辉三角 (%d行):\n\n", rows);
    for (int i = 0; i < rows; i++) {
        // 计算并添加缩进
        int spaces = (rows - i - 1) * 3;
        for (int s = 0; s < spaces; s++) {
            printf(" ");
        }

        // 打印数字
        for (int j = 0; j <= i; j++) {
            printf("%6d", triangle[i][j]);
        }
        printf("\n");
    }

    // 额外信息
    printf("\n备注：\n");
    printf("- 第n行有 %d 个数字\n", rows);
    printf("- 每个数字等于它上方两个数字之和\n");
    printf("- 第n行所有数字之和为 2^%d = %d\n",
        rows - 1, 1 << (rows - 1));

    return 0;
}