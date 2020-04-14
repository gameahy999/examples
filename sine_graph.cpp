#include "sine_graph.h"

#include <iostream>
#include <math.h>
#include <thread>
#include <time.h>
#include <unistd.h>

const int kThreadNum = 16;
const int kSampleCount = 200;
const int kTotalAmplitude = 300;
const double PI = 3.1415926;

static unsigned long GetTickCount() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
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

void MultiThreadDrawSineGraph() {
    std::thread threads[kThreadNum];
    for (int i = 0; i < kThreadNum; i++) {
        threads[i] = std::thread(DrawSineGraph);
        std::cout << "thread " << i << " is created." << std::endl;
    }

    for (int i = 0; i < kThreadNum; i++) {
        threads[i].join();
    }
}
