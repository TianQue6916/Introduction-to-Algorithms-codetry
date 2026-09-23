#ifndef HEAT_EQUATION_H
#define HEAT_EQUATION_H

#include "sparse_matrix.h"

// 求解一维热传导方程
void solve_heat_equation_1d(double alpha, double L, double T,
    int nx, int nt,
    double (*ic)(double),
    double (*bc_left)(double),
    double (*bc_right)(double),
    double (*source)(double, double),
    double** solution);

// 求解二维热传导方程
void solve_heat_equation_2d(double alpha, double Lx, double Ly, double T,
    int nx, int ny, int nt,
    double (*ic)(double, double),
    double*** solution);

// Thomas算法求解三对角系统
void thomas_solve(const BandMatrix* A, const double* b, double* x);

#endif