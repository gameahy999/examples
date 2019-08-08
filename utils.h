#ifndef __UTILS_H__
#define __UTILS_H__

#include<chrono>

namespace utils {

void separator(int i = 0);

class Timer {
public:
    Timer() : m_begin(std::chrono::high_resolution_clock::now()) {}
    void reset() { m_begin = std::chrono::high_resolution_clock::now(); }

    //默认输出毫秒
    int64_t elapsed() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //默认输出秒
    double elapsed_second() const {
        return std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //微秒
    int64_t elapsed_micro() const {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //纳秒
    int64_t elapsed_nano() const {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //分
    int64_t elapsed_minutes() const {
        return std::chrono::duration_cast<std::chrono::minutes>(std::chrono::high_resolution_clock::now() - m_begin).count();
    }

    //时
    int64_t elapsed_hours() const {
        return std::chrono::duration_cast<std::chrono::hours>(std::chrono::high_resolution_clock::now() - m_begin).count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_begin;
};

}

#endif
