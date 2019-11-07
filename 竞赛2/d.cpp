#include<iostream>
using namespace std;
int abs(int a){return a>0?a:-a;}
struct TreeNode {
    int val;
    TreeNode *l, *r;
    TreeNode(int val) {
        this->val = val;
        l = NULL;
        r = NULL;
    }
};
 
class Tree {
private:
    TreeNode *root;
    int ans;
    int initial(TreeNode* p, int arr[], int now) {
        int len = 0;
        if (arr[now + 1] != -1) {
            p->l = new TreeNode(arr[now + 1]);
            len += initial(p->l, arr, now + 1);
        }
        else len++;
        if (arr[now + len+1] != -1) {
            p->r = new TreeNode(arr[now + len+1]);
            len += initial(p->r, arr, now + len+1);
        }
        else len++;
        return len + 1;
    }
    int divide(TreeNode* p){
        if(!p)return 0;
        int move_l=divide(p->l);
        int move_r=divide(p->r);
        ans+=abs(move_l)+abs(move_r);
        return p->val+move_l+move_r-1;
    }
public:
    Tree(int arr[], int n) {
        if (arr[0]==-1) {
            root = NULL;
            return;
        }
        root = new TreeNode(arr[0]);
        initial(root, arr, 0);
        ans=0;
    }
    int solve(){
        divide(root);
        return ans;
    }
};
 
 
 
int main()
{
    int n=0;
    int a[30010]; 
    while(cin>>a[n++]);
    Tree tree(a,n);
    cout<<tree.solve();
 
    return 0;
}