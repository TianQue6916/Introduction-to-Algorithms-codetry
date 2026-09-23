#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

#include "sparse_matrix.h"

// 矩阵-向量乘法
void csr_matvec(const CSRMatrix* A, const double* x, double* y);

// 共轭梯度法求解
int conjugate_gradient(const CSRMatrix* A, const double* b, double* x,
    int max_iter, double tol);

// 计算残差范数
double residual_norm(const CSRMatrix* A, const double* b, const double* x);

#endif