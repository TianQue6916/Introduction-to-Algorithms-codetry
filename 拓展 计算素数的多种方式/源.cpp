#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

// 方法1：试除法判断单个数字是否为素数
static bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// 方法2：埃拉托斯特尼筛法找出所有小于等于n的素数
std::vector<int> sieveOfEratosthenes(int n) {
    std::vector<bool> isPrime(n + 1, true);
    std::vector<int> primes;

    if (n >= 2) {
        isPrime[0] = isPrime[1] = false;

        int limit = sqrt(n);
        for (int i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
    }

    return primes;
}

// 打印素数列表
void printPrimes(const std::vector<int>& primes) {
    std::cout << "找到 " << primes.size() << " 个素数: ";
    for (size_t i = 0; i < primes.size(); ++i) {
        std::cout << primes[i];
        if (i < primes.size() - 1) {
            std::cout << ", ";
        }
        // 每行打印10个数字
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "请输入一个正整数 n: ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "没有素数小于等于 " << n << std::endl;
        return 0;
    }

    // 使用试除法
    std::cout << "\n=== 使用试除法 ===" << std::endl;
    std::vector<int> primesTrial;
    auto start1 = std::chrono::high_resolution_clock::now();

    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            primesTrial.push_back(i);
        }
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    printPrimes(primesTrial);
    std::cout << "试除法耗时: " << duration1.count() << " 毫秒" << std::endl;


    // 使用埃拉托斯特尼筛法
    std::cout << "\n=== 使用埃拉托斯特尼筛法 ===" << std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    std::vector<int> primesSieve = sieveOfEratosthenes(n);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);

    printPrimes(primesSieve);
    std::cout << "筛法耗时: " << duration2.count() << " 毫秒" << std::endl;

    // 验证两种方法结果是否一致
    if (primesTrial == primesSieve) {
        std::cout << "\n✓ 两种方法结果一致!" << std::endl;
    }
    else {
        std::cout << "\n✗ 两种方法结果不一致!" << std::endl;
    }

    return 0;
}