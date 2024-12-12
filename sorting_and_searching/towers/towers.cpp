#include <iostream>
#include <vector>


int findLowest(const std::vector<int> &cubes, std::vector<int> towers, int it = 0){
    if (it != cubes.size())
    {
        for (int i = 0; i < towers.size(); i++)
        {
            if (cubes[it] < towers[i])
            {
                towers[i] = cubes[it];
            }else{
                towers.emplace_back(cubes[it]);
            }   
        }    
    }
    return towers.size();
}


int main(int argc, char const *argv[])
{
    int n = 5;
    // std::cin >> n;
    std::vector<int> cubes(n);
    // for (int i = 0; i < n; i++)
    // {
    //     std::cin >> cubes[i];
    // }
    cubes = {3, 8, 2, 1, 5};
    std::vector<int> towers{};
    
    int lowest = findLowest(cubes, towers);

    return 0;
}