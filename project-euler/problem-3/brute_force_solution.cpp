#include <iostream>
#include <vector>

std::vector<long> getPrimes(long max)
{
    std::vector<long> primes;
    bool factorFound;
    for (long i = 1; i <= max; i++)
    {
        factorFound = false;
        for (std::vector<long>::iterator iter = ++primes.begin(); iter < primes.end(); iter++) // ++primes to avoid 1
        {
            if (i % *iter == 0)
            {
                factorFound = true;
                break;
            }
        }

        if (!factorFound)
        {
            primes.push_back(i);
        }
    }

    return primes;
}

long getLargestPrimeFactor(long num)
{
    std::vector<long> primes = getPrimes(num / 2);

    if (primes.size() > 0)
    {
        for (std::vector<long>::iterator iter = primes.end() - 1; iter >= primes.begin(); iter--)
        {
            if (num % *iter == 0)
            {
                return *iter;
            }
        }
    }

    return 1;
}

int main()
{
    long number;
    std::cout << "Enter the number for which I should find the largest prime factor: ";
    std::cin >> number;

    long largestPrimeFactor = getLargestPrimeFactor(number);

    if (largestPrimeFactor == 1)
    {
        std::cout << number << " is prime" << std::endl;
    }
    else
    {
        std::cout << largestPrimeFactor << std::endl;
    }
}