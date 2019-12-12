#include<iostream>
using namespace std;

void inputHandle(int &n,int &m,char *coin,int* r){
    cin>>n>>m;
    r=new int[n];
    coin=new char[n];
    g=new int*[n];
    for(int i=0;i<n;i++)g[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]=0;
    cin>>coin;
    for(int i=0;i<n;i++)coin[i]-='a';
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        --a;--b;++r[b];
        g[a][b]=1;
        
    }
}
int main()
{
    int n,m;
    char *coin;
    int *r;
    int **g;
    inputHandle();
    return 0;
}