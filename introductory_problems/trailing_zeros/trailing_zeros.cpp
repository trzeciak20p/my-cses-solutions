#include <iostream>
#include <cstdint>

unsigned long long pow(int val, int power){
    if (power == 1)
    {
        return val;
    }
    return val * pow(val, power - 1);
}

int countZeros(unsigned long long num){
    int zero_counter = 0;
    while (num > 1)
    {
        if (num % 10 != 0)
        {
            return zero_counter;
        }
        zero_counter++;
        num /= 10;
    }
    return 0;
}

unsigned long long factorial(int n){
    unsigned long long res = 1;

    for (int i = 2; i <= n; i++)
    {
        res *= i;
        std::cout << res << "\r\n";
        int zeros = countZeros(res);
        unsigned long long div = pow(10, zeros + 5);
        res %= div;
        std::cout << res << "\r\n\r\n";
    }
    return res; 
}

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    unsigned long long num = factorial(n); 
    std::cout << countZeros(num) << "\r\n";

    // pamięć ktoś coś?   

    return 0;
}
