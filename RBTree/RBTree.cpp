#include<iostream>
using namespace std;
enum COLOR{
    RED,
    BLACK
};
template<class K,class V>
class RBNode{
    public:
        RBNode<K,V> *left,*right,*parent;
        V val;
        K key;
        COLOR color;
        RBNode(const K& k=K(),const V&value=V())
            :left(NULL),
            right(NULL),
            val(v),
            key(k),
            color(RED)
        {}        
};
template<class K,class V>
class RBTree{
private: 
    RBNode<K,V>* root;
public:
    RBTree():root(NULL);
    RBNode<K,V>* insert(const K&key,const V&value);
    RBNode<K,V>* search(const K&key);
    RBNode<K,V>* predecessor(RBNode<K,V>* node)const;
    RBNode<K,V>* successor(RBNode<K,V>* node)  const;
    bool remove(const K&key);
    void inOrder();
    
private:
    void insertFixUp(RBNode<K,V>* &parent,RBNode<K,V>* &cur);
    void removeFixUp(RBNode<K,V>* node);
    void leftRotate(RBNode<K,V>* &node);
    void rightRotate(RBNode<K,V>* &node);
    void check(RBNode<K,V>* &parent,RBNode<K,V>* &cur);
    void inOrderVisit(RBNode<K,V>* root);
};
template<class K,class V>
RBNode<K,V>* RBTree<K,V>::search(const K&key){
    RBNode<k,V>* cur=root;
    while(cur||cur->key!=key){
        if(cur->key>key)
            cur=cur->left;
        else
            cur=cur->right;
    }
    return cur;
}
template<class K,class V>
RBNode<K,V>* RBTree<K,V>::insert(const K&key,const V&value){
    if(root==NULL){
        root=new RBNode<K,V>(key,value);
        root->color=BLACK;
        return root;
    }
    // find insert position
    RBNode<K,V>* cur=root;
    RBNode<K,V>* parent=NULL;
    while(cur){
        if(cur->key>key){
            parent=cur;
            cur=cur->left;
        }
        else if(cur->key<key){
            parent=cur;
            cur=cur->right;
        }
        else{
            return NULL;
        }
    }
    cur=new RBNode<K,V>(key,value);
    cur->parent=parent;
    if(parent->letf>key)
        parent->left=cur;
    else
        parent->right=cur;

    // check color
    insertFixUp(parent,cur);
    root->color=BLACK;
    return cur;
}

template<class K,class V>
void RBTree<K,V>::insertFixUp(RBNode<K,V>* &parent,RBNode<K,V>* &cur){
    while(parent&&parent->color==RED){
        RBNode<K,V>* grandfather=parent->parent;
        if(parent==grandfather->left){
            RBNode<k,V>* uncle=grandfather->right;
            if(uncle&&uncle->color==RED){
                grandfather->color=RED;
                parent->color=BLACK;
                uncle->color=BLACK;
                cur=grandfather;
                parent=grandfather->parent;
            }
            else if((uncle&&uncle->color==BLACK)||uncle==NULL){
                if(cur==parent->left){    //rotate right
                    parent->color=BLACK;
                    grandfather->color=RED;
                    rightRotate(grandfather);
                }
                else{
                    leftRotate(parent);
                    parent->color=BLACK;
                    grandfather->color=RED;
                    rightRotate(grandfather);
                }
                break;
            }
        }
        else if(parent==grandfather->right){
            RBNode<K,V>* uncle=grandfather->left;
            if(uncle&&uncle->color==RED){
                grandfather->color=RED;
                parent->color=BLACK;
                uncle->color=BLACK;
                cur=grandfather;
                parent=cur->parent;
            }
            else if((uncle&&uncle->color==BLACK)||uncle==NULL){
                if(cur==parent->right){  //left rotate
                    parent->color=BLACK;
                    grandfather->color=RED;
                    rightRotate(grandfather);
                }
                else if(cur==parent->left){
                    rightRotate(parent);
                    parent->color=BLACK;
                    grandfather->color=RED;
                    rightRotate(grandfather);
                }
                break;
            }
        }
    }
}

template<class K,class V>
bool RBTree<K,V>::remove(const K& key){
    RBNode<K,V>* tmp=search(key);
    if(tmp==NULL)return false;
    
    RBNode<K,V>* parent=tmp->parent;
    RBNode<K,V>* subL=tmp->left;
    RBNode<K,V>* subR=tmp->right;

    if(subL==NULL&&subR==NULL){
        if(parent->left==tmp)
            parent->left=NULL;
        else
            parent->right=NULL;
        delete tmp;
    }
    else if(subL==NULL){
        if(parent->left==tmp)
            parent->left=subR;
        else
            parent->right=subR;
        subR->parent=parent;
        delete tmp;
    }
    else if(subR==NULL){
        if(parent->left==tmp)
            parent->left=subL;
        else
            parent->right=subL;
        subL->parent=parent;
        delete tmp;
    }
    else{
        
    }
}

template<class K,class V>
void RBTree<K,V>::leftRotate(RBNode<K,V>* &node){
    RBNode<K,V>* parent=node->parent;
    RBNode<K,V>* subR=node->right;
    RBNode<K,V>* subRL=subR->left;

    parent->right=subRL;
    if(subRL)subRL->parent=node;
    subR->left=node;
    node->parent=subR;
    if(parent==NULL){
        subR->parent=NULL;
        root=subR;
    }
    else{
        subR->parent=parent;
        if(parent->left==node)
            parent->left=subR;
        else{
            parent->right=subR;
        }
    }
    parent=subR;
}

template<class K,class V>
void RBTree<K,V>::rightRotate(RBNode<K,V>* &node){
    RBNode<K,V>* parent=node->parent;
    RBNode<K,V>* subL=node->left;
    RBNode<K,V>* subLR=subL->right;

    parent->left=subLR;
    if(subLR)subLR->parent=node;
    subL->right=node;
    node->parent=subL;
    if(parent==NULL){
        subL->parent=NULL;
        root=subL;
    }
    else{
        subL->parent=parent;
        if(parent->right==node)
            parent->right=subL;
        else{
            parent->left=subL;
        }
    }
    parent=subL;
}
template<class K,class V>
void RBTree<K,V>::inOrderVisit(RBNode<K,V>* root){
    if(root==NULL)return;
    inOrderVisit(root->left);
    cout<<root->key<<" ";
    root->right;
}
template<class K,class V>
void RBTree<K,V>::inOrder(){
    inOrderVisit(root);
}



int main()
{

    return 0;
}