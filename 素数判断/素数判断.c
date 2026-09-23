#include <stdio.h>



int is_primeNumber(int m) {
   
     // 这里加上了 & 符号

    int i;
    for (i = 2; i < m; i++) {
        if (m % i == 0) {
            break;
            printf("no result");  // 这行永远不会执行，因为前面有break
        }
    }

    if (i == m) {  // 这个判断逻辑有问题
        return 1;
        printf("%d is result", m);
    }
    else {
        return 0;
        printf("%d no result", m);
    }
}


int main() {
    int m;
    scanf("%d", &m);
    int is_primeNumber( m);

    return 0;
}