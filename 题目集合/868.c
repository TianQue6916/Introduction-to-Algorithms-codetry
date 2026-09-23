//#include <stdio.h>
//#include <math.h>
//#include<stdlib.h>
//
//
//
//
//
//int main(void) {
//	int n = 5;
//	int mod = 0, result = 0;
//	int count_bit = 0, count_1time = 0,count_1bit=0,count_1_alltime=0;
//	while (n) {
//		mod = n & 1;
//		if (mod) {
//			count_1time++;
//			count_1bit = count_bit;
//		}
//		if (count_1time % 2 == 0) {
//			count_1_alltime++;
//			result = count_bit - count_1bit;
//			count_1time = 0;
//		}
//
//
//		if (!count_1_alltime) {
//			return 0;
//		}
//
//		count_bit++;
//		n >>= 1;
//
//	}
//	int max = 0;
//	if (result >= max) {
//		max = result;
//		return result;
//
//	}
//	else {
//		return result;
//	}
//
//
//
//	
//}

#include <stdio.h>

int main(void) {
    int n = 22;  // 可以改成任意测试数：5, 22, 13等
    int mod = 0;
    int result = 0;           // 最终结果（最大距离）
    int count_bit = 0;        // 当前位的位置
    int count_1time = 0;      // 改成：已经遇到的1的总个数
    int last_pos = -1;        // 新增：上一个1的位置（用count_1bit改的）
    int current_dist = 0;     // 新增：当前计算的距离

    while (n) {
        mod = n & 1;  // 取当前最低位

        if (mod) {  // 如果当前位是1
            count_1time++;  // 遇到1的总数加1

            if (last_pos != -1) {  // 如果之前遇到过1
                current_dist = count_bit - last_pos;  // 计算距离
                if (current_dist > result) {  // 更新最大距离
                    result = current_dist;
                }
            }

            last_pos = count_bit;  // 记录当前1的位置
        }

        count_bit++;  // 位置加1
        n >>= 1;      // 右移处理下一位
    }

    // 如果遇到的1少于2个，返回0
    if (count_1time < 2) {
        return 0;
    }

    return result;
}