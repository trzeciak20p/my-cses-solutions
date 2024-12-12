#include <iostream>
#include <string>
#include <algorithm>


int main(int argc, char const *argv[])
{

    std::string str = "";
    std::cin >> str;
    std::sort(str.begin(), str.end(), [](char i, char j){return i > j;});
    
    int counter = 1;
    while (std::prev_permutation(str.begin(), str.end()))
    {
        counter++;
    }
    std::cout << counter << "\r\n";

    std::sort(str.begin(), str.end());
    do 
    {
        std::cout << str << "\r\n";
    } while (std::next_permutation(str.begin(), str.end()));
    


    return 0;
}
