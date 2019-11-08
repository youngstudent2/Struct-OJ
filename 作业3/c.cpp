#include<iostream>
using namespace std;
#define max(x,y) x>=y?x:y
class stack{
    int *s;
    int top;
public:
    stack(int n){
        s=new int[n+3];
        top=-1;
    }
    void pop(){
        --top;
    }
    void push(int x){
        s[++top]=x;
    }
    bool empty(){
        return top==-1;
    }
    int Top(){
        return s[top]; 
    }
    int size(){
        return top+1;
    }
};
 
 
 
int main(){
    int n;
    int *pre_sum;
    int tmp;
    cin>>n;
    pre_sum=new int[n+3];
    //calculate pre sum
 
    pre_sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        pre_sum[i]=pre_sum[i-1]+(tmp>8?1:-1);
         
    }
    //for(int i=0;i<=n;i++)cout<<pre_sum[i]<<' ';
    //cout<<endl;
    //get decresed stack
    stack s(n);
    s.push(0);
    for(int i=0;i<=n;i++){
        if(pre_sum[i]<pre_sum[s.Top()])
            s.push(i);
    }
    //get ans
    int ans=0;
    for(int i=n;i>=0;i--){
        while(!s.empty()&&pre_sum[s.Top()]<pre_sum[i]){
            ans=max(ans,i-s.Top());
            s.pop();
        }
    }
     
    cout<<ans;
    return 0;
}
 
/*
8
9 9 6 0 1 6 9 9
*/