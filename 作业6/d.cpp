#include<iostream>
using namespace std;
struct element{
    int father;
    int relation;
    //relation x.rel-y.rel: 0-same 1-magic_to 2,3-just_so_so 4-be_magic_to
};
element *eles;
int rx,ry;
void makeSet(element* &arr,int n){
    arr=new element[n];
    for(int i=0;i<n;i++){
        arr[i].father=i;
        arr[i].relation=0;
    }
}
int find(int x){
    int fx=eles[x].father;
    if(x!=fx){
        eles[x].father=find(fx);
        eles[x].relation=(eles[x].relation+eles[fx].relation)%5;
    }
         
    return eles[x].father;
}
 
 
inline bool check(int k,int x,int y){
    rx=find(x);ry=find(y);
    if(k==0){
        //x and y is in the same set and if their relations are not equal return false 
        if(rx==ry&&eles[x].relation!=eles[y].relation)return false;
        else return true;
    }
    else{
        if(rx==ry&&((eles[x].relation+1)%5!=eles[y].relation))return false;
        else return true;
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    int k,x,y;
    int ans=0;
    cin>>n>>m;
     
    makeSet(eles,n);
    for(int i=0;i<m;i++){
        cin>>k>>x>>y;
        if((x>n||y>n)||(k==1&&x==y)){
            ans++;
            continue;
        }
        if(check(k,x,y)){
            if(k==0){
                if(rx!=ry){
                    //union
                    eles[ry].father=rx;
                    eles[ry].relation=(eles[x].relation-eles[y].relation+5)%5;
                }
            }
            else{
                if(rx!=ry){
                    //union
                    eles[ry].father=rx;
                    eles[ry].relation=(5-eles[y].relation+eles[x].relation+1)%5;
                }
            }
            
        }
        else ++ans;
    }
    cout<<ans;
 
    return 0;
}