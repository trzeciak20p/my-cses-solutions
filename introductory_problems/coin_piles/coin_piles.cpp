#include <iostream>

int main(int argc, char const *argv[])
{
    int t = 1;
    std::cin >> t;
    
    int a = 0;
    int b = 0; 
    
    while (t > 0)
    {
        std::cin >> a;
        std::cin >> b;
        while (a > 0 && b > 0)
        {
            a--;
            b--;
            if (a >= b)
            {
                a--;
            }else{
                b--;
            }
            
        }     
        if (a == 0 && b == 0)
        {
            std::cout << "YES\r\n";
        }else{
            std::cout << "NO\r\n";
        }     
        t--;
    }
    

    return 0;
}