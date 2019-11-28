#include<iostream>
#include<algorithm>
using namespace std;
struct Edge{
    int x,y;
    int cost;
    friend istream& operator>>(istream& in,Edge& e){
        in>>e.x>>e.y>>e.cost;
        return in;
    }
    void reverse_copy(const Edge& e){
        x=e.y;
        y=e.x;
        cost=e.cost;
    }
};
struct Harbor{
    int cost;
    int city;
    friend bool operator>(const Harbor& h1,const Harbor& h2){
        return h1.cost>h2.cost;
    }
};
int findMinPath(int city,Edge* edges,int *LUT){
    int index=LUT[city];
    if(index==-1){
        return 0xfffffff;
    }
    else return edges[index].cost;
}
int main()
{
    long long int total_cost=0;
    Edge* edges;
    Harbor *harbors;
    int *LUT;
    bool *build_harbor;
    int n,m;
    cin>>n>>m;
    edges=new Edge[m<<1];
    harbors=new Harbor[n];
    LUT=new int[n];
    build_harbor=new bool[n];
    for(int i=0;i<m;i++){
        cin>>edges[i];
        edges[i+m].reverse_copy(edges[i]);
    }
    for(int i=0;i<n;i++){
        LUT[i]=-1;
        build_harbor[i]=true;
        cin>>harbors[i].cost;
        if(harbors[i].cost==-1)
            harbors[i].cost=0xfffffff;
        harbors[i].city=i;
        total_cost+=harbors[i].cost;
        //might be overflow
    }
    sort(harbors,harbors+n,
    [](const Harbor& h1,const Harbor& h2)->bool{return h1>h2;});
    sort(edges,edges+m,
    [](const Edge& e1,const Edge& e2)->bool{
        if(e1.x<e2.x)return true;
        else if(e1.x>e2.x)return false;
        else{
            return e1.cost<e2.cost;
        }
    });
    for(int currentCity=-1,i=0;i<m;i++){
        if(currentCity<edges[i].x){
            currentCity=edges[i].x;
            LUT[currentCity]=i;
        }        
    }
    for(int i=0;i<n;i++){
        int min_path=findMinPath(harbors[i].city,edges,LUT);
        if(harbors[i].cost>min_path){
            build_harbor[harbors[i].city]=false;
            total_cost=total_cost-harbors[i].cost+min_path;
        }
    }

    cout<<total_cost;

    

    return 0;
}
/*
5 6
1 2 7
1 3 5
1 4 4
1 5 8
2 3 6
4 5 10
-1 10 1 2 10
*/