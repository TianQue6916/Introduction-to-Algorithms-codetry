#include <stdio.h>
#include <math.h>

////3827
//给你一个整数 n。
//
//如果一个整数的二进制表示中所有位都相同，则称其为 单比特数（Monobit）。
//
//返回范围[0, n]（包括两端）内 单比特数 的个数。



//
//代码中有多个错误：
//
//judge_way1函数：
//
//
//逻辑错误：判断条件 i == 1 << j - 1 并不能正确判断单比特数
//
//
//judge_way2函数：
//
//死循环：while(1) 没有退出条件
//
//
//逻辑错误：count = i - 1 赋值错误
//
//countMonobit函数：
//
//逻辑错误：用两个函数结果相等来判断返回1，但这并不是题目要求的功能
//
//函数没有实现题目要求的功能（统计单比特数个数）
//
//语法问题：
//
//注释中的"////3827" 虽然不会导致错误，但写法不规范


int judge_way1(int n) {
	int count = 0;

	if (n == 0) {

		count++;
		return count;
	}


	for (int i = 0; i <= n; i++) {
		//循环范围问题：内层循环 j <= i / 2 不合理
		for (int j = 0; j <= i; j++) {

			//逻辑错误：1 << j - 1 等价于 1 << (j - 1)，但运算符优先级问题导致计算错误
			if (i == (1 << j) - 1) {
				count++;


			}



		}





	}





	return count;
}
int judge_way2(int n) {
	int count = 0;
	if (n == 0) {

		count++;
		return count;
	}
	for (int i = 0; i <= n; i++) {
		

		//逻辑错误：循环内条件 if (1 << i - 1 > n) 永远不会成立，导致无法break
		if ((1 << i) - 1 > n) {
			count=i-1;
			return count+1;
		}

		

	}




	
}


int countMonobit(int n) {
	int count1 = 0, count2 = 0;

	count1 = judge_way1(n);

	//count2 = judge_way2(n);

	/*if (count1 == count2) {
		int count = count1;
		return count;
	}*/






	return count1;


}