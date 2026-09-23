#include <stdio.h>
#include <math.h>
#include<stdlib.h>
//
//
///**
// * 创建一个指定大小的动态数组
// * @param size 数组大小
// * @return 成功返回数组指针，失败返回NULL
// */
//int* create_array(int size) {
//    if (size <= 0) {
//        printf("错误：数组大小必须大于0\n");
//        return NULL;
//    }
//
//    int* arr = (int*)malloc(size * sizeof(int));
//
//    if (arr == NULL) {
//        printf("错误：内存分配失败\n");
//        return NULL;
//    }
//
//    return arr;
//}
//
///**
// * 创建并初始化数组（所有元素设为指定值）
// * @param size 数组大小
// * @param init_value 初始值
// * @return 成功返回数组指针，失败返回NULL
// */
//int* create_init_array(int size, int init_value) {
//    int* arr = create_array(size);
//
//    if (arr != NULL) {
//        for (int i = 0; i < size; i++) {
//            arr[i] = init_value;
//        }
//    }
//
//    return arr;
//}
//
///**
// * 创建并初始化数组（按顺序赋值 0,1,2,...）
// * @param size 数组大小
// * @return 成功返回数组指针，失败返回NULL
// */
//int* create_sequence_array(int size) {
//    int* arr = create_array(size);
//
//    if (arr != NULL) {
//        for (int i = 0; i < size; i++) {
//            arr[i] = i;
//        }
//    }
//
//    return arr;
//}
//
///**
// * 复制数组
// * @param arr 原数组
// * @param size 数组大小
// * @return 成功返回新数组指针，失败返回NULL
// */
//int* copy_array(int* arr, int size) {
//    if (arr == NULL || size <= 0) {
//        printf("错误：无效的参数\n");
//        return NULL;
//    }
//
//    int* new_arr = create_array(size);
//
//    if (new_arr != NULL) {
//        for (int i = 0; i < size; i++) {
//            new_arr[i] = arr[i];
//        }
//    }
//
//    return new_arr;
//}
//
///**
// * 调整数组大小
// * @param arr 原数组指针
// * @param old_size 原数组大小
// * @param new_size 新数组大小
// * @param default_value 新增元素的默认值
// * @return 成功返回新数组指针，失败返回NULL（原数组保持不变）
// */
//int* resize_array(int* arr, int old_size, int new_size, int default_value) {
//    if (new_size <= 0) {
//        printf("错误：新大小必须大于0\n");
//        return NULL;
//    }
//
//    // 分配新内存
//    int* new_arr = (int*)malloc(new_size * sizeof(int));
//
//    if (new_arr == NULL) {
//        printf("错误：内存分配失败\n");
//        return NULL;
//    }
//
//    // 复制旧数据
//    int copy_size = (old_size < new_size) ? old_size : new_size;
//    for (int i = 0; i < copy_size; i++) {
//        new_arr[i] = arr[i];
//    }
//
//    // 如果新数组更大，初始化新增部分
//    for (int i = copy_size; i < new_size; i++) {
//        new_arr[i] = default_value;
//    }
//
//    // 释放旧数组
//    free(arr);
//
//    return new_arr;
//}
//
///**
// * 释放数组
// * @param arr 数组指针
// */
//void free_array(int* arr) {
//    if (arr != NULL) {
//        free(arr);
//    }
//}
//
///**
// * 打印数组
// * @param arr 数组指针
// * @param size 数组大小
// */
//void print_array(int* arr, int size) {
//    if (arr == NULL || size <= 0) {
//        printf("数组为空\n");
//        return;
//    }
//
//    printf("[");
//    for (int i = 0; i < size; i++) {
//        printf("%d", arr[i]);
//        if (i < size - 1) {
//            printf(", ");
//        }
//    }
//    printf("]\n");
//}
////int* sortByBits(int* arr, int arrSize, int* returnSize) {
////    // 设置返回数组的大小
////    *returnSize = arrSize;
////
////    // 创建一个数组来存储每个数字和它的1的个数
////    int* result = (int*)malloc(arrSize * sizeof(int));
////    int* bitsCount = (int*)malloc(arrSize * sizeof(int));
////
////    // 计算每个数字的二进制1的个数
////    for (int i = 0; i < arrSize; i++) {
////        result[i] = arr[i];
////        bitsCount[i] = give_the_num_of_one(arr[i]);
////    }
////
////    // 冒泡排序（按1的个数排序，相同则按数值大小）
////    for (int i = 0; i < arrSize - 1; i++) {
////        for (int j = 0; j < arrSize - i - 1; j++) {
////            // 如果前一个1的个数大于后一个，或者个数相等但数值更大，就交换
////            if (bitsCount[j] > bitsCount[j + 1] ||
////                (bitsCount[j] == bitsCount[j + 1] && result[j] > result[j + 1])) {
////                // 交换数值
////                int temp = result[j];
////                result[j] = result[j + 1];
////                result[j + 1] = temp;
////
////                // 交换对应的1的个数
////                temp = bitsCount[j];
////                bitsCount[j] = bitsCount[j + 1];
////                bitsCount[j + 1] = temp;
////            }
////        }
////    }
////
////    free(bitsCount);  // 释放临时数组
////    return result;
////}
//
//
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//
////int give_the_num_of_one(int* arr, int arrsize, int* returnSize) {
////    int count = 0;
////    for (int i = 0; i <= arrsize; i++) {
////        int count = 0;
////        if (arr[i] == 1) {
////            count++;
////        }
////
////            
////    }
////
////    return count;
////
////}
//int give_the_num_of_one(int n) {
//
//    int count = 0;
//    while (n) {
//        count += n & 1;  
//        n >>= 1;         
//    }
//    return count;
//}
//
//
//
//
//
//void make_array(int array[], int array_size) {
//    for (int i = 0; i <= array_size; i++) {
//        array[i] = i;
//    }
//    // 不需要返回，直接修改传入的数组
//}
//
//
//
//void print_array(int array[], int array_size) {
//    for (int i = 0; i <= array_size; i++) {
//        printf("%d", array[i]);
//    }
//}
//int* to_malloc(int* arr, int arrsize) {//用于创建一个动态的数组空间
//    if (arr == NULL || arrsize <= 0) {
//        return NULL;  // 参数无效
//    }
//
//    int* returnarray = (int*)malloc(arrsize * sizeof(int));
//    if (returnarray == NULL) {
//        return NULL;  // 内存分配失败
//    }
//
//    for (int i = 0; i < arrsize; i++) {
//        returnarray[i] = arr[i];
//    }
//
//    return returnarray;
//}
//
//int* sortByBits(int* arr, int arrSize, int* returnSize) {
//    //int* arr = to_malloc(*arr, arrSize);
//
//
//
//
//
//
//
//
//}#include <stdio.h>
#include <stdlib.h>

