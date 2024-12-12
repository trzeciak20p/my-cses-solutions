#include <iostream>
#include <vector>

bool find(const std::vector<int> &vec, int val){
    for(int i : vec){
        if (i == val)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    int songs[n]{};
    for (int i = 0; i < n; i++)
    {
        std::cin >> songs[i]; 
    }
    int longest_sequence = 0;

    for (int i = 0; i < n; i++)
    {
        std::vector<int> sqeuence{};
        int length = 0;
        for (int j = i; j < n; j++)
        {
            if (find(sqeuence, songs[j]) || j == n-1)
            {
                if (length > longest_sequence)
                {
                    longest_sequence = length;
                }
                length = 0;
                sqeuence.clear();          
            }else{
                length++;
                sqeuence.emplace_back(songs[j]);
            }           
        }
    }
    std::cout << longest_sequence << "\r\n";
    
    return 0;
}