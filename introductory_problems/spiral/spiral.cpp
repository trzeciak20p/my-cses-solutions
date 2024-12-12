#include <iostream>

int main(int argc, char const *argv[])
{
    int t = 0;
    std::cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        int res = 0;
        int x = 0, y = 0;
        std::cin >> y;
        std::cin >> x;
        if (x > y){
            
            if (x % 2 == 1)
            {
                res = x*x -y+1;
            }else{
                res = (x-1)*(x-1) + y;
            }
            
        }else{
            if (y % 2 == 0)
            {
                res = y*y - x+1;
            }else{
                res = (y-1)*(y-1) + x;
            }
        }
        
    
        std::cout << "odp: " << res << "\r\n";
    }
    


    return 0;
}
