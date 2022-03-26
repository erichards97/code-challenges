#include <iostream>

unsigned long sumNaturalNumbers(unsigned long n)
{
    unsigned long sum = 1;
    for (int i = 2; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

unsigned long sumSquaredNaturalNumbers(unsigned long n)
{
    unsigned long sum = 1;
    for (int i = 2; i <= n; i++)
    {
        sum += (i * i);
    }
    return sum;
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