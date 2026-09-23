#include "sparse_matrix.h"
#include "matrix_ops.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// 创建CSR矩阵
CSRMatrix create_csr_matrix(int rows, int cols, int expected_nnz) {
    CSRMatrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.nnz = 0;
    mat.capacity = expected_nnz > 0 ? expected_nnz : 100;

    mat.values = (double*)malloc(mat.capacity * sizeof(double));
    mat.col_indices = (int*)malloc(mat.capacity * sizeof(int));
    mat.row_ptr = (int*)malloc((rows + 1) * sizeof(int));

    if (mat.values == NULL || mat.col_indices == NULL || mat.row_ptr == NULL) {
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);
    }

    // 初始化行指针
    for (int i = 0; i <= rows; i++) {
        mat.row_ptr[i] = 0;
    }

    return mat;
}

// 释放CSR矩阵
void free_csr_matrix(CSRMatrix* mat) {
    if (mat) {
        if (mat->values) free(mat->values);
        if (mat->col_indices) free(mat->col_indices);
        if (mat->row_ptr) free(mat->row_ptr);
        mat->values = NULL;
        mat->col_indices = NULL;
        mat->row_ptr = NULL;
        mat->capacity = 0;
        mat->nnz = 0;
    }
}

// 矩阵向量乘法
void csr_matvec(const CSRMatrix* A, const double* x, double* y) {
    for (int i = 0; i < A->rows; i++) {
        y[i] = 0.0;
        for (int j = A->row_ptr[i]; j < A->row_ptr[i + 1]; j++) {
            y[i] += A->values[j] * x[A->col_indices[j]];
        }
    }
}

// 共轭梯度法
int conjugate_gradient(const CSRMatrix* A, const double* b, double* x,
    int max_iter, double tol) {
    int n = A->rows;
    double* r = (double*)malloc(n * sizeof(double));
    double* p = (double*)malloc(n * sizeof(double));
    double* Ap = (double*)malloc(n * sizeof(double));

    if (r == NULL || p == NULL || Ap == NULL) {
        fprintf(stderr, "内存分配失败\n");
        free(r); free(p); free(Ap);
        return -1;
    }

    // 计算初始残差 r = b - Ax
    csr_matvec(A, x, Ap);
    for (int i = 0; i < n; i++) {
        r[i] = b[i] - Ap[i];
        p[i] = r[i];
    }

    double rsold = 0.0;
    for (int i = 0; i < n; i++) rsold += r[i] * r[i];

    double rsnew, alpha, beta;
    double b_norm = 0.0;
    for (int i = 0; i < n; i++) b_norm += b[i] * b[i];
    b_norm = sqrt(b_norm);

    int iter = 0;
    while (iter < max_iter && sqrt(rsold) > tol * b_norm) {
        csr_matvec(A, p, Ap);

        double pAp = 0.0;
        for (int i = 0; i < n; i++) pAp += p[i] * Ap[i];

        alpha = rsold / pAp;

        // 更新解和残差
        for (int i = 0; i < n; i++) {
            x[i] += alpha * p[i];
            r[i] -= alpha * Ap[i];
        }

        rsnew = 0.0;
        for (int i = 0; i < n; i++) rsnew += r[i] * r[i];

        beta = rsnew / rsold;

        // 更新搜索方向
        for (int i = 0; i < n; i++) {
            p[i] = r[i] + beta * p[i];
        }

        rsold = rsnew;
        iter++;
    }

    free(r); free(p); free(Ap);
    return iter;
}

// 计算残差范数
double residual_norm(const CSRMatrix* A, const double* b, const double* x) {
    int n = A->rows;
    double* Ax = (double*)malloc(n * sizeof(double));

    if (Ax == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return -1.0;
    }

    csr_matvec(A, x, Ax);

    double norm = 0.0;
    for (int i = 0; i < n; i++) {
        double residual = b[i] - Ax[i];
        norm += residual * residual;
    }

    free(Ax);
    return sqrt(norm);
}

// 开始计时
void start_timer(Timer* timer) {
    timer->start_time = clock();
}

// 停止计时并返回毫秒数
double stop_timer(Timer* timer) {
    timer->end_time = clock();
    double elapsed = (double)(timer->end_time - timer->start_time) * 1000.0 / CLOCKS_PER_SEC;
    return elapsed;
}

// 估计矩阵向量乘法的FLOPS
double estimate_flops_matvec(const CSRMatrix* A) {
    // 每个非零元需要一次乘法和一次加法
    return 2.0 * A->nnz;
}