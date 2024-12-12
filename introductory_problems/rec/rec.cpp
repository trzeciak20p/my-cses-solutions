#include <iostream>
#include <vector>

void swap(std::vector<int> &vec, int a, int b){
    if (a == b || a > vec.size() || b > vec.size()){return;}
    int temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}

void swing(std::vector<int> &vec, int a, int b){
    if (a >= b || a > vec.size() || b > vec.size()){return;}
    while (a < b)
    {
        int temp = vec[b];
        vec[b] = vec[b-1];
        vec[b-1] = temp;
        b--;
    }
    
}

void display(const std::vector<int> &vec){
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << "\r\n";
}

void every(std::vector<int> vec, int iter = 0, int iter2 = 0){
    std::vector<int> temp = vec;
    if (iter2 == vec.size())
    {
        iter++;
        iter2 = 0;
    }
    
    if (iter >= vec.size())
    {
        return;
    }
    swing(vec, 0, iter);
    std::cout << "i: " << iter << " " << iter2 << "\r\n";
    display(vec);
    
    for (int i = iter2+1; i < vec.size(); i++)
    {
        swing(vec, iter2+1, i);
        display(vec);
    }
    
    

    every(temp, iter, iter2+1);
}


int main(int argc, char const *argv[])
{
    
    std::vector<int> vec = {1,2,3};    
    every(vec);
    // swing(vec, 0, 3);
    // display(vec);
    // swing(vec, 0, 2);
    // display(vec);    
    // swing(vec, 0, 2);
    // display(vec);



    return 0;
}
