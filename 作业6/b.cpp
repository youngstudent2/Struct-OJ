#include<iostream>
using namespace std;
int main()
{
    int a[1002]={0};
    int n;
    while(cin>>n){
        a[n+1]++;
    }
    int sum=0;
    for(int i=1;i<1002;i++){
        if(a[i]){
            sum+=((a[i]-1)/i+1)*i;
        }
    }
    cout<<sum;
    return 0;
}