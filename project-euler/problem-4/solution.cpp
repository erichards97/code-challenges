#include <iostream>
#include <vector>
#include <cmath>

bool isPalindrome(int x)
{
    int length = (log(x) / log(10)) + 1;
    std::vector<int> chars;
    chars.reserve(length);
    
    while (x > 0)
    {
        chars.push_back(x % 10);
        x = x / 10;
    }

    for (int i = 0; i < (length / 2); i++)
    {
        if (chars[i] != chars[length - (i + 1)])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int maxPalindrome = 0;
    int minMultiple = 1;
    // As we're counting backwards, if we find e.g. 998 * 995 gives a palindrome, then there's no need to check 994 * ... and below
    for (int i = 999; i >= minMultiple; i--)
    {
        for (int j = i; j >= minMultiple; j--)
        {
            int product = i * j;

            if (product <= maxPalindrome)
            {
                break;
            }

            if (isPalindrome(product))
            {
                maxPalindrome = product;
                minMultiple = std::min(i, j);
            }
        }
    }

    std::cout << maxPalindrome << std::endl;
}