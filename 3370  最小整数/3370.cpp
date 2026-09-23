//#include<math.h>
//#include<stdio.h>
//
//
//class Solution {
//public:
//	//int transfer10_2(int n) {
//	//	//这个函数可以把十进制组换到二进制，输出整数
//	//	int original = n, inter = 0, mod = 0, count = 0, result = 0;
//	//	while (1) {
//
//	//		mod = original % 2;
//	//		inter = original / 2;
//	//		original = inter;
//
//	//		if (count != 0) {
//	//			result = result + mod * pow(10, count);
//	//			/*printf("r%d\n", result);*/
//	//		}
//	//		else {
//	//			result = mod;
//	//		}
//
//	//		count++;
//	//		/*printf("mod%d\n", mod);
//	//		printf("c%d\n", count);
//	//		printf("%d\n", original);
//	//		printf("%d\n", inter);*/
//
//	//		if (inter == 1) {
//
//	//			result = result + 1 * pow(10, count);
//	//			break;
//	//		}
//	//		else if (inter == 0) {
//
//	//			break;
//
//	//		}
//
//
//
//	//	}
//
//
//
//	//	return result;
//	//}
//
//	/*int transfer2_10(int n) {
//		int result = 0;
//
//
//
//
//
//
//
//		return result;
//	}*/
//
//
//
//	//int arraycreate() {
//
//
//	//	return
//	//}
//	//													2^n-1!!
//
//
//
//	int judge(int i) {
//		int n=0;
//		while (1) {
//
//			if (i == pow(2, n)-1) {
//				break;
//			}
//			if (pow(2, n) - 1 > i) {
//				break;
//			}
//				n++;
//		}
//		return pow(2, n)-1;
//
//	}
//
//
//
//
//	int smallestNumber(int n) {
//		//int x = 0;
//		///*n = transfer(n);*/
//		//while (1) {
//		//	x = transfer(x);
//		//	if (x >= n) {
//
//		//	}
//		//}
//		//return;
//
//		//return;
//		n = 8;
//		int inter_judge=judge(n);
//		printf("%d", inter_judge);
//		
//
//	}
//};