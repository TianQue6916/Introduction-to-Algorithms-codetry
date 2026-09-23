#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <chrono>
class MatrixMaxFinder {
private:
    std::vector<std::vector<double>> matrix;
    int rows, cols;
public:
    MatrixMaxFinder(int r, int c) : rows(r), cols(c) {
        matrix.resize(rows, std::vector<double>(cols));
    }
    void generateRandomMatrix(double min_val = 0.0, double max_val = 1000.0) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(min_val, max_val);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = dist(gen);
            }
        }
    }

    void printPartialMatrix(int show_rows = 5, int show_cols = 5) {
        std::cout << "生成的" << rows << "x" << cols << "矩阵 (显示前"
            << show_rows << "x" << show_cols << "):" << std::endl;
        std::cout << "==========================================" << std::endl;

        for (int i = 0; i < std::min(show_rows, rows); i++) {
            for (int j = 0; j < std::min(show_cols, cols); j++) {
                std::cout << std::fixed << std::setprecision(2) << std::setw(8) << matrix[i][j];
            }
            if (cols > show_cols) std::cout << " ...";
            std::cout << std::endl;
        }
        if (rows > show_rows) std::cout << " ..." << std::endl;
    }

    double findMaxSimple() {
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

    std::pair<int, int> findMaxPosition() {
        double max_val = matrix[0][0];
        std::pair<int, int> pos = { 0, 0 };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] > max_val) {
                    max_val = matrix[i][j];
                    pos = { i, j };
                }
            }
        }
        return pos;
    }

    double findMaxByRow() {
        double max_val = matrix[0][0];
        for (int i = 0; i < rows; i++) {
            double row_max = *std::max_element(matrix[i].begin(), matrix[i].end());
            if (row_max > max_val) {
                max_val = row_max;
            }
        }
        return max_val;
    }

    void analyzeMatrix() {
        double max_val = findMaxSimple();
        auto max_pos = findMaxPosition();
        double min_val = matrix[0][0];
        double sum = 0;
        int count = 0;

        for (const auto& row : matrix) {
            for (double val : row) {
                if (val < min_val) min_val = val;
                sum += val;
                count++;
            }
        }
        double average = sum / count;

        std::cout << "\n=== 矩阵分析结果 ===" << std::endl;
        std::cout << "矩阵维度: " << rows << " x " << cols << std::endl;
        std::cout << "最大值: " << std::fixed << std::setprecision(4) << max_val << std::endl;
        std::cout << "最大值位置: 第" << max_pos.first + 1 << "行, 第" << max_pos.second + 1 << "列" << std::endl;
        std::cout << "最小值: " << std::fixed << std::setprecision(4) << min_val << std::endl;
        std::cout << "平均值: " << std::fixed << std::setprecision(4) << average << std::endl;
        std::cout << "数值范围: [" << min_val << ", " << max_val << "]" << std::endl;
    }

    void findTopNValues(int n = 5) {
        std::vector<std::tuple<double, int, int>> all_values;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                all_values.emplace_back(matrix[i][j], i, j);
            }
        }

        std::sort(all_values.begin(), all_values.end(),
            [](const auto& a, const auto& b) {
                return std::get<0>(a) > std::get<0>(b);
            });

        std::cout << "\n=== 前" << n << "个最大值 ===" << std::endl;
        for (int i = 0; i < std::min(n, (int)all_values.size()); i++) {
            auto [value, row, col] = all_values[i];
            std::cout << i + 1 << ". 值: " << std::fixed << std::setprecision(4) << value
                << "  位置: (" << row + 1 << ", " << col + 1 << ")" << std::endl;
        }
    }
};

int main() {
    const int ROWS = 50;
    const int COLS = 50;

    std::cout << "=== 50x50矩阵最大值查找程序 ===" << std::endl;

    MatrixMaxFinder finder(ROWS, COLS);

    auto start_time = std::chrono::high_resolution_clock::now();
    finder.generateRandomMatrix();
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> gen_time = end_time - start_time;

    finder.printPartialMatrix();

    start_time = std::chrono::high_resolution_clock::now();
    finder.analyzeMatrix();
    end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> analysis_time = end_time - start_time;

    finder.findTopNValues(10);

    std::cout << "\n=== 性能统计 ===" << std::endl;
    std::cout << "矩阵生成时间: " << std::fixed << std::setprecision(6) << gen_time.count() << " 秒" << std::endl;
    std::cout << "分析计算时间: " << std::fixed << std::setprecision(6) << analysis_time.count() << " 秒" << std::endl;
    std::cout << "总元素数量: " << ROWS * COLS << " 个" << std::endl;

    std::cout << "\n程序执行完成，按回车键退出..." << std::endl;
    std::cin.get();

    return 0;
}