#include <iostream>
#include <string>
#include <set>

void strSort(std::string &str){
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i; j < str.length(); j++)
        {
            if(str[j] < str[i]){
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }  
    }
}

void every(std::set<std::string> &strings, std::string str, int index = 0){
    if (index < str.length())
    {
        std::string temp_str = str;
        char temp = str[0];
        str[0] = str[index];
        str[index] = temp;
        strings.emplace(str);    
        for (int i = 1; i < str.length(); i++)
        {
            for (int j = i; j < str.length(); j++)
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
                std::cout << str << "\r\n";
                strings.emplace(str);
            }
        }   
        every(strings, temp_str, index+1);   
    }
}

void a(std::string str){
    int index = str.length();
    while(index >= 0)
    {
        for (int i = 0; i < count; i++)
        {
            /* code */
        }
        
        
        index++;
    }
    


}

int main(int argc, char const *argv[])
{
    std::string str = "bbacd";
    // std::cin >> str;
    strSort(str);
    std::set<std::string> strings{};
    every(strings, str);


    return 0;
}