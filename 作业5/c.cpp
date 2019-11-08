#include<iostream>
using namespace std;
struct TreeNode {
    TreeNode *left, *right;
    int val, d;
    TreeNode() {
        left = NULL;
        right = NULL;
        d = 0;
        this->val = 0;
    }
};
class Tree {
private:
    TreeNode* root;
    TreeNode* pool;
    int nodeNum;
    void inOrderVisit(TreeNode* p) {
        if (p->left)
            inOrderVisit(p->left);
        cout << p->val << ' ';
        if (p->right)
            inOrderVisit(p->right);
    }
public:
    Tree(int n) {
        nodeNum = n;
        pool = new TreeNode[n+1];
        root = &pool[1];
        root->val = 1;
    }
    void addChild(int i, int l, int r) {
        TreeNode* p = &pool[i];
        if (l > -1) {
            p->left = &pool[l];
            p->left->d = p->d + 1;
            p->left->val = l;
        }
        if (r > -1) {
            p->right = &pool[r];
            p->right->d = p->d + 1;
            p->right->val = r;
        }
    }
    void solve() {
        TreeNode** q = new TreeNode*[nodeNum];
        int head = 0, tail = 0;
        q[tail++] = root;
        int currentDepth = 0;
        TreeNode *l = root, *r = root;
        while (head < tail) {
             
            if (q[head]->d > currentDepth) {
                currentDepth = q[head]->d;
                if (l == r) {
                    cout << l->val << ' ';
                }
                else {
                    cout << l->val << ' ' << r->val << ' ';
                }
                l = q[head];
            }
             
            if (q[head]->left)
                q[tail++] = q[head]->left;
            if (q[head]->right)
                q[tail++] = q[head]->right;
 
            r = q[head];
            ++head;
        }
        if (l == r) {
            cout << l->val << ' ';
        }
        else {
            cout << l->val << ' ' << r->val << ' ';
        }
    }
    void inOrder() {
        inOrderVisit(root);
    }
};
int main()
{
    int n;
    cin >> n;
    Tree tree(n);
    int l, r;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        tree.addChild(i, l, r);
    }
    //tree.inOrder();
    //cout << endl;
    tree.solve();
 
    //system("pause");
    return 0;
}