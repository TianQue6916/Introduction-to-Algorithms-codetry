
#include <iostream>
using namespace std;
/**********   Begin   **********/
//可在此添加其他内容
void Shift(char *str,int n)
{
    int len = 0;
    // 计算字符串长度
    while (str[len] != '\0') {
        len++;
    }

    if (len == 0) return;

    // 确保n在合理范围内
    n = n % len;
    if (n <= 0) {
        cout << str << endl;
        return;
    }

    // 临时存储要移动的字符
    char temp[100];  // 假设字符串最大长度为100
    for (int i = 0; i < n; i++) {
        temp[i] = str[i];
    }

    // 将剩余字符左移
    for (int i = 0; i < len - n; i++) {
        str[i] = str[i + n];
    }

    // 将临时存储的字符放到字符串末尾
    for (int i = 0; i < n; i++) {
        str[len - n + i] = temp[i];
    }

    cout << str << endl;
}
/**********   End   **********/
