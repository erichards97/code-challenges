#include "primes.hpp"
#include <iostream>
#include <vector>
#include <cmath>

unsigned long largestExponentLessThan(int num, int max)
{
    int expo = 1;
    while (pow(num, expo) < max)
    {
        expo++;
    }
    return pow(num, expo - 1);
}

int main()
{
    unsigned long max;
    std::cout << "Enter max (inclusive)" << std::endl;
    std::cin >> max;

    std::vector<unsigned long> primes = primesLessThan(max + 1);

    unsigned long product = 1;
    for (unsigned long p : primes)
    {
        unsigned long x = largestExponentLessThan(p, max + 1);
        std::cout << p << "|" << x << std::endl;
        product *= x;
    }

    std::cout << "Product: " << product << std::endl;
}