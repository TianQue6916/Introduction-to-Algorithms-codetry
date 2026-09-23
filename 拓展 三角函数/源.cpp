#include <thread>
#include <chrono>

// 简单的动态sin波
void animateSinWave(int durationSeconds = 10) {
    std::cout << "动态sin波演示 (按Ctrl+C退出):" << std::endl;

    auto startTime = std::chrono::steady_clock::now();
    auto endTime = startTime + std::chrono::seconds(durationSeconds);

    while (std::chrono::steady_clock::now() < endTime) {
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
            currentTime - startTime).count();

        double time = elapsed / 1000.0;
        double value = sin(time * 2 * M_PI);  // 1Hz频率

        // 创建简单的波形显示
        int width = 50;
        int position = (value + 1) * (width / 2);

        std::string wave(width, ' ');
        wave[position] = '*';
        wave[width / 2] = '|';  // 中心线

        std::cout << "\r时间: " << std::setw(6) << std::fixed << std::setprecision(2) << time
            << "s  sin(t): " << std::setw(6) << std::setprecision(3) << value
            << "  [" << wave << "]";
        std::cout.flush();

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    std::cout << "\n演示结束!" << std::endl;
}