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
    int nodeNum;
    int inOrder(TreeNode* p,int* arr) {
        int len = 0;
        if(p->left)
            len+=inOrder(p->left,arr);
        *(arr+len)=p->val;
        if(p->right)
            len+=inOrder(p->right,arr+1+len);
        return len+1;
    }
    void buildTree(TreeNode* p){
        int val;
        if(cin>>val&&val!=-1){
            p->left=new TreeNode(val);
            buildTree(p->left);
        }
        if(cin>>val&&val!=-1){
            p->right=new TreeNode(val);
            buildTree(p->right);
        }            
    }
public:
    int* inOrderVisit() {
        int* arr = new int[nodeNum];
        inOrder(root,arr);
        return arr;
    }
    Tree(int n):root(NULL),nodeNum(n){}
    void getInput(){
        int val;
        cin>>val;
        if(val==-1)return;
        root=new TreeNode(val);
        buildTree(root);
    }
 
};
int main()
{
    int n;
    cin>>n;
    Tree tree(n);
    tree.getInput();
    int *arr=tree.inOrderVisit();
    /*
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    */
    int first=0,second=0; 
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            if(!first){
                first=arr[i];
                second=arr[i+1];
            }
            else{
                second=arr[i+1];
            }
        }
    }
    cout<<second<<' '<<first;
    return 0;
}
/*
3
1 3 -1 2 -1 -1 -1
*/