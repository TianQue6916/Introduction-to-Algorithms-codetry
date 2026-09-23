#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// 如果没有M_PI定义，定义它
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// ==================== 数据结构定义 ====================

// CSR稀疏矩阵结构
typedef struct {
    double* values;        // 非零元值
    int* col_indices;      // 列索引
    int* row_ptr;          // 行指针
    int rows, cols, nnz;   // 行数、列数、非零元个数
} CSRMatrix;

// 计时器结构
typedef struct {
    clock_t start_time;
    clock_t end_time;
} Timer;

// ==================== 函数声明 ====================

// 内存管理函数
CSRMatrix create_csr_matrix(int rows, int cols, int expected_nnz);
void free_csr_matrix(CSRMatrix* mat);

// 矩阵运算函数
void csr_matvec(const CSRMatrix* A, const double* x, double* y);
int conjugate_gradient(const CSRMatrix* A, const double* b, double* x,
    int max_iter, double tol);
double residual_norm(const CSRMatrix* A, const double* b, const double* x);

// 性能测试函数
void start_timer(Timer* timer);
double stop_timer(Timer* timer);
double estimate_flops_matvec(const CSRMatrix* A);

// 测试函数
void solve_heat_equation_simple();
void test_sparse_matrix_performance();
void test_iterative_solvers();

// ==================== 辅助函数定义 ====================

// 创建CSR矩阵
CSRMatrix create_csr_matrix(int rows, int cols, int expected_nnz) {
    CSRMatrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.nnz = 0;

    // 确保分配至少一些内存
    int capacity = expected_nnz > 0 ? expected_nnz : 100;
    mat.values = (double*)malloc(capacity * sizeof(double));
    mat.col_indices = (int*)malloc(capacity * sizeof(int));
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
        mat->rows = mat->cols = mat->nnz = 0;
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
        if (r) free(r);
        if (p) free(p);
        if (Ap) free(Ap);
        return -1;
    }

    // 计算初始残差 r = b - Ax
    csr_matvec(A, x, Ap);
    for (int i = 0; i < n; i++) {
        r[i] = b[i] - Ap[i];
        p[i] = r[i];
    }

    double rsold = 0.0;
    for (int i = 0; i < n; i++) {
        rsold += r[i] * r[i];
    }

    double rsnew, alpha, beta;
    double b_norm = 0.0;
    for (int i = 0; i < n; i++) {
        b_norm += b[i] * b[i];
    }
    b_norm = sqrt(b_norm);

    int iter = 0;
    while (iter < max_iter && sqrt(rsold) > tol * b_norm) {
        csr_matvec(A, p, Ap);

        double pAp = 0.0;
        for (int i = 0; i < n; i++) {
            pAp += p[i] * Ap[i];
        }

        alpha = rsold / pAp;

        // 更新解和残差
        for (int i = 0; i < n; i++) {
            x[i] += alpha * p[i];
            r[i] -= alpha * Ap[i];
        }

        rsnew = 0.0;
        for (int i = 0; i < n; i++) {
            rsnew += r[i] * r[i];
        }

        beta = rsnew / rsold;

        // 更新搜索方向
        for (int i = 0; i < n; i++) {
            p[i] = r[i] + beta * p[i];
        }

        rsold = rsnew;
        iter++;
    }

    free(r);
    free(p);
    free(Ap);

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

// ==================== 热传导方程求解 ====================

double initial_condition(double x) {
    return sin(M_PI * x);
}

double boundary_left(double t) {
    (void)t; // 避免未使用参数警告
    return 0.0;
}

double boundary_right(double t) {
    (void)t; // 避免未使用参数警告
    return 0.0;
}

double source_term(double x, double t) {
    (void)x; (void)t; // 避免未使用参数警告
    return 0.0;
}

