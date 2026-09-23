#include <stdio.h>
#include <math.h>
#include<stdlib.h>

//int return_defferent(int x, int y) {
//	int count = 0;
//	int judge = 0; 
//	while (1) {
//		judge=(x ^ y);
//		if (judge) {
//			count++;
//		}
//		if (x == 0 && y == 0) {
//			break;
//		}
//		x >>= 1;
//		y >>= 1;
//	}
//	
//	return count;
//
//}

int hammingDistance1(int x, int y) {
    int count = 0;
    while (x || y) {
        if ((x & 1) != (y & 1)) {
            count++;
        }
        x >>= 1;
        y >>= 1;
    }
    return count;
}

//这个方法十分重要！！！


//方法三：Brian Kernighan 算法
//思路及算法
//
//在方法二中，对于 s = (10001100)
//2
//​
//的情况，我们需要循环右移 8 次才能得到答案。而实际上如果我们可以跳过两个 1 之间的 0，直接对 1 进行计数，那么就只需要循环 3 次即可。
//
//我们可以使用 Brian Kernighan 算法进行优化，具体地，该算法可以被描述为这样一个结论：记 f(x) 表示 x 和 x−1 进行与运算所得的结果（即 f(x) = x  & (x−1)），那么 f(x) 恰为 x 删去其二进制表示中最右侧的 1 的结果。
//
//
//
//基于该算法，当我们计算出 s = x⊕y，只需要不断让 s = f(s)，直到 s = 0 即可。这样每循环一次，s 都会删去其二进制表示中最右侧的 1，最终循环的次数即为 s 的二进制表示中 1 的数量。
//
//注意
//
//Brian Kernighan 算法发布在 1988 年出版的 The C Programming Language (Second Edition) 的练习中（由 Brian W.Kernighan 和 Dennis M.Ritchie 编写），但是 Donald Knuth 在 2006 年 4 月 19 日指出，该方法第一次是由 Peter Wegner 在 1960 年的 CACM3 上出版。可以在上述书籍中找到更多位操作的技巧。
//
//作者：力扣官方题解
//链接：https ://leetcode.cn/problems/hamming-distance/solutions/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int hammingDistance2(int x, int y) {
    int diff = x ^ y;  // 不同的位标记为 1
    int count = 0;

    while (diff) {
        diff &= (diff - 1);  // 每次去掉一个 1
        count++;             // 计一次数
    }

    return count;
}


