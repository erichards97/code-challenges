#include <iostream>
#include <vector>

/**
 * @brief Get the next prime number, given a starting number and a list of primes thus far.
 *
 * @param current The starting number, from which we should find the next prime.
 * @param primes A list of primes between 1 and the starting number.
 * @return long The next prime number after the given number.
 */
long getNextPrime(long current, std::vector<long> primes)
{
    long i = current + 1;
    std::vector<long>::iterator iter = ++primes.begin(); // ++ to skip 1

    while (iter < primes.end())
    {
        if (i % *iter == 0)
        {
            iter = ++primes.begin(); // ++ to skip 1
            i++;
        }
        else
        {
            iter++;
        }
    }

    return i;
}

/**
 * @brief Repeatedly divide factors of the given number by the smallest possible prime, until we reach the larget prime factor.
 * 
 * @param num The number for which we should find the largest prime factor.
 * @return long The largest prime factor of the given number.
 */
long getLargestPrimeFactor(long num)
{
    std::vector<long> primes = {1, 2};

    long currentPrime = 2;
    long currentFactor = num;

    while (currentFactor > currentPrime)
    {
        if (currentFactor % currentPrime == 0)
        {
            currentFactor = currentFactor / currentPrime;
        }
        else
        {
            currentPrime = getNextPrime(currentPrime, primes);
            primes.push_back(currentPrime);
        }
    }

    return currentFactor;
}

int main()
{
    long number;
    std::cout << "Enter the number for which I should find the largest prime factor: ";
    std::cin >> number;

    std::cout << getLargestPrimeFactor(number) << std::endl;
}