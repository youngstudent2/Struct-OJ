#include<iostream>
using namespace std;
int min(int a,int b){return a<b?a:b;}
int main()
{
    int n;
    cin>>n;
    int map[50][50];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
        }
    }
 
    int dp[50][50];
    dp[0][0]=map[0][0];
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+map[i][0];
        dp[0][i]=dp[0][i-1]+map[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+map[i][j];
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}