#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{

    std::string str = "";
    std::cin >> str;
    int n = str.length();
    const int size = 'Z'-'A';
    int chars[size]{};
    for (char c : str)
    {
        chars[c-'A']++;
    }
    bool tooMuchOdd = false;
    std::string res = ""; 
    for(int i = 0; i < size; i++){
        if (chars[i] % 2 == 1)
        {
            if (tooMuchOdd)
            {
                std::cout << "NO SOLUTION\r\n";
                return 0;
            }
            res += char(i+'A');
            tooMuchOdd = true;
        }
    }
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < (chars[i]/2); j++){
            res = char(i+'A') + res;
        }
    }
    if (n % 2 == 1)
    {
        n--;
    }
    // std::cout << res << n<< "\r\n";
    for (int i = (n/2)-1; i >= 0; i--)
    {
        res += res[i];   
    }
    std::cout << res << "\r\n";
    
    return 0;
}
