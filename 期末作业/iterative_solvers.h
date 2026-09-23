#ifndef ITERATIVE_SOLVERS_H
#define ITERATIVE_SOLVERS_H

#include "sparse_matrix.h"

// 共轭梯度法 (对称正定矩阵)
int conjugate_gradient(const CSRMatrix* A, const double* b, double* x,
    int max_iter, double tol);
int pcg(const CSRMatrix* A, const double* b, double* x,
    int max_iter, double tol,
    void (*precond)(const double*, double*));

// GMRES (通用矩阵)
int gmres(const CSRMatrix* A, const double* b, double* x,
    int restart, int max_iter, double tol);
int fgmres(const CSRMatrix* A, const double* b, double* x,
    int m, int max_iter, double tol,
    void (*precond)(const double*, double*));

// 逐次超松弛法 (SOR)
int sor(const CSRMatrix* A, const double* b, double* x,
    double omega, int max_iter, double tol);

// 计算残差范数
double residual_norm(const CSRMatrix* A, const double* b, const double* x);

#endif