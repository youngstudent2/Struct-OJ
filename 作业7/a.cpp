#include<iostream>
using namespace std;
#define maxn 500
int r[4][maxn];
int a[10001]={0},b[10001]={0};
int n;


int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    int tmp;
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++)
            cin>>r[i][j];
    }   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp=r[0][i]+r[1][j];
            if(tmp<=10000)
            a[tmp]++;
            tmp=r[2][i]+r[3][j];
            if(tmp<=10000)
            b[tmp]++;
        }
    }
    int ans = 0;
    for(int i=0;i<10000;i++){
        ans+=a[i]*b[10000-i];
    }
    cout<<ans;

    return 0;
}
/*
2
1000 2000
3000 2000
2000 3000
1000 3000

*/