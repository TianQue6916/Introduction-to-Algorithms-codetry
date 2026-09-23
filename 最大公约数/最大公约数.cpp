#include <stdio.h>

// 1. 辗转相除法（欧几里德算法）
int gcd_euclidean(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 2. 更相减损法
int gcd_subtract(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}

// 3. 递归辗转相除法
int gcd_recursive(int a, int b) {
    if (b == 0) return a;
    return gcd_recursive(b, a % b);
}

// 4. 最小公倍数
int lcm(int a, int b) {
    return a * b / gcd_euclidean(a, b);
}

int main() {
    int a = 1997, b = 615;

    printf("计算 %d 和 %d 的GCD和LCM：\n", a, b);
    printf("=================================\n");

    printf("1. 辗转相除法: \n");
    printf("   GCD(%d, %d) = %d\n", a, b, gcd_euclidean(a, b));
    printf("   LCM(%d, %d) = %d\n", a, b, lcm(a, b));

    printf("\n2. 更相减损法: \n");
    printf("   GCD(%d, %d) = %d\n", a, b, gcd_subtract(a, b));

    printf("\n3. 递归辗转相除: \n");
    printf("   GCD(%d, %d) = %d\n", a, b, gcd_recursive(a, b));

    // 验证所有方法结果一致
    printf("\n=================================\n");
    printf("验证: 所有方法计算的GCD是否相同？\n");
    int g1 = gcd_euclidean(a, b);
    int g2 = gcd_subtract(a, b);
    int g3 = gcd_recursive(a, b);

    if (g1 == g2 && g2 == g3) {
        printf("✓ 所有方法结果一致: GCD = %d\n", g1);
        printf("✓ LCM = %d × %d ÷ %d = %d\n", a, b, g1, lcm(a, b));
    }
    else {
        printf("✗ 结果不一致！\n");
    }

    return 0;
}