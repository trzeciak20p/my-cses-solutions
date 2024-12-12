#include <iostream>
#include <math.h>


int pow(int base, int power){    
    if (power > 0)
    {
        return base * pow(base, power-1);
    }
    return 1;
}

std::string fill(std::string str, const int &n){
    while (str.length() < n)
    {
        str = '0' + str;
    }
    return str;
}

void flipBit(std::string &str, int pos){
    if (pos >= str.length())
    {
        return;
    }   
    str[pos] = (str[pos] == '0') ? '1' : '0';
}



int main(int argc, char const *argv[])
{
    
    const int n = []{
        int res = 0;
        std::cin >> res;
        if (res > 16)
        {
            return 16;
        }
        return res;
    }(); 

    const int n_pow_val = pow(2, n);
    char bit_changes[n_pow_val]{};
    std::string str = [n]{
        std::string res = "";
        for (int i = 0; i < n; i++)
        {
            res += '0';
        }
        return res;
    }();
    int now_pow = 0;

    std::cout << str << "\r\n";
    for (int i = 1; i < n_pow_val; i++)
    {
        int now_bit = 1;
        if (i == pow(2, now_pow))
        {
            now_pow++;
            now_bit = now_pow;
        }else{
            int prev_pow_val = pow(2, now_pow-1);
            now_bit = bit_changes[prev_pow_val - (i - prev_pow_val)];
        }

        flipBit(str, str.length() - now_bit);       
        bit_changes[i] = now_bit;
        // std::cout << now_bit << " ";
        std::cout << str << "\r\n";
    }
    // for (int i : bit_changes)
    // {
    //     std::cout << i << " ";
    // }
      
    return 0;
}