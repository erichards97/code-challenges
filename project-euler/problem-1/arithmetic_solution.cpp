#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>

int sumNaturalNumbers(int n)
{
    return (n * (n + 1)) / 2;
}

std::vector<int> filterDivisorMultiples(std::vector<int> divisors)
{
    std::vector<int> uniqueDivisors;

    std::sort(divisors.begin(), divisors.end(), std::greater<int>());

    bool shouldAdd;
    for (std::vector<int>::iterator iter1 = divisors.begin(); iter1 != divisors.end(); ++iter1)
    {
        shouldAdd = true;
        for (std::vector<int>::iterator iter2 = iter1; ++iter2 != divisors.end();)
        {
            if (*iter1 % *iter2 == 0)
            {
                shouldAdd = false;
                break;
            }
        }
        if (shouldAdd)
        {
            uniqueDivisors.push_back(*iter1);
        }
    }

    return uniqueDivisors;
}

int sumDivisibleNumbers(int divisor, int max)
{
    int numDivisible = floor(max / divisor);
    int sumDivisible = sumNaturalNumbers(numDivisible);
    return divisor * sumDivisible;
}

int sumMultipleDivisible(std::vector<int> divisors, int max)
{
    int sum = 0;
    int sumRemove = 0;

    std::vector<int> uniqueDivisors = filterDivisorMultiples(divisors);

    for (int i = 0; i < uniqueDivisors.size(); i++)
    {
        sum += sumDivisibleNumbers(uniqueDivisors[i], max);
        for (int j = i + 1; j < uniqueDivisors.size(); j++)
        {
            sumRemove += sumDivisibleNumbers(uniqueDivisors[i] * uniqueDivisors[j], max);
        }
    }

    return sum - sumRemove;
}

int main()
{

    int max;
    std::cout << "Enter max" << std::endl;
    std::cin >> max;

    std::vector<int> v;
    int input;
    std::cout << "Enter divisor, 0 to end input" << std::endl;
    while ((std::cin >> input) && input != 0)
    {
        std::cout << input << std::endl;
        v.push_back(input);
    }

    std::cout << sumMultipleDivisible(v, max) << std::endl;
}