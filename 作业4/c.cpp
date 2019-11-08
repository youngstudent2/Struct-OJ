#include<iostream>
using namespace std;
int max(int &a, int &b) { return a > b ? a : b; }
struct TreeNode{
    TreeNode *left, *right;
    int dp;
    TreeNode() {
        left = NULL;
        right = NULL;
    }
};
class Tree {
private:
    TreeNode* root;
    TreeNode* pool;
    int LongestPathLength;
    int nodeNum;
    int findLongestPath(TreeNode* p) {
        if (!p->left && !p->right)return 0;
        int l = 0, r = 0;
        if (p->left) {
            l = findLongestPath(p->left) + 1;
        }
        if (p->right) {
            r = findLongestPath(p->right) + 1;
        }
        int sum = l + r + 2;
        LongestPathLength = max(LongestPathLength, sum);
        return max(l, r);
    }
public:
    Tree(int n) {
        nodeNum = n;
        pool = new TreeNode[n];
        root = &pool[0];
    }
    void addChild(int i, int l, int r) {
        TreeNode* p = &pool[i];
        if (l > -1) {
            p->left = &pool[l];
        }
        if (r > -1) {
            p->right = &pool[r];
        }   
    }
    int solve() {
        findLongestPath(root);
        return (nodeNum << 1) - LongestPathLength;
    }
 
};
int main()
{
    int n;
    cin >> n;
    Tree tree(n);
    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        tree.addChild(i, l, r);
    }
     
    cout << tree.solve();
 
    //system("pause");
    return 0;
}
/*
11
1 2
3 4
9 -1
5 -1
10 6
7 -1
-1 8
-1 -1
-1 -1
-1 -1
-1 -1
*/