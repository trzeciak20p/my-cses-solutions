#include <iostream>

int main(int argc, char const *argv[])
{
    int n = 1;
    int m = 1;
    std::cin >> n;    
    std::cin >> m;
    int tickets[n]{};
    int ppl[m]{};

    for (int i = 0; i < n; i++)
    {
        std::cin >> tickets[i];
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> ppl[i];
    }    
    int sold_count = 0;
    for (int i = 0; i < m; i++)
    {
        int biggest_price = 0;
        int to_empty = 0;
        for (int j = 0; j < n; j++)
        {
            if (tickets[j] > 0 && tickets[j] <= ppl[i] && tickets[j] > biggest_price)
            {
                biggest_price = tickets[j];
                to_empty = j;
                sold_count++;
            }
        }
        if (biggest_price != 0)     // ticket was bought
        {
            std::cout << tickets[to_empty] << " ";
            tickets[to_empty] = 0;
        }      
    }
    std::cout << "\r\n";

    if (sold_count != m)
    {
        std::cout << "-1\r\n";
    }


    return 0;
}