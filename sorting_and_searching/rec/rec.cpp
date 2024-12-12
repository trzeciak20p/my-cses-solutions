#include <iostream>
#include <vector>

void displayRange(const std::vector<int> &vec, int start, int end){
    for (int i = start; i <= end; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout <<  "\r\n";
}

void for22(const std::vector<int> &data, int index = 0){
    if (index < data.size())
    {
        for (int i = index; i < data.size(); i++)
        {
            displayRange(data, index, i);         
        }
        for22(data, index+1);
    }else{
        std::cout << "\r\n";
    }
    
}

void for2(const std::vector<int> &data, int i = 0){
    if (i < data.size())
    {
        displayRange(data, i, data.size()-1);
        for2(data, i+1);
    }else{
        std::cout << "\r\n";
    }
    
}

void for1(const std::vector<int> &data, int i = 0){
    if (i < data.size())
    {
        std::cout << data[i] << " ";
        for1(data, i+1);
    }else{
        std::cout << "\r\n";
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> data = {1, 2, 3, 4};

    // for1(data);
    // for2(data);
    for22(data);
    
    return 0;
}