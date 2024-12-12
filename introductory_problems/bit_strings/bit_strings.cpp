#include <iostream>

int pow(int val, int power){
    if (power == 1)
    {
        return val;
    }
    return val * pow(val, power - 1);
}

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    if (n > 1)
    {
        return 0;
    }
    std::cout << pow(2, n) << "\r\n"; 
    return 0;
}
