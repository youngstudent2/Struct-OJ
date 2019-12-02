#include<iostream>
using namespace std;
struct Edge{
    int x,y;
    friend istream& operator>>(istream &in,Edge& e){
        in>>e.x>>e.y;
        return in;
    }

};
int* find(int n,int m,Edge *edges){
    int num=n;
    int *res=new int[n];
    int count=0;
    if(n==1){
        res[0]=0;
        return res;
    }
    int *d=new int[n];
    int *w=new int[n];
    for (int i = 0; i < n; i++) {
		d[i] = 0; w[i] = 0;
	}
    for(int i=0;i<m;i++){
        int x=edges[i].x;
        int y=edges[i].y;
        d[x]++;d[y]++;
        w[x]+=y;w[y]+=x;
    }
    for(int i=0;i<n;i++){
        if(d[i]==1)
            res[count++]=i;
    }
    //count should be tail
    for(int i=0;n>2;i=0){
        for(int j=0;j<count;++j,--n){
            const int dest=w[res[j]];
            w[dest]-=res[j];
            if(--d[dest]==1)
                res[i++]=dest;
        }
        count=i;
    }
    res[count]=-1;
    return res;
}

int main()
{
    Edge *edges;
    int n,m;
    cin>>n>>m;
    if(m==0)return 0;
    edges=new Edge[m];
    for(int i=0;i<m;i++){
        cin>>edges[i];
    }

    int *res;;
    res=find(n,m,edges);
    if (*(res+1)==-1) {
        cout << res[0];
    }
    else if(*(res+2)==-1){
        if (res[0] < res[1])cout << res[0] << ' ' << res[1];
        else cout << res[1] << ' ' << res[0];
    }

    return 0;
}
/*
4 3
1 0
1 2
1 3
*/
