//#include<math.h>
//#include<stdio.h>
//#include<stdlib.h>
//
//
////int transfer(int n) {
////	int original = n, inter = 0, mod = 0, count = 0, result = 0;
////	while (1) {
////
////		mod = original % 2;
////		inter = original / 2;
////		original = inter;
////
////		if (count != 0) {
////			result = result + mod * pow(10, count);
////			/*printf("r%d\n", result);*/
////		}
////		else {
////			result = mod;
////		}
////
////		count++;
////		/*printf("mod%d\n", mod);
////		printf("c%d\n", count);
////		printf("%d\n", original);
////		printf("%d\n", inter);*/
////		
////		if (inter == 1) {
////			
////			result = result + 1 * pow(10, count);
////			break;
////		}
////		else if (inter == 0) {
////			
////			break;
////
////		}
////
////
////
////	}
////
////
////
////		return result;
////}
//
//
//
//
//
//int judge(int i) {
//	int n=0;
//	while (1) {
//
//		if (i == pow(2, n) - 1) {
//			break;
//		}
//		if (pow(2, n) - 1 > i) {
//			break;
//		}
//		n++;
//	}
//	return pow(2, n) - 1;
//
//}
//
//
//
//int main() {
//	int n = 16;
//	int result = judge(n);
//	printf("%d", result);
//
//	return 0;
//}