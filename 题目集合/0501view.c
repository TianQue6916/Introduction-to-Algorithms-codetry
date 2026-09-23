//#include <stdio.h>
//#include <math.h>
//#include<stdlib.h>
//
//int insertBits(int N, int M, int i, int j) {
//	int mask_last = (1 << i) - 1;
//	int N_last = N&mask_last;
//	int m = 0;
//
//
//
//	for (int a = i; a <= j; a++) {
//
//		N >>= a;
//		m = ((M >> (a - i))&1) ;
//		N = m & N;
//
//	}
//
//
//
//
//
//
//
//
//
//
//
//
//	return N;
//}
//
int insertBits(int N, int M, int i, int j) {
    int mask_last = (1 << i) - 1;
    int N_last = N & mask_last;


    N >>= i;


    for (int a = 0; a <= j - i; a++) {
       
        int m_bit = (M >> a) & 1;

        if (m_bit) {
            
            N |= (1 << a);
        }
        else {
           
            N &= ~(1 << a);
        }
    }

   
    return (N << i) | N_last;
}