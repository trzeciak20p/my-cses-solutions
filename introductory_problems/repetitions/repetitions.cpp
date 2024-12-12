#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string sequence = "";
    std::cin >> sequence;
    int longest = 0;
    int current_length = 1;
    for (int i = 1; i < sequence.length(); i++)
    {
        if (sequence[i] == sequence[i-1])
        {
            current_length++;
        }else{
            if (current_length > longest)
            {
                longest = current_length;
            }
            current_length = 1;
        }
    }
    if (current_length > longest)
    {
        longest = current_length;
    }
    std::cout << longest << "\r\n";
    return 0;
}
