#include <iostream>
#include <math.h>
#include <string>
#include <thread>
#include <time.h>
#include <unistd.h>
#include <vector>

// const int kThreadNum = 8;
const int kSampleCount = 200;
const int kTotalAmplitude = 300;
const double PI = 3.1415926;

static unsigned long GetTickCount() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

static void PrintUsage() {
    std::cout << "Usage:" << std::endl;
    std::cout << "\t./sine <thread-num> <memory-size>" << std::endl;
}

void DrawSineGraph() {
    int busy_span[kSampleCount] = {0};
    int amplitude = kTotalAmplitude / 2;
    double radian = 0.0;
    double radian_inc = 2.0 / (double)kSampleCount;

    // calculate the amplitude
    for (int i = 0; i < kSampleCount; i++) {
        busy_span[i] = static_cast<int>(amplitude + (sin(PI * radian) * amplitude));
        radian += radian_inc;
    }

    int start_time = 0;
    for (int i = 0;; i = (i + 1) % kSampleCount) {
        start_time = static_cast<int>(GetTickCount());
        while (static_cast<int>(GetTickCount()) - start_time < busy_span[i]) {
            // Do nothing here.
        }

        usleep((kTotalAmplitude - busy_span[i]) * 1000);
    }
}

void MultiThreadDrawSineGraph(int thread_num) {
    std::thread threads[thread_num];
    for (int i = 0; i < thread_num; i++) {
        threads[i] = std::thread(DrawSineGraph);
        std::cout << "thread " << i << " is created." << std::endl;
    }

    for (int i = 0; i < thread_num; i++) {
        threads[i].join();
    }
}

void OccupyMemorySize(std::vector<std::string>& svec, int memory_size) {
    for (int i = 0; i < memory_size * 1024; i++) {
        std::string s(1024*1024, 'a');
        svec.push_back(s);
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        PrintUsage();
        return -1;
    }
    int thread_num = 8;
    int memory_size = 4;

    try {
        thread_num = std::stoi(argv[1]);
        memory_size = std::stoi(argv[2]);
    } catch (const std::exception& e) {
        std::cout << "Failed to convert string to int: " << argv[1] << ", " << argv[2] << std::endl;
    }

    std::cout << "thread_num: " << thread_num << ", memory_size: " << memory_size << std::endl;
    std::vector<std::string> svec;
    OccupyMemorySize(svec, memory_size);
    MultiThreadDrawSineGraph(thread_num);
    return 0;
}
