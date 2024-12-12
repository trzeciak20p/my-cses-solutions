#include <iostream>


int main(int argc, char const *argv[])
{
    int n = 0;
    int x = 0;
    std::cin >> n;    
    std::cin >> x;
    int ppl[n]{};
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> ppl[i];
    }
    int gondolas_count = n;

    for (int i = 0; i < n; i++)
    {
        if (ppl[i] > 0)
        {
            int biggest_sum = ppl[i];
            int index2 = 0;
            for (int j = i+1; j < n; j++)
            {
                if (int sum = ppl[i] + ppl[j]; sum > biggest_sum && sum <= x && ppl[j] != 0)
                {
                    biggest_sum = sum;
                    index2 = j;
                }      
            }
            if (biggest_sum != ppl[i])  // this means 2 ppl in a gondola
            {
                // std::cout << i << " " << index2 << "\r\n";
                gondolas_count--;
                ppl[index2] = 0;
            }
        }     
    }
    std::cout << gondolas_count << "\r\n";
    return 0;
}
