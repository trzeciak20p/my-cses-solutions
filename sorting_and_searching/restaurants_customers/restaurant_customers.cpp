#include <iostream>


struct t_time{
    int arrive;
    int leave;
};

bool checkBetween(t_time time, int val){
    return (val >= time.arrive && val <= time.leave);
}

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    t_time customers[n]{};
    for (int i = 0; i < n; i++)
    {
        t_time customer{};
        std::cin >> customer.arrive;
        std::cin >> customer.leave;
        customers[i] = customer;
    }
    int earliest = customers[0].arrive;
    int latest = customers[0].leave;
    for (t_time c : customers)
    {
        if (c.arrive < earliest)
        {
            earliest = c.arrive;
        }
        if (c.leave > latest)
        {
            latest = c.leave;
        }
    }
    
    int max_at_once = 0;
    for (int i = earliest; i <= latest; i++)
    {
        int customer_count = 0;
        for (t_time c : customers)
        {   
            if (checkBetween(c, i))
            {
                customer_count++;
            }           
        }
        if (customer_count > max_at_once)
        {
            max_at_once = customer_count;
        }       
    }
    std::cout << max_at_once << "\r\n";    
    return 0;
}