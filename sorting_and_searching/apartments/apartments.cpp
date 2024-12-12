#include <iostream>
#include <vector>


int main(int argc, char const *argv[])
{
    int n = 0;
    int m = 0;
    int k = 0;
    std::cin >> n;
    std::cin >> m;
    std::cin >> k;

    std::vector<int> people{};
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        std::cin >> x;
        people.push_back(x);
    }
    std::vector<int> apartments{};
    for (int i = 0; i < m; i++)
    {
        int x = 0;
        std::cin >> x;
        apartments.push_back(x);
    }
    std::vector<std::pair<int, int>> succes{};
    for (int p : people)
    {
        int closest = k+1;
        int found = 0;
        for (int a = 0; a < apartments.size(); a++)
        {
            if (int range = abs(apartments[a]-p); range < closest)
            {
                closest = range;
                found = a;
            }           
        }
        if (closest < k+1)
        {
            succes.push_back({p, apartments[found]});
            apartments.erase(apartments.begin()+found);
        }     
    }
    
    std::cout << succes.size() << "\r\n";   
    
    
      
    return 0;
}
