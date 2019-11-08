#include<iostream>
#include<string>
using namespace std;
struct TreeNode {
    TreeNode *left, *right, *pre;
    int val;
    int d;
    TreeNode(int val, int d, TreeNode* fa = NULL, TreeNode* left = NULL, TreeNode* right = NULL) {
        this->val = val;
        this->d = d;
        this->left = left;
        this->right = right;
        pre = fa;
    }
};
class Tree {
private:
    TreeNode* root;
    int nodeNum;
    void inOrder(TreeNode* p) {
        if(p->left)inOrder(p->left);
        cout << p->val << ' ';
        if(p->right)inOrder(p->right);
    }
    TreeNode* findNode(int &target, TreeNode* p) {
        TreeNode* tmp = NULL;
        if (p->val == target)tmp = p;
        if (!tmp&&p->left)
            tmp = findNode(target, p->left);
        if (!tmp&&p->right)
            tmp = findNode(target, p->right);
        return tmp;
    }
public:
    Tree(int a[], int n) {
        if (n <= 0) {
            root = NULL;
            return;
        }
        root = new TreeNode(a[0],0);
        nodeNum = n;
        TreeNode** q = new TreeNode*[n];
        q[0] = root;
        for (int i = 0, count = 0; count < n - 1;) {
            if (a[count + 1]==-1) {
                if (count & 1)++i;
                ++count;
            }
            else if (count & 1) {//right
                q[i]->right = new TreeNode(a[++count], q[i]->d + 1, q[i]);
                q[count] = q[i]->right;
                ++i;
            }
            else {//left
                q[i]->left = new TreeNode(a[++count], q[i]->d + 1, q[i]);
                q[count] = q[i]->left;
            }
        }
        delete[] q;
    }
    bool findRelation(int a, int b) {
        if (root == NULL)return false;
        TreeNode *pa = findNode(a, root);
        TreeNode *pb = findNode(b, root);
        return pa->pre != pb->pre&&pa->d == pb->d;
    }
 
    void inOrderVisit() {
        inOrder(root);
        cout << endl;
    }
};
void inputHandle(int* arr, int &n, const string &s) {
    n = 0;
    int num = 0;
    for (auto& ch : s) {
        if (ch == ' ') {
            arr[n++] = num;
            num = 0;
        }
        else if (ch == '#') {
            num = -1;
        }
        else {
            num = num * 10 + (ch - '0');
        }
    }
}
int main() {
    int arr[502], n;
    int a, b;
    string s;
    getline(cin, s);
    s.erase(s.length() - 1);
    s.append(" ");
    inputHandle(arr, n, s);
    /*
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;*/
    cin >> a >> b;
    Tree tree(arr, n);
    //tree.inOrderVisit();
    cout << (tree.findRelation(a, b) ? "true" : "false");
    //system("pause");
    return 0;
}