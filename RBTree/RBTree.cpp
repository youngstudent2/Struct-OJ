#include<iostream>
using namespace std;
class RBNode{
    public:
        enum COLOR{RED,BLACK};
        RBNode *left,*right;
        int val;
        COLOR color;
        RBNode():left(NULL),right(NULL),val(0),color(BLACK){}
        RBNode(int v):left(NULL),right(NULL),val(v),color(BLACK){}        
    };
class RBTree{
private: 
    RBNode* root;
public:
    RBTree();
    RBNode* insert(RBNode* node);
    RBNode* search(int k);
    RBNode* minimum() const;
    RBNode* maximum() const;
    RBNode* predecessor(RBNode* node)const;
    RBNode* successor(RBNode* node)  const;
    void inOrder();
    bool remove(int k);
private:
    void insertFixUp(RBNode* node);
    void removeFixUp(RBNode* node);
    void leftRotate (RBNode* node);
    void rightRotate(RBNode* node);
    
};



int main()
{

    return 0;
}