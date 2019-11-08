#include<iostream>
using namespace std;
struct node{
    node *pre,*next;
    char val;
    node(char val){
        this->val=val;
        pre=NULL;next=NULL;
    }
};
class LinkedList{
    node *head,*tail;
    void printWord(node *p){
        p=p->next;
        while(p&&p->val!=' '){
            cout<<p->val;
            p=p->next;
        }
    }
public:
    LinkedList(){
        head=new node(0);
        tail=head;
    }
    void add(char ch){
        tail->next=new node(ch);
        tail->next->pre=tail;
        tail=tail->next;
    }
    void reverse(){
        node *p=tail;
        while(p!=head){
            if(p->val==' '){
                printWord(p);
                cout<<' ';
            }
            p=p->pre;
        }
        printWord(p);
    }
};
 
int main()
{
    ios::sync_with_stdio(false);
    char ch;
    LinkedList l;
    ch=getchar();
    while(ch>26){
        l.add(ch);
        ch=getchar();
    }
    l.reverse();
    return 0;
}
//i am a student2