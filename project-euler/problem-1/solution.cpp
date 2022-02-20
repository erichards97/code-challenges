#include <iostream>

using namespace std;

int count(int limit) {
    int sum = 0;

    for (int i = 1; i < limit; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }

    return sum;
}

int main()
{
    int res = count(1000);

    cout << res << endl;

    return 0;
}