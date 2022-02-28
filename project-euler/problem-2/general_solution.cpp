#include <iostream>
#include <vector>
#include <numeric>

int nextFibonacciNumber(std::vector<int> &fibonacciNumbers)
{
    int numNumbers = fibonacciNumbers.size();
    if (numNumbers < 2)
    {
        return numNumbers + 1; // 0 => 1, 1 => 2
    }
    else
    {
        return fibonacciNumbers[numNumbers - 1] + fibonacciNumbers[numNumbers - 2];
    }
}

std::vector<int> getFibonacciNumbers(int max)
{
    std::vector<int> fibonacciNumbers;

    int nextFibonacci;
    while ((nextFibonacci = nextFibonacciNumber(fibonacciNumbers)) && (nextFibonacci <= max))
    {
        fibonacciNumbers.push_back(nextFibonacci);
    }

    return fibonacciNumbers;
}

std::vector<int> getEveryNElement(int starting, int n, std::vector<int> &items)
{
    std::vector<int> selectedItems;

    std::vector<int>::iterator iter = items.begin();
    iter += starting;

    while (iter < items.end())
    {
        selectedItems.push_back(*iter);
        iter += n;
    }

    return selectedItems;
}

int getSum(std::vector<int> &v)
{
    int initial_sum = 0;
    return accumulate(v.begin(), v.end(), initial_sum);
}

int main()
{
    std::vector<int> fibonacciNumbers = getFibonacciNumbers(4000001);

    std::vector<int> evenFibonacciNumbers = getEveryNElement(1, 3, fibonacciNumbers);

    std::cout << "Sum: " << getSum(evenFibonacciNumbers) << std::endl;
}