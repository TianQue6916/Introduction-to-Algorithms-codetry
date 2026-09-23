
#include <stdio.h>

// Sum函数：计算数组中除最大元素之外其他元素的和
void Sum(int arr[], int len) {
    if (len <= 0) {
        printf("0\n");
        return;
    }

    // 找到最大值
    int max_val = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // 计算除最大值外的和
    int sum = 0;
    int found_max = 0; // 标记是否已经跳过一个最大值

    for (int i = 0; i < len; i++) {
        if (arr[i] == max_val && !found_max) {
            found_max = 1; // 跳过第一个最大值
            continue;
        }
        sum += arr[i];
    }

    printf("%d\n", sum
    );
}

// 主函数，处理输入输出
int main() {
    int len;
    scanf("%d", &len);

    int arr[100]; // 假设数组最大长度为100
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    Sum(arr, len);

    return 0;
}
