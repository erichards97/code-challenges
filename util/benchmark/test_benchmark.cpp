#include "lib/benchmark.hpp"

#include <thread>
#include <iostream>

using namespace std;

void long_operation(int millis)
{
    this_thread::sleep_for(chrono::milliseconds(millis));
}

int main()
{
    long timeTaken = benchmark(10, long_operation, 150);
    cout << timeTaken << endl;
}