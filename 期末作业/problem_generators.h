#pragma once
#ifndef PROBLEM_GENERATORS_H
#define PROBLEM_GENERATORS_H

#include "sparse_matrix.h"

// 生成一维泊松方程矩阵
void poisson_1d(int n, CSRMatrix* A, double* b);

// 生成二维泊松方程矩阵
void poisson_2d(int nx, int ny, CSRMatrix* A, double* b);

// 生成随机稀疏矩阵
void random_sparse_matrix(int n, double density, CSRMatrix* A);

#endif