/**
 * 创建一个指定大小的动态数组
 * @param size 数组大小
 * @return 成功返回数组指针，失败返回NULL
 */
int* create_array(int size) {
    if (size <= 0) {
        printf("错误：数组大小必须大于0\n");
        return NULL;
    }
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("错误：内存分配失败\n");
        return NULL;
    }
    return arr;
}

/**
 * 创建并初始化数组（所有元素设为指定值）
 * @param size 数组大小
 * @param init_value 初始值
 * @return 成功返回数组指针，失败返回NULL
 */
int* create_init_array(int size, int init_value) {
    int* arr = create_array(size);
    if (arr != NULL) {
        for (int i = 0; i < size; i++) {
            arr[i] = init_value;
        }
    }
    return arr;
}

/**
 * 创建并初始化数组（按顺序赋值 0,1,2,...）
 * @param size 数组大小
 * @return 成功返回数组指针，失败返回NULL
 */
int* create_sequence_array(int size) {
    int* arr = create_array(size);
    if (arr != NULL) {
        for (int i = 0; i < size; i++) {
            arr[i] = i;
        }
    }
    return arr;
}

/**
 * 复制数组
 * @param arr 原数组
 * @param size 数组大小
 * @return 成功返回新数组指针，失败返回NULL
 */
int* copy_array(int* arr, int size) {
    if (arr == NULL || size <= 0) {
        printf("错误：无效的参数\n");
        return NULL;
    }
    int* new_arr = create_array(size);
    if (new_arr != NULL) {
        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
    }
    return new_arr;
}

