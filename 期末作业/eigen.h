#pragma once
#include "eigen.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

// 带加速的幂法（Aitken加速）
double power_method_aitken(const CSRMatrix* A, double* eigenvector,
    int max_iter, double tol) {

    int n = A->rows;
    double* x = malloc(n * sizeof(double));
    double* y = malloc(n * sizeof(double));

    // 随机初始化
    for (int i = 0; i < n; i++) {
        x[i] = (double)rand() / RAND_MAX;
    }

    // 归一化
    double norm = 0.0;
    for (int i = 0; i < n; i++) norm += x[i] * x[i];
    norm = sqrt(norm);
    for (int i = 0; i < n; i++) x[i] /= norm;

    double lambda_old = 0.0;
    double lambda_new;
    double lambda_accel;  // Aitken加速后的特征值

    for (int iter = 0; iter < max_iter; iter++) {
        // y = A*x
        csr_matvec_optimized(A, x, y);

        // Rayleigh商估计特征值
        lambda_new = 0.0;
        for (int i = 0; i < n; i++) lambda_new += y[i] * x[i];

        // Aitken加速（每三次迭代应用一次）
        if (iter >= 2 && iter % 3 == 0) {
            lambda_accel = lambda_new -
                (lambda_new - lambda_old) * (lambda_new - lambda_old) /
                (lambda_new - 2 * lambda_old + lambda_accel);
        }
        else {
            lambda_accel = lambda_new;
        }

        // 检查收敛
        if (iter > 0 && fabs(lambda_accel - lambda_old) < tol * fabs(lambda_accel)) {
            memcpy(eigenvector, x, n * sizeof(double));
            free(x); free(y);
            return lambda_accel;
        }

        // 归一化y得到新的x
        norm = 0.0;
        for (int i = 0; i < n; i++) norm += y[i] * y[i];
        norm = sqrt(norm);
        for (int i = 0; i < n; i++) x[i] = y[i] / norm;

        lambda_old = lambda_accel;
    }

    memcpy(eigenvector, x, n * sizeof(double));
    free(x); free(y);
    return lambda_new;
}

// 隐式重启Arnoldi方法（用于计算多个特征值）
void arnoldi_method(const CSRMatrix* A, int k, int m, double* eigenvalues,
    double** eigenvectors, int max_iter, double tol) {

    int n = A->rows;
    double** V = malloc((m + 1) * sizeof(double*));
    double* H = calloc((m + 1) * m, sizeof(double));

    for (int i = 0; i <= m; i++) {
        V[i] = malloc(n * sizeof(double));
    }

    // 初始化第一个向量
    for (int i = 0; i < n; i++) {
        V[0][i] = (double)rand() / RAND_MAX;
    }

    // 归一化
    double norm = 0.0;
    for (int i = 0; i < n; i++) norm += V[0][i] * V[0][i];
    norm = sqrt(norm);
    for (int i = 0; i < n; i++) V[0][i] /= norm;

    // Arnoldi过程
    for (int j = 0; j < m; j++) {
        // w = A * V[j]
        csr_matvec_optimized(A, V[j], V[j + 1]);

        // 修正的Gram-Schmidt正交化
        for (int i = 0; i <= j; i++) {
            H[i * m + j] = 0.0;
            for (int k = 0; k < n; k++) {
                H[i * m + j] += V[j + 1][k] * V[i][k];
            }

            for (int k = 0; k < n; k++) {
                V[j + 1][k] -= H[i * m + j] * V[i][k];
            }
        }

        H[(j + 1) * m + j] = 0.0;
        for (int k = 0; k < n; k++) {
            H[(j + 1) * m + j] += V[j + 1][k] * V[j + 1][k];
        }
        H[(j + 1) * m + j] = sqrt(H[(j + 1) * m + j]);

        // 归一化
        if (fabs(H[(j + 1) * m + j]) > 1e-12) {
            for (int k = 0; k < n; k++) {
                V[j + 1][k] /= H[(j + 1) * m + j];
            }
        }
    }

    // 计算Hessenberg矩阵的特征值（使用QR算法）
    // ... QR算法的实现

    // 提取特征向量
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            eigenvectors[i][j] = 0.0;
            for (int l = 0; l < m; l++) {
                eigenvectors[i][j] += V[l][j] * /* Q的特征向量分量 */;
            }
        }
    }

    // 清理内存
    for (int i = 0; i <= m; i++) free(V[i]);
    free(V); free(H);
}