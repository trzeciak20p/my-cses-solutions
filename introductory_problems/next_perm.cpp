#include <iostream>
#include <algorithm>
#include <vector>

void display(const std::vector<int>& vec){
    for (auto i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << "\r\n";
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec = {1,3,2,4};
    std::sort(vec.begin(), vec.end());   
    do{
        // kodzik momento
        display(vec);   
    }while(std::next_permutation(vec.begin(), vec.end()));

    return 0;
}