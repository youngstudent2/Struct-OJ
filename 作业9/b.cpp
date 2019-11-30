#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 50000
struct Edge{
    int x,y;
    friend istream& operator>>(istream &in,Edge& e){
        in>>e.x>>e.y;
        return in;
    }
    bool operator<(const Edge& e){
        if(x<e.x)
            return true;
        else if(x==e.x)
            return y<e.y;
        else 
            return false;
    } 
};
Edge *edges;
int d[maxn];
int val[maxn];
int n,m;
void search(int node){
    for(int i=0;i<m;i++){
        if(edges[i].x==node){
            val[edges[i].x]++;
            search(edges[i].y);
        }
    }
}
int main()
{
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        d[i]=0;
        val[i]=0;
    }
    edges=new Edge[m];
    for(int i=0;i<m;i++){
        cin>>edges[i];
        d[edges[i].x]++;
        d[edges[i].y]++;
    }
    for(int i=0;i<m;i++){
        cout<<edges[i].x<<' '<<edges[i].y<<endl;
    }
    sort(edges,edges+m);
    for(int i=0;i<n;i++){
        if(d[i]==1){
            search(i);
        }
    }

/*
    for(int i=0;i<m;i++){
        cout<<edges[i].x<<' '<<edges[i].y<<endl;
    }
*/
    return 0;
}
/*
4 3
1 0
1 2
1 3
*/
