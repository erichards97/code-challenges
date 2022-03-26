#include <iostream>

unsigned long sumNaturalNumbers(unsigned long n)
{
    return (n * (n + 1)) / 2;
}

unsigned long sumSquaredNaturalNumbers(unsigned long n)
{
    return (n * (n + 1) * ((2 * n) + 1)) / 6;
}

int main()
{
    unsigned long n;
    std::cout << "Enter largest natural number: " << std::endl;
    std::cin >> n;

    unsigned long naturalSumSquared = sumNaturalNumbers(n);
    naturalSumSquared *= naturalSumSquared;

    unsigned long naturalSquareSum = sumSquaredNaturalNumbers(n);

    std::cout << "Squared sum minus sum of squares is: " << (naturalSumSquared - naturalSquareSum) << std::endl;
}