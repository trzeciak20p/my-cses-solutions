#include <iostream>


int main(int argc, char const *argv[])
{
    int n = 0;
    int target_sum = 0;
    std::cin >> n;
    std::cin >> target_sum;
    int nums[n]{};
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (nums[i] + nums[j] == target_sum)
            {
                std::cout << i+1 << " " << j+1 << "\r\n";
                return 0;
            }
        }
    }
    std::cout << "IMPOSSIBLE\r\n";
    return 0;
}