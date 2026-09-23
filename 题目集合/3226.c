////// 3226
////
////#include <math.h>
////#include <stdio.h>
////
////long long transfer10_2(int n) {
////    // 这个函数可以把十进制组换到二进制，输出整数
////    int original = n, inter = 0, mod = 0, count = 0;
////    long long result = 0;
////    while (1) {
////
////        mod = original % 2;
////        inter = original / 2;
////        original = inter;
////
////        if (count != 0) {
////            result = result + mod * pow(10, count);
////            /*printf("r%d\n", result);*/
////        }
////        else {
////            result = mod;
////        }
////
////        count++;
////        // printf("mod%d\n", mod);
////        // printf("c%d\n", count);
////        // printf("%d\n", original);
////        // printf("%d\n", inter);
////
////        if (inter == 1) {
////
////            result = result + 1 * pow(10, count);
////            break;
////        }
////        else if (inter == 0) {
////
////            break;
////        }
////    }
////
////    return result;
////}
////
////int check(int n, int k) {
////    int count = 0;
////    long long n2 = transfer10_2(n);
////    // printf("%lld", n2);
////    long long k2 = transfer10_2(k);
////    // printf("%lld", k2);
////    long long inter_n = n2, mod_n = 0, inter_k = k2, mod_k = 0;
////    while (1) {
////        mod_n = inter_n % 10;
////        inter_n = inter_n / 10;
////        mod_k = inter_k % 10;
////        inter_k = inter_k / 10;
////        if (mod_n != mod_k) {
////            count++;
////            // printf("%d", count);
////        }
////        if (mod_n == 0 && mod_k == 1) {
////            return -1;  // n 的该位是 0，但需要变成 1，不可能
////        }
////        if (mod_n == 1 && mod_k == 0) {
////            count++;    // n 的该位是 1，可以改成 0
////        }
////        // mod_n == mod_k 的情况不变
////    }
////
////    return count;
////}
//
//
//// 3226
//
//#include <math.h>
//#include <stdio.h>
//
//// 修改：用数组存储二进制位
//void transfer10_2(int n, int bits[], int* len) {
//    // bits数组存储二进制位（从低位到高位）
//    // len返回实际位数
//    int index = 0;
//    if (n == 0) {
//        bits[0] = 0;
//        *len = 1;
//        return;
//    }
//
//    while (n > 0) {
//        bits[index++] = n % 2;
//        n /= 2;
//    }
//    *len = index;
//}
//
//int check(int n, int k) {
//    // 用数组存储二进制位（最大31位就够了，int最多31位有效位）
//    int n_bits[32] = { 0 };
//    int k_bits[32] = { 0 };
//    int n_len, k_len;
//
//    // 获取二进制位
//    transfer10_2(n, n_bits, &n_len);
//    transfer10_2(k, k_bits, &k_len);
//
//    // 取最大长度进行比较
//    int max_len = n_len > k_len ? n_len : k_len;
//    int count = 0;
//
//    for (int i = 0; i < max_len; i++) {
//        int bit_n = (i < n_len) ? n_bits[i] : 0;  // 超出长度补0
//        int bit_k = (i < k_len) ? k_bits[i] : 0;
//
//        if (bit_n == 0 && bit_k == 1) {
//            return -1;  // n的该位是0，但需要变成1，不可能
//        }
//        if (bit_n == 1 && bit_k == 0) {
//            count++;    // n的该位是1，可以改成0
//        }
//        // 相同的情况什么都不做
//    }
//
//    return count;
//}
//
//int minChanges(int n, int k) {
//    int x = check(n, k);
//    return x;
//}





int minChanges(int n, int k) {
    int res = 0;
    while (n > 0 || k > 0) {
        if ((n & 1) == 0 && (k & 1) == 1) {
            return -1;
        }
        if ((n & 1) == 1 && (k & 1) == 0) {
            res++;
        }
        n >>= 1;
        k >>= 1;
    }
    return res;
}

