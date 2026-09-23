#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
//
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** validStrings(int x, int* returnSize) {
//	int flag = 0;
//	int*array = (int)malloc(sizeof(int) * 100);
//	int a = 0;
//	int x1 = x;
//	x >>= 1;
//	while (x) {
//		a = x & 11;
//		x >>= 2;
//
//
//		array[flag] = a;
//
//		if (a) {
//			flag++;
//
//		}
//
//	}
//
//	a = 0;
//	while (x1) {
//		a = x & 11;
//		x >>= 2;
//
//		array[flag] = a;
//
//		if (a) {
//			flag++;
//		}
//	}
//
//	returnSize = flag;
//	return array;
//
//
//
//}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** validStrings(int x, int* returnSize) {
    // 计算需要的空间大小
    int maxBits = sizeof(int) * 8; 
    char** result = (char**)malloc(maxBits * sizeof(char*));
    if (!result) {
        *returnSize = 0;
        return NULL;
    }

    int count = 0;
    int temp = x;
    while (temp) {
        int bit = temp & 1; // 检查最低位
        if (bit) {
            // 分配字符串空间（假设每个字符串长度为2）
            result[count] = (char*)malloc(2 * sizeof(char));
            if (!result[count]) {
                // 分配失败时释放已分配的内存
                for (int i = 0; i < count; i++) {
                    free(result[i]);
                }
                free(result);
                *returnSize = 0;
                return NULL;
            }
            result[count][0] = '1';
            result[count][1] = '\0';
            count++;
        }
        temp >>= 1;
    }

    *returnSize = count;
    return result;
}
