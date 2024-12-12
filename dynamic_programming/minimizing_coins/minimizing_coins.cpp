#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{

    int n = 0;
    std::cin >> n;
    int coins[n]{};
    for (int i = 0; i < n; i++)
    {
        std::cin >> coins[i];
    }
    std::sort(coins, coins+n, [](int i, int j){return i > j;});
    
    int d_sum = 11;
    int min_coins = d_sum + 1;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int coin_count = 0;
        for (int j = i; j < n;)
        {
            if (sum + coins[j] > d_sum)
            {
                j++;
            }else{
                sum += coins[j];
                coin_count++;
                if(sum == d_sum){
                    if (coin_count < min_coins)
                    {
                        min_coins = coin_count;
                    }
                    break;
                }
            }
        }
    }
    
    if (min_coins > d_sum)
    {
        std::cout << -1 << "\r\n";
    }else{
        std::cout << min_coins << "\r\n";
    }
    
    return 0;
}