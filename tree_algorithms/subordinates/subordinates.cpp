#include <iostream>
#include <vector>


class Employee{
    public:
        int num;
        std::vector<Employee*> subords{};

        Employee(int n){
            num = n;
        }

        void add(Employee *e){
            subords.push_back(e);
        }

        Employee *find(int seek){
            // std::cout << num;
            if (num == seek)
            {
                // std::cout << "found\r\n";
                return this;
            }   
            // std::cout << "\r\n";
            for (Employee* e : subords)
            {
                if (Employee*f = e->find(seek); f != nullptr)
                {
                    return f;
                }           
            }
            return nullptr;
        }

        void addBelow(Employee *employee, int below){
            find(below)->add(employee);
        }   
 
        int countBelow(){
            int res = -1;
            countBelowHelper(res);
            return res;
        }

    private:
        void countBelowHelper(int &count){
            for (Employee* e : subords)
            {
                e->countBelowHelper(count);
            }
            count++;
        }
};


int main(int argc, char const *argv[])
{
    int n = 6;
    std::cin >> n;
    n -= 1;
    int empl[n]{};
    for (int i = 0; i < n; i++)
    {
        std::cin >> empl[i];
    }

    Employee top(1);
    for (int i = 0; i < n; i++)
    {
        top.addBelow(new Employee(i+2), empl[i]);
    }

    std::cout << top.countBelow() << " ";
    for (int i = 0; i < n; i++)
    {
        std::cout << top.find(i+2)->countBelow() << " ";
    }
    
    return 0;
}