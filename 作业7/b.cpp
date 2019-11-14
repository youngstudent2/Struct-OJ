#include<iostream>
#include<cstdlib>
using namespace std;
inline int max(int x,int y){return x>y?x:y;}
struct actor{
    int weight,height;
    bool operator <(const actor &x){
        return weight<x.weight&&height<x.height;
    }
};
int cmp(const void *a,const void *b){
    return ((actor*)b)->height>((actor*)a)->height;
}

int main(){
    int n;
    cin>>n;
    actor *actors=new actor[n];
    for(int i=0;i<n;i++){
        cin>>actors[i].height>>actors[i].weight;
    }
    qsort(actors,n,sizeof(actor),cmp);
    /*
    for(int i=0;i<n;i++){
        cout<<actors[i].height<<' '<<actors[i].weight<<endl;
    }
    cout<<endl;
    */
    int *dp=new int[n];

    for(int i=0;i<n;i++){
        dp[i]=1;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(actors[i]<actors[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans;
    
    

    return 0;
}
/*
4
5 4
6 4
6 7
2 3
*/