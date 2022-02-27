#include <iostream>

using namespace std;

int count(int divisors[], int numDivisors, int max)
{
    int sum = 0;

    for (int i = 1; i <= max; i++)
    {
        for (int d = 0; d < numDivisors; d++)
        {
            if (i % divisors[d] == 0)
            {
                sum += i;
                break;
            }
        }
    }

    return sum;
}

int main()
{

    int max;
    cout << "Enter max" << endl;
    cin >> max;

    int numDivisors;
    cout << "Enter number of divisors" << endl;
    cin >> numDivisors;

    int divisors[numDivisors];

    for (int i = 0; i < numDivisors; i++)
    {
        cout << "Enter divisor" << endl;
        cin >> divisors[i];
    }

    int res = count(divisors, numDivisors, max);

    cout << res << endl;

    return 0;
}