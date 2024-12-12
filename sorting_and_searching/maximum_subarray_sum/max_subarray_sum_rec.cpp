#include <iostream>
#include <vector>

int sumRange(const std::vector<int> &vec, int start, int end){
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += vec[i];
    }
    return sum;
}
void displayRange(const std::vector<int> &vec, int start, int end){
    for (int i = start; i <= end; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout <<": "<< sumRange(vec, start, end)<< "\r\n";
}


void for22(const std::vector<int> &data, int &max_sum, int index = 0){
    if (index < data.size())
    {
        for (int i = index; i < data.size(); i++)
        {
            if (int sum = sumRange(data, index, i); sum > max_sum)
            {
                max_sum = sum;
            }
            displayRange(data, index, i);
        }         
        for22(data, max_sum, index+1);
    }  
}

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
       
    int max_sum = nums[0];

    for22(nums, max_sum);

    std::cout << max_sum << "\r\n";

    return 0;
}