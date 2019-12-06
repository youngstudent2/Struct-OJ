#include<iostream>
#include<vector>
using namespace std;
struct Edge{
    int to;
    int g;
    friend istream& operator>>(istream& in,Edge& e){
        cin>>e.to>>e.g;
        return in;
    }
    Edge(){}
    Edge(int v1,int g1):to(v1),g(g1){}
};
int inputHandle(int& v,int &e,int&l,int* &g,vector<Edge>* &G){
    cin>>v>>e>>l;
    G=new vector<Edge>[v+1];
    g=new int[v+1];
    for(int i=1;i<=v;i++){
        cin>>g[i];
    }
    int u;
    Edge tmp;
    for(int i=0;i<e;i++){
        cin>>u;
        cin>>tmp;
        G[u].push_back(tmp);
    }
}
inline int min(int a,int b){return a<b?a:b;}
int dij(int e,int v,vector<Edge>* &G){
    int *d=new int[v+1];
    bool *used=new bool[v+1];
    for(int i=2;i<=v;i++)d[i]=0xfffffff;
    for (int i = 0; i < G[1].size(); i++) {
			d[G[1][i].to] = G[1][i].g;
		}
    d[1]=0;
    while(true){
            int p = 0;
			for (int i = 1; i <= v; i++) {
				if (d[i] < d[p] && used[i] == 0) p = i;
			}
			if (p == 0)break;
			used[p] = 1;
			for (int i = 0; i < G[p].size(); i++) {
				d[G[p][i].to] = min(d[G[p][i].to], d[p] + G[p][i].g);
			}
    }
    return d[v];
}
int main()
{
    int v,e,l,*g;
    vector<Edge> *G;
    inputHandle(v,e,l,g,G);
    cout<<dij(e,v,G,g);
  

    return 0;
}

