#include<iostream>
using namespace std;
#define maxn 100000
int main()
{
    int m,n;
    int a[maxn],b[maxn];
    while(cin>>m>>n){
        int i=0,j=0;
        for(;i<m;i++){
            cin>>a[i];
        }
        for(;j<n;j++){
            cin>>b[j];
        }
        i=0;j=0;
        cout<<(a[i]<b[j]?a[i++]:b[j++]);
        for(;i<m&&j<n;){
            cout<<' '<<(a[i]<b[j]?a[i++]:b[j++]);            
        }
        for(;i<m;i++)cout<<' '<<a[i];
        for(;j<n;j++)cout<<' '<<b[j];
        cout<<endl;
    }
     
    return 0;
}