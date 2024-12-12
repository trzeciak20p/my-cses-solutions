#include <iostream>

struct pos{
    int x;
    int y;
};
std::string dis(pos p){
    return "(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
}

bool valid(pos k1, pos k2){  //no attack
    if (k1.x == k2.x && k1.y == k2.y)
    {
        return false;
    }
    return !((abs(k1.x - k2.x) == 2 && abs(k1.y - k2.y) == 1) || (abs(k1.x - k2.x) == 1 && abs(k1.y - k2.y) == 2));
}

void emulateBoard(int k){
    int res = 0;
    pos k1 = {0,0};
    pos k2 = {0,0};
    for (k1.x = 0; k1.x < k; k1.x++)
    {
        for (k1.y = 0; k1.y < k; k1.y++)
        {
            for (k2.x = k1.x; k2.x < k; k2.x++)
            {
                k2.y = 0;
                if (k2.x == k1.x)
                {
                    k2.y = k1.y;
                }
                
                for (; k2.y < k; k2.y++)
                {
                    res += valid(k1, k2);
                }
            }

        }
    }
    

    std::cout << k <<": " << res << "\r\n";
}

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;

    for (int k = 1; k <= n; k++)
    {
        emulateBoard(k);
    }

    return 0;
}
