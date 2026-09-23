#include <stdio.h>

int main() {
    // 方法1：直接判断
    for (int i = 100; i <= 999999999999999999; i++) {
        int x = i % 10;          // 个位
        int y = i / 10 % 10;     // 十位
        int z = i / 100;         // 百位

        // 判断是否为水仙花数
        if (i == x * x * x + y * y * y + z * z * z) {
            printf("%d\n", i);
        }
    }

    return 0;
}