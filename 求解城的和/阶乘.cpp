#include <stdio.h>

int main() {
    int i, j, n;
    int total = 0;  // 阶乘总和
    int factorial;  // 每个阶乘值

    scanf_s("%d", &n);

    for (i = 1; i <= n; i++) {
        factorial = 1;  // 重置每个数的阶乘计算
        for (j = 1; j <= i; j++) {
            factorial *= j;  // 计算 i!
        }
        total += factorial;  // 累加到总和中
    }

    printf("%d", total);

    return 0;
}