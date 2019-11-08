#include<iostream>
using namespace std;
#define maxn 100000
class stack{
    bool s[maxn];
    int top;
public:
    stack(){
        top=-1;
    }
    void pop(){
        --top;
    }
    void push(bool x){
        s[++top]=x;
    }
    bool empty(){
        return top==-1;
    }
    bool Top(){
        return s[top]; 
    }
    int size(){
        return top+1;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    char ch;
    int count=0;
    stack s;
    bool tmp;
    while(cin>>ch){
        tmp=ch=='(';
        if(s.empty()){
            s.push(tmp);
            continue;
        }
        else{
            if(!tmp&&s.Top()){
                s.pop();
            }
            else s.push(tmp);
        }
    }  
    cout<<s.size();
    return 0;
}