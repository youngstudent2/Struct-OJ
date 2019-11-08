#include<iostream>
using namespace std;
struct TreeNode {
    TreeNode *left, *right;
    int w;
    TreeNode(int weight) :w(weight), left(NULL), right(NULL) {}
};
class Tree {
private:
    TreeNode* root;
    int nodeNum;
    void inOrderVisit(TreeNode* p) {
        if (p == NULL)return;
        if (p->left)
            inOrderVisit(p->left);
        cout << p->w << ' ';
        if (p->right)
            inOrderVisit(p->right);
    }
    int mergeExchange(TreeNode* p) {
        if (p == NULL)return 0;
        int left = mergeExchange(p->left);
        int right = mergeExchange(p->right);
        //printf_s("%lld %lld %lld\n", p->w, left, right);
        if (left > right) { //exchange
            TreeNode* tmp = p->left;
            p->left = p->right;
            p->right = tmp;
        }
        return left + right + p->w;
    }
public:
    Tree(int a[], int n) {
        if (n <= 0) {
            root = NULL;
            return;
        }
        root = new TreeNode(a[0]);
        nodeNum = n;
        TreeNode** q = new TreeNode*[n];
        q[0] = root;
        for (int i = 0, count = 0; count < n - 1;) {
            if (count & 1) {//right
                q[i]->right = new TreeNode(a[++count]);
                q[count] = q[i]->right;
                ++i;
            }
            else {//left
                q[i]->left = new TreeNode(a[++count]);
                q[count] = q[i]->left;
            }
        }
        delete[] q;
    }
 
    void mergeAndExchange() {
        mergeExchange(root);
    }
 
    void inOrder() {
        inOrderVisit(root);
    }
 
 
};
int main()
{
    ios::sync_with_stdio(false);
    int n;
    int *a;
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)cin >> a[i];
    Tree tree(a, n);
    tree.mergeAndExchange();
    tree.inOrder();
    //system("pause");
    return 0;
}
 
//6 3 2 1 6 4 5