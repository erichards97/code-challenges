#pragma once
#include <chrono>
#include <utility>

template <typename F, typename... Args>
unsigned long benchmark(int n, F func, Args &&...args)
{
    long double sumDuration = 0;

    for (int i=0; i<n; i++) {
        auto start = std::chrono::high_resolution_clock::now();

        func(std::forward<Args>(args)...);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;

        sumDuration += duration.count();
    }

    return sumDuration / n;
}
