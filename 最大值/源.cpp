#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>

std::vector<std::vector<double>> generateMatrix(int rows, int cols) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1000.0);

    std::vector<std::vector<double>> matrix(rows, std::vector<double>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = dist(gen);
        }
    }
    return matrix;
}

void printMatrix(const std::vector<std::vector<double>>& matrix) {
    std::cout << "生成的50x50矩阵:" << std::endl;
    std::cout << "==========================================" << std::endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << std::fixed << std::setprecision(2) << std::setw(8) << matrix[i][j];
        }
        std::cout << " ..." << std::endl;
    }
    std::cout << " ..." << std::endl;
}

double findMaxValue(const std::vector<std::vector<double>>& matrix) {
    double max_val = matrix[0][0];
    for (const auto& row : matrix) {
        for (double val : row) {
            if (val > max_val) {
                max_val = val;
            }
        }
    }
    return max_val;
}

std::pair<int, int> findMaxPosition(const std::vector<std::vector<double>>& matrix) {
    double max_val = matrix[0][0];
    std::pair<int, int> position = { 0, 0 };

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                position = { i, j };
            }
        }
    }
    return position;
}

int main() {
    const int ROWS = 50;
    const int COLS = 50;

    std::cout << "正在生成50x50随机矩阵..." << std::endl;
    auto matrix = generateMatrix(ROWS, COLS);

    printMatrix(matrix);

    double max_value = findMaxValue(matrix);
    auto max_pos = findMaxPosition(matrix);

    std::cout << "\n计算结果:" << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "矩阵最大值: " << std::fixed << std::setprecision(4) << max_value << std::endl;
    std::cout << "最大值位置: 第" << max_pos.first + 1 << "行, 第" << max_pos.second + 1 << "列" << std::endl;
    std::cout << "矩阵维度: " << ROWS << " x " << COLS << std::endl;

    std::cout << "\n按回车键退出..." << std::endl;
    std::cin.get();

    return 0;
}