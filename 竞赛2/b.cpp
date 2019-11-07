#include<iostream>
#include<sstream>
using namespace std;
 
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
    int *order;
    int count;
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
    void inOrderVisit(TreeNode* p) {
        if (p == NULL)return;
        if (p->l)
            inOrderVisit(p->l);
        order[count++] = p->val;
        if (p->r)
            inOrderVisit(p->r);
    }
    void inOrderVisit2(TreeNode* p) {
        if (p == NULL)return;
        if (p->r)
            inOrderVisit2(p->r);
        order[count++] = p->val;
        if (p->l)
            inOrderVisit2(p->l);
    }
public:
    Tree(int arr[], int n) {
        if (arr[0]==-1) {
            root = NULL;
            return;
        }
        root = new TreeNode(arr[0]);
        initial(root, arr, 0);
        order = new int[n];
        count = 0;
    }
    int* LrootR() {
        inOrderVisit(root);
        return this->order;
    }
    int* RrootL() {
        inOrderVisit2(root);
        return this->order;
    }
    bool friend operator==(Tree& a, Tree& b);
};
bool operator==(Tree& a, Tree& b) {
    int *o1 = a.LrootR();
    int *o2 = b.RrootL();
    /*
    for (int i = 0; i < a.count; i++) {
        cout << o1[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < b.count; i++) {
        cout << o2[i] << ' ';
    }
    cout << endl;*/
    if (a.count != b.count)
        return false;
    int n = a.count;
    for (int i = 0; i < n; i++) {
        if (o1[i] != o2[i])return false;
    }
    return true;
}
 
 
int main()
{
    stringstream ss,sss;
    string s;
    int arr[200];
    int n = 0, m = 0;
    getline(cin, s);
    ss << s;
    while (ss >> arr[n])n++;
    Tree a(arr, n);
    getline(cin, s);
    sss << s;
    while (sss >> arr[m])m++;
    Tree b(arr, m);
 
    if (a == b)cout << "YES";
    else cout << "NO";
    //system("pause");
    return 0;
}
/*
2 3 5 -1 -1 4 -1 -1 4 -1 -1
2 4 -1 -1 3 4 -1 -1 5 -1 -1
1 2 -1 5 -1 -1 3 -1 5 -1 -1
1 2 -1 5 -1 -1 3 -1 5 -1 -1
 
*/