#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::vector<unsigned int> readNumsFromFile(std::string filename)
{
    std::vector<unsigned int> nums;
    std::string line;
    std::ifstream MyReadFile(filename);

    while (getline(MyReadFile, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            nums.push_back(line[i] - '0');
        }
    }

    MyReadFile.close();

    return nums;
}

unsigned long findLargestConsecutiveProduct(int n, std::vector<unsigned int> nums)
{
    unsigned long maxProduct = 0;
    unsigned long product = 1;

    for (int i = 0; i < n; i++) // Form the initial product from the first n numbers
    {
        product *= nums[i];
    }

    maxProduct = product;

    for (std::vector<unsigned int>::iterator iter = nums.begin() + n; iter < nums.end(); iter++) // Iterate from start+n until the end
    {
        std::cout << "Current product is: " << product << " removing: " << *(iter-n) << " and inserting: " << *iter << std::endl;

        // Remove earliest number from our current product
        if (*(iter - n) == 0)
        {
            // If the number to remove is 0, we need to recalculate the product from the last n-1 numbers
            product = 1;
            for (int i = 1; i < n; i++)
            {
                product *= *((iter - n) + i);
            }
        }
        else
        {
            // Otherwise, just divide the current product by the number to be removed
            product /= *(iter - n);
        }

        // Insert (multiply) new number to our current product
        product *= *iter;

        std::cout << "New product is: " << product << std::endl;

        if (product > maxProduct)
        {
            maxProduct = product;
        }
    }

    return maxProduct;
}

int main()
{
    std::vector<unsigned int> nums = readNumsFromFile("num.txt");

    unsigned long largestConsecutiveProduct = findLargestConsecutiveProduct(13, nums);

    std::cout << largestConsecutiveProduct << std::endl;
}