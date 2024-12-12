#include <iostream>
#include <set>

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    std::set<int> set1{};

    for (int i = 0; i < n; i++)
    {
        int val = 0;
        std::cin >> val;
        set1.insert(val);
    }
    std::cout << set1.size() << "\r\n";
      
    return 0;
}
