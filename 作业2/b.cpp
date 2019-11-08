#include<iostream>
using namespace std;
struct Node{
    int val;
    Node *left,*right;
    Node(int x){
        val=x;
        left=right=NULL;
    }
};
class CircleList{
    Node* p;
    int n;
public:
    CircleList(int n){
        //assert(n>0);
        p=new Node(1);
        Node* tmp=p;
        for(int i=2;i<=n;i++){
            tmp->right=new Node(i);
            tmp->right->left=tmp;
            tmp=tmp->right;
        }
        tmp->right=p;
        p->left=tmp;
        this->n=n;
    }
    void out(Node* &pr,Node* &pl,int &n){
        cout<<pr->val<<' '<<pl->val<<' ';
         
        Node* tmp1=pr->left;
        tmp1->right=pr->right;
        tmp1->right->left=tmp1;
         
        Node* tmp2=pl->left;
        tmp2->right=pl->right;
        tmp2->right->left=tmp2;
             
        delete pr;
        delete pl;
        n-=2;
         
        pr=tmp1->right;
        pl=tmp2;
         
     
    }
    int chooseMonitor(int k,int m){
        Node* teacher_left=p->left;
        Node* teacher_right=p;
        while(n>0){
            for(int i=1;i<k;i++)//顺时针清点 
                teacher_right=teacher_right->right;
            for(int i=1;i<m;i++)//逆时针清点 
                teacher_left=teacher_left->left;
                 
            if(teacher_left->val==teacher_right->val){
                cout<<teacher_right->val;
                return teacher_right->val;
            }
             
            //print(teacher_right);
            out(teacher_right,teacher_left,n);
             
        }
    }
    /*for debug
    void print(Node *p){
        Node* tmp=p->right;
        cout<<p->val<<' ';
        while(tmp!=p){
            cout<<tmp->val<<' ';
            tmp=tmp->right;
        }
        cout<<endl;
    }
    */
};
 
int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    CircleList cl(n);
    cl.chooseMonitor(k,m);  
    return 0;
}