#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <stdlib.h>
#include <time.h>

// 计时器结构
typedef struct {
    clock_t start_time;
    clock_t end_time;
} Timer;

// 计时函数
void start_timer(Timer* timer);
double stop_timer(Timer* timer);

// 计算浮点运算次数估计
double estimate_flops_matvec(const CSRMatrix* A);

#endif