/**
 * 调整数组大小
 * @param arr 原数组指针
 * @param old_size 原数组大小
 * @param new_size 新数组大小
 * @param default_value 新增元素的默认值
 * @return 成功返回新数组指针，失败返回NULL（原数组保持不变）
 */
int* resize_array(int* arr, int old_size, int new_size, int default_value) {
    if (new_size <= 0) {
        printf("错误：新大小必须大于0\n");
        return NULL;
    }
    int* new_arr = (int*)malloc(new_size * sizeof(int));
    if (new_arr == NULL) {
        printf("错误：内存分配失败\n");
        return NULL;
    }
    int copy_size = (old_size < new_size) ? old_size : new_size;
    for (int i = 0; i < copy_size; i++) {
        new_arr[i] = arr[i];
    }
    for (int i = copy_size; i < new_size; i++) {
        new_arr[i] = default_value;
    }
    free(arr);
    return new_arr;
}

/**
 * 释放数组
 * @param arr 数组指针
 */
void free_array(int* arr) {
    if (arr != NULL) {
        free(arr);
    }
}

/**
 * 打印数组
 * @param arr 数组指针
 * @param size 数组大小
 */
void print_array(int* arr, int size) {
    if (arr == NULL || size <= 0) {
        printf("数组为空\n");
        return;
    }
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * 计算整数二进制中1的个数
 */
int give_the_num_of_one(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

/**
 * 填充数组为 0,1,2,...,array_size-1
 */
void make_array(int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {  // 修复越界：< 而不是 <=
        array[i] = i;
    }
}

/**
 * 打印数组元素（不换行）
 */
void print_array_simple(int array[], int array_size) {
    for (int i = 0; i < array_size; i++) {  // 修复越界
        printf("%d", array[i]);
    }
}

/**
 * 创建动态数组并复制原数组内容
 */
int* to_malloc(int* arr, int arrsize) {
    if (arr == NULL || arrsize <= 0) {
        return NULL;
    }
    int* returnarray = (int*)malloc(arrsize * sizeof(int));
    if (returnarray == NULL) {
        return NULL;
    }
    for (int i = 0; i < arrsize; i++) {
        returnarray[i] = arr[i];
    }
    return returnarray;
}

/**
 * 核心函数：按二进制1的个数排序
 * @param arr 输入数组
 * @param arrSize 数组大小
 * @param returnSize 输出数组大小（应等于arrSize）
 * @return 排序后的新数组（需调用者free）
 */
int* sortByBits(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    // 复制原数组
    int* result = copy_array(arr, arrSize);
    if (result == NULL) return NULL;

    // 创建存储1的个数的数组
    int* bitsCount = create_array(arrSize);
    if (bitsCount == NULL) {
        free_array(result);
        return NULL;
    }

    // 计算每个数字的二进制1的个数
    for (int i = 0; i < arrSize; i++) {
        bitsCount[i] = give_the_num_of_one(result[i]);
    }

    // 冒泡排序（按1的个数升序，相同则按数值升序）
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
            if (bitsCount[j] > bitsCount[j + 1] ||
                (bitsCount[j] == bitsCount[j + 1] && result[j] > result[j + 1])) {
                // 交换数值
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
                // 交换对应的1的个数
                temp = bitsCount[j];
                bitsCount[j] = bitsCount[j + 1];
                bitsCount[j + 1] = temp;
            }
        }
    }

    free_array(bitsCount);
    return result;
}