void solve_heat_equation_simple() {
    printf("===== 一维热传导方程求解 =====\n");

    double alpha = 1.0;      // 热扩散系数
    double L = 1.0;          // 区域长度
    double T = 0.1;          // 总时间

    int nx = 50;             // 空间网格数
    int nt = 100;            // 时间步数

    double dx = L / (nx - 1);
    double dt = T / nt;
    double r = alpha * dt / (dx * dx);

    // 分配内存存储解
    double** solution = (double**)malloc(nt * sizeof(double*));
    if (solution == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return;
    }

    for (int i = 0; i < nt; i++) {
        solution[i] = (double*)malloc(nx * sizeof(double));
        if (solution[i] == NULL) {
            fprintf(stderr, "内存分配失败\n");
            for (int j = 0; j < i; j++) {
                free(solution[j]);
            }
            free(solution);
            return;
        }
    }

    double* u_old = (double*)malloc(nx * sizeof(double));
    double* u_new = (double*)malloc(nx * sizeof(double));

    if (u_old == NULL || u_new == NULL) {
        fprintf(stderr, "内存分配失败\n");
        free(u_old);
        free(u_new);
        for (int i = 0; i < nt; i++) free(solution[i]);
        free(solution);
        return;
    }

    // 初始条件
    for (int i = 0; i < nx; i++) {
        double x = i * dx;
        u_old[i] = initial_condition(x);
    }

    // 时间推进（使用显式格式简化）
    for (int t_step = 0; t_step < nt; t_step++) {
        double current_time = t_step * dt;

        // 边界条件
        u_new[0] = boundary_left(current_time);
        u_new[nx - 1] = boundary_right(current_time);

        // 内部点更新
        for (int i = 1; i < nx - 1; i++) {
            double x = i * dx;
            u_new[i] = u_old[i] + r * (u_old[i - 1] - 2 * u_old[i] + u_old[i + 1])
                + dt * source_term(x, current_time);
        }

        // 保存当前时间步的解
        for (int i = 0; i < nx; i++) {
            solution[t_step][i] = u_new[i];
        }

        // 更新旧解
        double* temp = u_old;
        u_old = u_new;
        u_new = temp;
    }

    printf("求解完成！\n");

    // 输出最终时刻的解
    printf("\n最终时刻的温度分布（部分显示）：\n");
    int step = nx / 10;
    if (step < 1) step = 1;
    for (int i = 0; i < nx; i += step) {
        printf("x=%.3f: u=%.6f\n", i * dx, solution[nt - 1][i]);
    }

    // 计算误差（与解析解比较）
    double error = 0.0;
    for (int i = 0; i < nx; i++) {
        double x = i * dx;
        double exact = exp(-M_PI * M_PI * alpha * T) * sin(M_PI * x);
        error += (solution[nt - 1][i] - exact) * (solution[nt - 1][i] - exact);
    }
    error = sqrt(error / nx);
    printf("\nL2误差: %.6e\n", error);

    // 清理内存
    free(u_old);
    free(u_new);
    for (int i = 0; i < nt; i++) {
        free(solution[i]);
    }
    free(solution);
}

// ==================== 稀疏矩阵性能测试 ====================

