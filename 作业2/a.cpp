#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=NULL;
    }
};
class LinkList{
    Node* head;
    Node* tail;
    int length;
public:
    LinkList(){
        head=new Node(0);
        tail=head;
        length=0;
    }
    int moveToTail(Node* pre){
        Node* p=pre->next;
        pre->next=p->next;
        tail->next=p;
        p->next=NULL;
        tail=p;
        --length;
    }
    void divide(int x){
        Node* pre=head;
        Node* p=pre->next;
        int count=0;
        while(count<length){
            if(p->val>=x){
                moveToTail(pre);
                p=pre->next;
            }
            else{
                pre=p;
                p=p->next;
                ++count;
            }           
        }
    }
    void append(int val){
        tail->next=new Node(val);
        tail=tail->next;
        ++length;
    }
    void printNodes(){
        for(Node* p=head->next;p;p=p->next){
            cout<<p->val<<' ';       
        }
    }
};
 
int main()
{
    int n,x,val;
    LinkList l;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>val;
        l.append(val);
    }
    l.divide(x);
    l.printNodes(); 
    return 0;
}
