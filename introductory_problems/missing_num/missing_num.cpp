#include <iostream>
#include <fstream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::fstream file("input.txt", std::ios::in);
    const int n = [&]{
        int res;
        file >> res;
        return res;
    }();
    bool tab[n];
    std::fill(tab, tab + sizeof(tab), false);
    int num;
    while (file >> num)
    {
        tab[num-1] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (!tab[i])
        {
            std::cout << i+1 << "\r\n";
            break;
        }
    }
    
    


    return 0;
}
