#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    if (n <= 3)
    {
        std::cout << "no solution\r\n";
        return 0;
    }

    int tab[n]{};
    
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            tab[i] = (i/2)+1;
        }else{
            tab[i] = (i/2)+(n/2) + ((n%2==0)?1:2);
        }     
    }
    
    for (int i : tab)
    {
        std::cout << i << " "; 
    }

    return 0;
}
