//#include <stdio.h>
//#include <math.h>
//#include<stdlib.h>
//#include <stdbool.h>
//
//
//
//int findFinalValue(int* nums, int numsSize, int original) {
//
//
//	for (int i = 0; i < numsSize; i++) {
//		if (nums[i] == original) {
//
//			original *= 2;
//			findFinalValue(nums, numsSize, original);
//
//
//		}
//		else {
//			return original;
//
//		}
//	
//	
//	
//	
//	}
//
//
//
//
//
//			return original;
//
//}

int findFinalValue(int* nums, int numsSize, int original) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == original) {
           
            return findFinalValue(nums, numsSize, original * 2);
        }
    }
  
    return original;
}