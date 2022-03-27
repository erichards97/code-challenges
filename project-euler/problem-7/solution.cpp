#include <iostream>
#include <vector>
#include <cmath>

unsigned long nthPrime(unsigned long n)
{
    std::vector<unsigned long> primes;

    unsigned long numPrimes = 0;
    unsigned long i = 2;
    long double sqrtI = sqrt(i);
    bool isPrime;
    while (numPrimes < n)
    {
        isPrime = true;
        
        for (unsigned long prime : primes)
        {
            if (i % prime == 0)
            {
                isPrime = false;
                break;
            }
            if (prime > sqrtI)
            {
                break;
            }
        }

        if (isPrime)
        {
            primes.push_back(i);
            numPrimes++;
        }

        i += 1;
        sqrtI = sqrt(i);
    }

    return primes.back();
}

int main()
{
    std::cout << nthPrime(10001) << std::endl;
    std::cout << nthPrime(1000000) << std::endl;
}