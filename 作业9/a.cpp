#include<iostream>
using namespace std;
 
struct Node {
    int bf,data;
    Node *right, *left;
    Node(int x) {
        bf = 0;
        data = x;
        right = NULL;
        left = NULL;
    }
};
template<class T>
class Stack {
private:
    T *s;
    int top;
public:
    Stack(int n) {
        top = -1;
        s = new T[n];
    }
    void pop(T &x) {
        x = s[top];
        top--;
    }
    T getTop() {
        return s[top];
    }
    void push(T n)
    {
        top++;
        s[top] = n;
    }
    bool empty()
    {
        return top == -1;
    }
};
 
void rotateL(Node *& ptr) {
    Node *subL = ptr;
    ptr = subL->right;
    subL->right = ptr->left;
    ptr->left = subL;
    ptr->bf = subL->bf = 0;
};
void rotateR(Node *& ptr) {
    Node *subR = ptr;  
    ptr = subR->left;
    subR->left = ptr->right;
    ptr->right = subR;
    ptr->bf = subR->bf = 0;
};
void rotateLR(Node *& ptr) {
    Node *subR = ptr;
    Node *subL = subR->left;
    ptr = subL->right;
    subL->right = ptr->left;
    ptr->left = subL;
    if (ptr->bf <= 0) subL->bf = 0;
    else subL->bf = -1;
    subR->left = ptr->right;
    ptr->right = subR;
    if (ptr->bf == -1) subR->bf = 1;
    else subR->bf = 0;
    ptr->bf = 0;
};
void rotateRL(Node *& ptr) {
    Node *subL = ptr;
    Node *subR = subL->right;
    ptr = subR->left;
    subR->left = ptr->right;
    ptr->right = subR;
    if (ptr->bf >= 0) subR->bf = 0;
    else subR->bf = 1;
    subL->right = ptr->left;
    ptr->left = subL;
    if (ptr->bf == 1) subL->bf = -1;
    else subL->bf = 0;
    ptr->bf = 0;
};
 
bool insert(Node *&ptr, int x) {
    Node *pr = NULL;
    Node *p = ptr;
    Node *q;
    int d;
    Stack<Node*> st(20);
    while (p != NULL) {
        if (p->data == x)return false;
        pr = p;
        st.push(pr);
        if (x < p->data)p = p->left;
        else p = p->right;
    }
    p = new Node(x);
    if (pr == NULL) {
        ptr = p;
        return true;
    }
    if (x < pr->data)pr->left = p;
    else pr->right = p;
    while (!st.empty()) {
        st.pop(pr);
        if (p == pr->left)pr->bf--;
        else pr->bf++;
        if (pr->bf == 0)break;
        if (pr->bf == 1 || pr->bf == -1)
            p = pr;
        else {
            d = (pr->bf < 0) ? -1 : 1;
            if (p->bf == d) {
                if (d == -1)rotateR(pr);
                else rotateL(pr);
            }
            else {
                if (d == -1)rotateLR(pr);
                else rotateRL(pr);
            }
            break;
        }
    }
    if (st.empty())ptr = pr;
    else {
        q=st.getTop();
        if (q->data > pr->data)q->left = pr;
        else q->right = pr;
    }
    return true;
}
 
void preOrder(Node *r) {
    if (r) {
        cout << r->data << ' ';
        preOrder(r->left);
        preOrder(r->right);
    }
}
 
int main() {
    int n;
    cin >> n;
    int a[20];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
        insert(head, a[i]);
    preOrder(head);
    return 0;
}