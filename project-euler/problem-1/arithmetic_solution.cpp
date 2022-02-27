#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>

/**
 * @brief Sums the natural numbers up to and including n.
 * 
 * @param n The number to sum until (inclusive).
 * @return int The sum of the numbers 1,2,3,...,n
 */
int sumNaturalNumbers(int n)
{
    return (n * (n + 1)) / 2;
}

/**
 * @brief Filters multiples of numbers present in a given vector. 
 * E.g. {2, 3, 4, 6, 7} returns {2, 3, 7}
 * 
 * @param numbers A vector of integers.
 * @return std::vector<int> The unique factors from the given integer vector.
 */
std::vector<int> filterMultiples(std::vector<int> numbers)
{
    std::vector<int> factors;

    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    bool shouldAdd;
    for (std::vector<int>::iterator iter1 = numbers.begin(); iter1 != numbers.end(); ++iter1)
    {
        shouldAdd = true;
        for (std::vector<int>::iterator iter2 = iter1; ++iter2 != numbers.end();)
        {
            if (*iter1 % *iter2 == 0)
            {
                shouldAdd = false;
                break;
            }
        }
        if (shouldAdd)
        {
            factors.push_back(*iter1);
        }
    }

    return factors;
}

/**
 * @brief Sums the numbers less than or equal to max, which are divisible by the divisor.
 * E.g. sumDivisibleNumbers(3,12) returns 3+6+9+12.
 * 
 * @param divisor The divisor.
 * @param max The upper-limit (inclusive).
 * @return int The sum of the numbers divisible by the divisor.
 */
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

    std::vector<int> uniqueDivisors = filterMultiples(divisors);

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