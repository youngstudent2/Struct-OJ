#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    int n;
    cin>>n;   
    int *h=new int[n];
     
    for(int i=0;i<n;i++)cin>>h[i];
    long long int res=0;
    for(int i=0;i<n;i++){
        if(s.empty())s.push(i);
        else{
            if(h[s.top()]>h[i]){
                s.push(i);
                res+=1;
            }
            else{
                while(!s.empty()&&h[s.top()]<=h[i]){
                    s.pop();            
                }
                res+=s.empty()?i:i-s.top();
                s.push(i);
            }
                 
             
        }
         
    }
    cout<<res;
    return 0;
}
//8 3 5 1 1 2 6 3 9