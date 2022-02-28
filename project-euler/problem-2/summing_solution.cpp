#include <iostream>
#include <vector>
#include <numeric>

int nextFibonacciNumber(int prevPrevFibonacci, int prevFibonacci)
{
    if (prevFibonacci == -1)
    {
        return 1;
    }
    else if (prevPrevFibonacci == -1)
    {
        return 2;
    }
    else
    {
        return prevPrevFibonacci + prevFibonacci;
    }
}

int sumNthFibonacciNumbers(int max, int starting, int n)
{
    int sum = 0;

    int prevPrevFibonacci = -1;
    int prevFibonacci = -1;
    int nextFibonacci = 0;

    int i = starting;

    while ((nextFibonacci = nextFibonacciNumber(prevPrevFibonacci, prevFibonacci)) && (nextFibonacci <= max))
    {
        if (i == n)
        {
            sum += nextFibonacci;
            i = 0;
        }
        else
        {
            i++;
        }
        prevPrevFibonacci = prevFibonacci;
        prevFibonacci = nextFibonacci;
    }
    
    return sum;
}

int main()
{
    std::cout << "Sum: " << sumNthFibonacciNumbers(4000001, 1, 2) << std::endl;
}