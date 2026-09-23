#include <stdio.h>
#include <math.h>

int isPrime(int m) {
    if (m <= 1) {
        return 0;  // 0和1不是素数
    }
    if (m == 2) {
        return 1;  // 2是素数
    }
    if (m % 2 == 0) {
        return 0;  // 偶数不是素数（除了2）
    }

    // 只需要检查到 sqrt(m)
    int limit = sqrt(m);
    for (int i = 3; i <= limit; i += 2) {  // 跳过偶数
        if (m % i == 0) {//这个条件是在判断究竟是不是整除
            return 0;
        }
    }
    return 1;

    for (int i = 3; i <(int)sqrt((double)m); i += 2) {  // 跳过偶数
        if (m % i == 0) {//这个条件是在判断究竟是不是整除
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = 13;

    // 测试一些数字
    printf("测试素数判断：\n");
    printf("%d %s素数\n", n, isPrime(n) ? "是" : "不是");

    // 额外测试
    printf("1-20中的素数：\n");
    for (int i = 1; i <= 20; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}