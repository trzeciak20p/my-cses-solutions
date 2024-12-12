#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    int tab[n]{};
    for (int i = 0; i < n; i++)
    {      
        std::cin >> tab[i];
    }
    int moves = 0;
    for (int i = 1; i < n; i++)
    {
        int diff = tab[i-1] - tab[i];
        if (diff > 0)
        {
            moves += diff;
            tab[i] += diff;
        }
    }
    std::cout << "moves: " << moves << "\r\n";
    
    return 0;
}
