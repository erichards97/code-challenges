#include <iostream>

std::string intToBinary(int num)
{
    std::string binary;

    int remainder;
    while (num > 0)
    {
        remainder = num % 2;
        binary = (remainder == 0 ? '0' : '1') + binary;
        num = num / 2;
    }

    return binary;
}

int largestBinaryGap(std::string binary)
{
    int maxGap = 0;
    int currentGap = 0;
    bool started = false;
    for (std::string::iterator it = binary.begin(); it != binary.end(); ++it)
    {
        if (*it == '0')
        {
            if (started)
            {
                currentGap++;
            }
        }

        else if (*it == '1')
        {
            if (currentGap > maxGap)
            {
                maxGap = currentGap;
            }

            currentGap = 0;
            started = true;
        }
    }

    return maxGap;
}

int main()
{
    for (int i = 1; i < 200; i++)
    {
        std::cout << i << std::endl;
        std::string binary = intToBinary(i);
        std::cout << binary << std::endl;
        std::cout << largestBinaryGap(binary) << std::endl;
        std::cout << std::endl;
    }
}
