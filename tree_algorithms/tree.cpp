#include <vector>

template <typename T>
class Tree{
    public:
        Tree(T value) : m_value(value){}

        void add(Tree* tree){
            if (getRoot()->getNode(tree->m_value) == nullptr) // adds if value doesn't already exist
            {
                tree->m_parent = this;
                m_nodes.push_back(tree);
            }
        }
        void add(T value){
            if (getRoot()->getNode(value) == nullptr) // adds if value doesn't already exist
            {
                Tree* tree = new Tree(value);
                tree->m_parent = this;
                m_nodes.push_back(tree);
            }
        }
        void add(Tree* tree, T below){
            getNode(below)->add(tree);
        }   
        void add(T value, T below){
            getNode(below)->add(value);
        } 
        
        Tree *operator [](T value){
            return getNode(value);
        }

        T getValue(){
            return m_value;
        }

        Tree* getNode(T seek){
            if (m_value == seek)
            {
                return this;
            }   
            for (Tree* tree : m_nodes)
            {
                if (Tree* nested = tree->getNode(seek); nested != nullptr)
                {
                    return nested;
                }           
            }
            return nullptr;
        }

        Tree* getRoot(){
            Tree* res = this;
            while (res->m_parent != nullptr)
            {
                res = res->m_parent;
            }
            return res;
        }
 
        int countBelow(){
            int res = -1;
            countBelowHelper(res);
            return res;
        }

        int getDistanceDown(T seek){      // -1 not found
            if (m_value == seek)
            {
                return 0;
            }           
            int distance = -1;
            if (Tree* t = getNode(seek); t != nullptr)
            {
                distance = 1;
                while (t->m_parent != this)
                {
                    t = t->m_parent;
                    distance++;
                }
            }
            return distance;
        }

        int getDistance(T a, T b){ 
            Tree* tree = getRoot()->getNode(a);
            if (tree == nullptr)
            {
                return -1;
            }
            int distanceUp = 0;
            int distanceDown = tree->getDistanceDown(b);         
            while (distanceDown < 0)
            {
                if(tree->m_parent == nullptr){
                    return -1;
                }
                tree = tree->m_parent;
                distanceDown = tree->getDistanceDown(b);
                distanceUp++;          
            }    
            return distanceUp + distanceDown;
        }

    private:
        T m_value{};
        std::vector<Tree*> m_nodes{};
        Tree* m_parent = nullptr;
        
        void countBelowHelper(int &count){
            for (Tree* t : m_nodes)
            {
                t->countBelowHelper(count);
            }
            count++;
        }

        void getDistanceHelper(const int &value, int &distance){
            for (Tree* t : m_nodes)
            {
                t->countBelowHelper(distance);
            }
            distance++;
        }

};

#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
    Tree<int> a(5);
    Tree<std::string> b("1");
    b.add("2");
    b.add("3");
    a.add(new Tree(3));
    b.getNode("3")->add(new Tree<std::string>("4"));
    b.getNode("3")->add(new Tree((std::string)"4"));
    b["3"]->add("4");
    std::cout << b.getDistanceDown("4") << "\r\n";
    std::cout << b.getDistance("2", "4") << "\r\n";
    
    if (b.getNode("1") == b["1"])
    {
        std::cout << "yupi\r\n";
    }
    
    return 0;
}