void test_sparse_matrix_performance() {
    printf("\n===== 稀疏矩阵运算性能测试 =====\n");

    int n = 1000;

    // 创建CSR矩阵
    CSRMatrix A = create_csr_matrix(n, n, 3 * n);

    // 创建三对角矩阵 [-1, 2, -1]
    A.row_ptr[0] = 0;
    int nnz = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            A.col_indices[nnz] = i - 1;
            A.values[nnz] = -1.0;
            nnz++;
        }

        A.col_indices[nnz] = i;
        A.values[nnz] = 2.0;
        nnz++;

        if (i < n - 1) {
            A.col_indices[nnz] = i + 1;
            A.values[nnz] = -1.0;
            nnz++;
        }

        A.row_ptr[i + 1] = nnz;
    }
    A.nnz = nnz;

    // 生成随机向量
    double* x = (double*)malloc(n * sizeof(double));
    double* y = (double*)malloc(n * sizeof(double));
    if (x == NULL || y == NULL) {
        fprintf(stderr, "内存分配失败\n");
        free_csr_matrix(&A);
        if (x) free(x);
        if (y) free(y);
        return;
    }

    for (int i = 0; i < n; i++) {
        x[i] = (double)rand() / RAND_MAX;
    }

    // 性能测试
    Timer timer;

    start_timer(&timer);
    for (int i = 0; i < 100; i++) {
        csr_matvec(&A, x, y);
    }
    double time_matvec = stop_timer(&timer);

    printf("矩阵-向量乘法100次耗时: %.3f ms\n", time_matvec);
    printf("平均每次耗时: %.3f ms\n", time_matvec / 100);

    // 估计FLOPS
    double flops_per_matvec = estimate_flops_matvec(&A);
    double total_flops = flops_per_matvec * 100;
    double gflops = total_flops / (time_matvec * 1e-3) / 1e9;

    printf("估计性能: %.2f GFLOPS\n", gflops);

    // 清理内存
    free_csr_matrix(&A);
    free(x);
    free(y);
}

// ==================== 迭代求解器测试 ====================

void test_iterative_solvers() {
    printf("\n===== 迭代求解器测试 =====\n");

    // 生成简单测试矩阵（三对角矩阵）
    int n = 100;
    CSRMatrix A = create_csr_matrix(n, n, 3 * n);
    double* b = (double*)malloc(n * sizeof(double));
    double* x = (double*)malloc(n * sizeof(double));

    if (b == NULL || x == NULL) {
        fprintf(stderr, "内存分配失败\n");
        free_csr_matrix(&A);
        if (b) free(b);
        if (x) free(x);
        return;
    }

    // 构建三对角矩阵 [-1, 2, -1]
    A.row_ptr[0] = 0;
    int nnz = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            A.col_indices[nnz] = i - 1;
            A.values[nnz] = -1.0;
            nnz++;
        }

        A.col_indices[nnz] = i;
        A.values[nnz] = 2.0;
        nnz++;

        if (i < n - 1) {
            A.col_indices[nnz] = i + 1;
            A.values[nnz] = -1.0;
            nnz++;
        }

        A.row_ptr[i + 1] = nnz;
    }
    A.nnz = nnz;

    // 生成右端项 b = sin(i*pi/(n+1))
    for (int i = 0; i < n; i++) {
        b[i] = sin(M_PI * (i + 1) / (n + 1));
        x[i] = 0.0;
    }

    // 使用共轭梯度法求解
    int max_iter = 1000;
    double tol = 1e-8;

    int iter = conjugate_gradient(&A, b, x, max_iter, tol);

    printf("共轭梯度法迭代次数: %d\n", iter);
    printf("最终残差: %.6e\n", residual_norm(&A, b, x));

    // 验证解的质量（简化验证）
    double error = 0.0;
    for (int i = 0; i < n; i++) {
        double exact = b[i] / (2.0 - 2.0 * cos(M_PI / (n + 1)));  // 近似精确解
        error += (x[i] - exact) * (x[i] - exact);
    }
    error = sqrt(error / n);
    printf("与近似精确解的误差: %.6e\n", error);

    // 清理内存
    free_csr_matrix(&A);
    free(b);
    free(x);
}

// ==================== 主函数 ====================

int main() {
    printf("稀疏矩阵计算库 - 综合测试\n");
    printf("==========================\n\n");

    // 设置随机种子
    srand(42);

    // 运行测试
    printf("测试1: 热传导方程求解\n");
    solve_heat_equation_simple();

    printf("\n测试2: 稀疏矩阵性能测试\n");
    test_sparse_matrix_performance();

    printf("\n测试3: 迭代求解器测试\n");
    test_iterative_solvers();

    printf("\n所有测试完成！\n");

    return 0;
}