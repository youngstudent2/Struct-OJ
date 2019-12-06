#include<iostream>
using namespace std;
bool g[201][201];
int main()
{
    int n,m;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]){
                if(i>0&&!g[i-1][j]){//up
                    dfs(i-1,j);
                }
                if(i)    
            }
        }
    }

    return 0;
}

