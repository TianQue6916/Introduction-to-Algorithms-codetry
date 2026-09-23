//////#include<stdio.h>
//////
//////void print(int n, int array[]) {
//////	for (int i = 0; i < n; i++) {
//////		printf("%d   ", array[i]);
//////	}
//////	printf("\n");
//////}
//////
//////void verse(int* array, int start, int stop) {
//////	for (int i = stop - 1; i > start - 1; i--) {
//////		static int time = 0;
//////		int temp = array[start + time];
//////		array[start + time] = array[stop - time];
//////
//////		array[stop - time] = temp;
//////		time++;
//////		if (time > (stop - start) / 2 + 1) {
//////			break;
//////		}
//////
//////
//////	}
//////
//////}
//////
//////int main() {
//////	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
//////	int n = sizeof(array) / 4;
//////	printf("%d\n", n);
//////	verse(array, 1, 7);
//////	print(n, array);
//////
//////	verse(array, 8, 10);
//////	print(n, array);
//////
//////	verse(array, 1, 10);
//////
//////
//////	print(n, array);
//////	return 0;
//////}
//////
//////
//////
//////
//////
//////
//////
//////
///////*
//////
//////1 2 3 4 5 = 1,2,3  4,5 = 3,2,1  5,4 = 4 5 1 2 3//数组旋转  @1
//////4 5 1 2 3
//////
//////
//////依次向后复制，不断备份   @2
//////*/
////
////#include<stdio.h>
////
////void print(int n, int array[]) {
////    for (int i = 0; i < n; i++) {
////        printf("%d   ", array[i]);
////    }
////    printf("\n");
////}
////
////void verse(int* array, int start, int stop) {
////    // 转换为0-based索引
////    int left = start - 1;
////    int right = stop - 1;
////    int length = right - left + 1;
////
////    for (int i = 0; i < length / 2; i++) {
////        int temp = array[left + i];
////        array[left + i] = array[right - i];
////        array[right - i] = temp;
////    }
////}
////
////int main() {
////    int array[] = { 1,2,3,4,5,6,7,8,9,0 };
////    int n = sizeof(array) / sizeof(array[0]);
////
////    printf("数组长度: %d\n", n);
////    printf("原始数组: ");
////    print(n, array);
////
////    
////    verse(array, 1, 7);
////    printf("反转1-7: ");
////    print(n, array);
////
////    verse(array, 8, 10);
////    printf("反转8-10: ");
////    print(n, array);
////
////    verse(array, 1, 10);
////    printf("反转整个: ");
////    print(n, array);
////
////   
////    return 0;
////}
//#include<stdio.h>
//
//void print(int n, int array[]) {
//    for (int i = 0; i < n; i++) {
//        printf("%d   ", array[i]);
//    }
//    printf("\n");
//}
//
//void verse(int* array, int n) {
//    int start, stop;
//
//    // 输入要反转的区间
//    printf("请输入要反转的起始位置 (1-%d): ", n);
//    scanf_s("%d", &start);
//
//    printf("请输入要反转的结束位置 (%d-%d): ", start, n);
//    scanf_s("%d", &stop);
//
//    // 输入验证
//    if (start < 1 || stop > n || start > stop) {
//        printf("输入错误！\n");
//        return;
//    }
//
//    // 转换为0-based索引
//    int left = start - 1;
//    int right = stop - 1;
//
//    // 执行反转
//    for (int i = left, j = right; i < j; i++, j--) {
//        int temp = array[i];
//        array[i] = array[j];
//        array[j] = temp;
//    }
//
//    printf("已反转第%d到第%d个元素\n", start, stop);
//}
//
//int main() {
//    int array[] = { 1,2,3,4,5,6,7,8,9,0 };
//    int n = sizeof(array) / sizeof(array[0]);
//
//    printf("数组长度: %d\n", n);
//    printf("原始数组: ");
//    print(n, array);
//
//    // 让用户选择要反转的位置
//    char choice;
//    do {
//        verse(array, n);
//        printf("当前数组: ");
//        print(n, array);
//
//        printf("继续反转吗？(y/n): ");
//        scanf_s(" %c", &choice);  // 注意前面的空格，用于跳过换行符
//    } while (choice == 'y' || choice == 'Y');
//
//    return 0;
//}
#include<stdio.h>

void print(int n, int array[]) {
    printf("当前数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void verse(int* array, int start, int stop) {
    int left = start - 1;
    int right = stop - 1;

    for (int i = left, j = right; i < j; i++, j--) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// 数组旋转函数
void rotate_array(int arr[], int n, int k) {
    k = k % n;
    if (k == 0) return;

    
    verse(arr, 1, n - k);
   
    verse(arr, n - k + 1, n);
    
    verse(arr, 1, n);
}

void show_menu() {
    printf("\n=== 数组操作菜单 ===\n");
    printf("1. 反转指定区间\n");
    printf("2. 旋转数组\n");
    printf("3. 显示当前数组\n");
    printf("4. 重置数组\n");
    printf("5. 退出\n");
    printf("请选择操作 (1-5): ");
}

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
91, 92, 93, 94, 95, 96, 97, 98, 99, 100 };
    int n = sizeof(array) / sizeof(array[0]);
    int original[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
91, 92, 93, 94, 95, 96, 97, 98, 99, 100 };

    int choice;

    do {
        show_menu();
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {  // 反转指定区间
            int start, stop;
            printf("输入起始位置 (1-%d): ", n);
            scanf_s("%d", &start);
            printf("输入结束位置: ");
            scanf_s("%d", &stop);

            if (start < 1 || stop > n || start > stop) {
                printf("输入无效！\n");
            }
            else {
                verse(array, start, stop);
                printf("反转完成！\n");
                print(n, array);
            }
            break;
        }

        case 2: {  // 旋转数组
            int k;
            printf("输入旋转位数: ");
            scanf_s("%d", &k);

            rotate_array(array, n, k);
            printf("旋转完成！\n");
            print(n, array);
            break;
        }

        case 3:  // 显示数组
            print(n, array);
            break;

        case 4:  // 重置数组
            for (int i = 0; i < n; i++) {
                array[i] = original[i];
            }
            printf("数组已重置！\n");
            print(n, array);
            break;

        case 5:  // 退出
            printf("再见！\n");
            break;

        default:
            printf("无效选择！\n");
        }
    } while (choice != 5);

    return 0;
}