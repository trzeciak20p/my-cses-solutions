#include <iostream>
#include <set>


int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    int coins[n]{};
    for (int i = 0; i < n; i++)
    {
        std::cin >> coins[i];
    }
    
    std::set<int> sums{};
    // nie działa block kodu
    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += coins[k];
            }
            sums.emplace(sum);
        }
    }

    
    int smallest_sum = 1;
    for (int c : coins)
    {
        smallest_sum += c;
    }
    for (int i = smallest_sum-1; i >= 1; i--)
    {
        bool exist = false;
        for (int sum : sums)
        {
            if (sum == i)
            {
                exist = true;
                break;
            }
        }
        if (!exist)
        {
            smallest_sum = i;
        }
    
    }
    std::cout << smallest_sum << "\r\n";
    
    return 0;
}