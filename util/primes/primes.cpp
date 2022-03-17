#include <vector>

std::vector<unsigned long> primesLessThan(unsigned long n)
{
    std::vector<unsigned long> primes;

    for (int i = 2; i < n; i++)
    {
        primes.push_back(i);
    }

    for (std::vector<unsigned long>::iterator iter = primes.begin(); iter < primes.end(); iter++)
    {
        unsigned long n = *iter;
        for (std::vector<unsigned long>::iterator innerIter = iter + 1; innerIter < primes.end(); innerIter++)
        {
            if (*innerIter % n == 0)
            {
                innerIter = primes.erase(innerIter);
            }
        }
    }

    return primes;
}