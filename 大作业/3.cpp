#include<iostream>
using namespace std;
struct Node{
    Node* next;
    int val;
    Node():val(0),next(NULL){}
    Node(int v):val(v),next(NULL){}
};
class LinkList{
private:
    Node* root;
    int size;
    int currentSize;
    Node* tail;
public:
    LinkList(int size){
        this->size=size;
        currentSize=0;
        root=new Node;
        tail=NULL;
    }
    void push(int val){
        //如果待插入位置不在队尾，则直接插入，尾节点不用更新
        //如果待插入位置在队尾
        //则判断currentSize<size，若真，则插入，并更新尾节点，否则不插入
        Node* p=root->next;
        ++currentSize;
        while(p){
            if(p->val<val){
                if(!p->next)
                    tail=p;

                Node* tmpNext=p->next;
                p->next=new Node(val);
                p->next->next=tmpNext;

                break;
            }
        }
        if(currentSize>size){
            currentSize=size;
            
        }
    }
    void print(){

    }



};
int main()
{
    int n,k;
    cin>>n>>k;
    LinkList list(k);
    char s[20];
    int x;
    while(scanf("%s",s)){
        if(s[0]=='C'){  //s=="Check"
            list.print();
        }
        else{
            sscanf(s,"%d",&x);
            printf("%d",x);
            list.push(x);
        }
    }



    return 0;
}