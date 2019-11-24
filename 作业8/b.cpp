#include<iostream>
using namespace std;
struct TreeNode{
    TreeNode *left,*right;
    int val;
    TreeNode():left(NULL),right(NULL){}
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};
 
class Tree{
private:
    TreeNode* root;
    int n;
    int res;
    int k;
    void inOrder(TreeNode* p) {
        if(p->left)inOrder(p->left);
        cout << p->val << ' ';
        if(p->right)inOrder(p->right);
    }
    int dfs_setGuard(TreeNode* p){
        if(!p)return 0;
        int left_guard = dfs_setGuard(p->left);
        int right_guard= dfs_setGuard(p->right);
        if(left_guard+right_guard==0)return 1;
        else if(left_guard==1||right_guard==1){
            res++;
            //cout<<p->val<<' ';
            return 2;
        }
        else return 0;
    }
public:
    void inOrderVisit() {
        inOrder(root);
        cout << endl;
    }
    Tree():root(NULL),n(0),res(0),k(0){}
    void getInput(){
        int val;
        cin>>val;
        if(val==-1)return;
        root=new TreeNode(k++);
        buildTree(root);
    }
    void buildTree(TreeNode* p){
        int val;
        if(cin>>val&&val==0){
            p->left=new TreeNode(k++);
            buildTree(p->left);
        }
        if(cin>>val&&val==0){
            p->right=new TreeNode(k++);
            buildTree(p->right);
        }            
    }
    /*
    void getInput(){   
        int v=0;     
        int val;
        cin>>val;
        if(val==-1)return;
        TreeNode* q[1314];
        int tail=0,head=0;
        root=new TreeNode(v++);
        q[tail++]=root;
        int count=0;
         
        while(cin>>val){
            if(val==0){
                if(count){
                    q[head]->right=new TreeNode(v++);
                    q[tail++]=q[head]->right;
                }
                else{
                    q[head]->left=new TreeNode(v++);
                    q[tail++]=q[head]->left;
                }
            }
            if(++count>=2){
                ++head;
                count=0;
            }
        }
        n=tail;     
    }
    */
    int setGuard(){
        TreeNode* fakeHead=new TreeNode;
        fakeHead->left=root;
        dfs_setGuard(fakeHead);      
        return res;
    }
 
};
 
 
 
int main()
{
    Tree tree;
    tree.getInput();
    //tree.inOrderVisit();
    cout<<tree.setGuard();
    return 0;
}
/*
0 0 -1 -1 0 0 -1 0 -1 -1 -1
 
*/