#include <iostream>

int main(int argc, char const *argv[])
{
    
    int n = [&]{
        int res = 0;
        std::cin >> res;
        return (int)res;
    }();
    while (n != 1)
    {
        std::cout << n << ", ";
        if (!(n & 1))
        {
            n /= 2;
        }else{
            n = n*3 + 1;
        }
    }
    std::cout << n << "\r\n";

    


    return 0;
}
