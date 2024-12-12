#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    int tab[n]{};
    int sum = 0;
    for (int i = 0; i < n;i++)
    {
        tab[i] = i+1;
        sum += tab[i];
    }

    if (sum % 2 == 1)
    {
        std::cout << "NO";
        return 1;
    }

    std::vector <int> vec1{};
    std::vector <int> vec2{};
    int sum2 = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (sum2 + tab[i] <= sum / 2)
        {
            vec1.push_back(tab[i]);
            sum2 += tab[i];
        }else{
            vec2.push_back(tab[i]);
        } 
    }
    
    std::cout << vec1.size() << "\r\n";
    for (int i : vec1)
    {
        std::cout << i << " ";
    }
    std::cout << "\r\n" << vec2.size() << "\r\n";
    for (int i : vec2)
    {
        std::cout << i << " ";
    }
    return 0;
}
