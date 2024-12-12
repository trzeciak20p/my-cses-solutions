#include <iostream>


int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    int nums[n]{};
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
       
    int max_sum = nums[0];
    for (int i = 0; i < n; i++)
    {       
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
    }
    std::cout << max_sum << "\r\n";

    return 0;
}