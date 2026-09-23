#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10000  // 最大矩阵大小
#define MAX_NONZERO 1000000  // 最大非零元数量

// COO格式 (坐标格式)
typedef struct {
    int row;
    int col;
    double value;
} COOElement;

typedef struct {
    COOElement* data;      // 动态数组
    int capacity;          // 当前分配容量
    int rows, cols, nnz;   // 行数、列数、非零元个数
} COOMatrix;

// CSR格式 (使用动态内存)
typedef struct {
    double* values;        // 非零元值
    int* col_indices;      // 列索引
    int* row_ptr;          // 行指针
    int rows, cols, nnz;
    int capacity;          // 值的容量
} CSRMatrix;

// 对角线存储格式
typedef struct {
    double* diag;          // 主对角线
    double* sub_diag;      // 次对角线
    double* super_diag;    // 上对角线
    int size;
    int bandwidth;         // 带宽
} BandMatrix;

// 函数声明
CSRMatrix coo_to_csr(const COOMatrix* coo);
COOMatrix csr_to_coo(const CSRMatrix* csr);

// 内存管理函数
COOMatrix create_coo_matrix(int rows, int cols, int expected_nnz);
void free_coo_matrix(COOMatrix* mat);
CSRMatrix create_csr_matrix(int rows, int cols, int expected_nnz);
void free_csr_matrix(CSRMatrix* mat);
BandMatrix create_band_matrix(int size, int bandwidth);
void free_band_matrix(BandMatrix* mat);

// 工具函数
double get_csr_element(const CSRMatrix* mat, int row, int col);
void set_csr_element(CSRMatrix* mat, int row, int col, double value);
double csr_frobenius_norm(const CSRMatrix* mat);

// 矩阵I/O函数
void save_matrix_to_file(const CSRMatrix* mat, const char* filename);
CSRMatrix load_matrix_from_file(const char* filename);
void print_csr_matrix(const CSRMatrix* mat, int max_rows, int max_cols);

#endif