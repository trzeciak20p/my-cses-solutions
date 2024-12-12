#include <iostream>


int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    int sticks[n]{};
    for (int i = 0; i < n; i++)
    {
        std::cin >> sticks[i];
    }
    int min = sticks[0];
    int max = sticks[0];
    for (int i = 0; i < n; i++)
    {
        if (sticks[i] > max)
        {
            max = sticks[i];
        }
        if (sticks[i] < min)
        {
            min = sticks[i];
        }
    }

    int min_cost = INT_MAX;
    for (int i = min; i <= max; i++)
    {
        int cost = 0;
        for (int stick : sticks)
        {
            cost += abs(stick - i);
        }
        if (cost < min_cost)
        {
            min_cost = cost;
        }  
        // std::cout << i << " " << cost << "\r\n";
    }
    std::cout << min_cost << "\r\n";
    

    return 0;
}