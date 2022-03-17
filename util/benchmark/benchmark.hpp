#pragma once
#include <chrono>
#include <cmath>
#include <utility>

template <typename F, typename... Args>
long benchmark(int n, F func, Args &&...args)
{
    double sumDuration = 0;

    for (int i = 0; i < n; i++)
    {
        // steady_clock recommended for measurements https://en.cppreference.com/w/cpp/chrono/high_resolution_clock
        std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

        func(std::forward<Args>(args)...);

        std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;

        sumDuration += duration.count();
    }

    return lround(sumDuration / n);
}
