#include <vector>

class Tree{
    public:
        Tree(int value) : value(value){}

        void add(Tree* tree){
            tree->parent = this;
            nodes.push_back(tree);
        }

        Tree* get(int seek){
            if (value == seek)
            {
                return this;
            }   
            for (Tree* tree : nodes)
            {
                if (Tree* nested = tree->get(seek); nested != nullptr)
                {
                    return nested;
                }           
            }
            return nullptr;
        }

        Tree* getRoot(){
            Tree* res = this;
            while (parent != nullptr)
            {
                res = res->parent;
            }
            return res;
        }

        void add(Tree* tree, int below){
            get(below)->add(tree);
        }   
 
        int countBelow(){
            int res = -1;
            countBelowHelper(res);
            return res;
        }

        int getDistanceDown(int seek){      // -1 not found
            if (value == seek)
            {
                return 0;
            }           
            int distance = -1;
            if (Tree* t = get(seek); t != nullptr)
            {
                distance = 1;
                while (t->parent != this)
                {
                    t = t->parent;
                    distance++;
                }
            }
            return distance;
        }

        int getDistance(int a, int b){ 
            Tree* tree = getRoot()->get(a);
            if (tree == nullptr)
            {
                return -1;
            }
            int distanceUp = 0;
            int distanceDown = tree->getDistanceDown(b);         
            while (distanceDown < 0)
            {
                if(tree->parent == nullptr){
                    return -1;
                }
                tree = tree->parent;
                distanceDown = tree->getDistanceDown(b);
                distanceUp++;          
            }    
            return distanceUp + distanceDown;
        }

    private:
        int value{};
        std::vector<Tree*> nodes{};
        Tree* parent = nullptr;
        
        void countBelowHelper(int &count){
            for (Tree* t : nodes)
            {
                t->countBelowHelper(count);
            }
            count++;
        }

        void getDistanceHelper(const int &value, int &distance){
            for (Tree* t : nodes)
            {
                t->countBelowHelper(distance);
            }
            distance++;
        }

        void getDistanceHelper(const int &a, const int &b, int &distance){

        }

};