#include <string.h>  
#include <algorithm>  
#include <stdio.h>  
#include <math.h>  
#include <queue>  
#define MAXN 100010  
#define inf 0x3f3f3f3f  
  
using namespace std;  
  
struct node{  
    int l,r;//区间[l,r]  
    int add;//区间的延时标记  
    int sum;//区间和  
    int mx; //区间最大值  
    int mn; //区间最小值  
}tree[MAXN<<2];//一定要开到4倍多的空间  
  
void pushup(int index){  
    tree[index].sum = tree[index<<1].sum+tree[index<<1|1].sum;  
    tree[index].mx = max(tree[index<<1].mx,tree[index<<1|1].mx);  
    tree[index].mn = min(tree[index<<1].mn,tree[index<<1|1].mn);  
}  
void pushdown(int index){  
    //说明该区间之前更新过  
    //要想更新该区间下面的子区间，就要把上次更新该区间的值向下更新  
    if(tree[index].add){  
        //替换原来的值  
        //在原来的值的基础上加上val  
          
        tree[index<<1].sum += (tree[index<<1].r-tree[index<<1].l+1)*tree[index].add;  
        tree[index<<1|1].sum +=(tree[index<<1|1].r-tree[index<<1|1].l+1)*tree[index].add;  
        tree[index<<1].mx += tree[index].add;  
        tree[index<<1|1].mx += tree[index].add;  
        tree[index<<1].mn += tree[index].add;  
        tree[index<<1|1].mn += tree[index].add;  
        tree[index<<1].add += tree[index].add;  
        tree[index<<1|1].add += tree[index].add;  
        tree[index].add = 0;  
  
    }  
}  
void build(int l,int r,int index){  
    tree[index].l = l;  
    tree[index].r = r;  
    tree[index].add = 0;//刚开始一定要清0  
    if(l == r){  
        scanf("%d",&tree[index].sum);  
        tree[index].mn = tree[index].mx = tree[index].sum;  
        return ;  
    }  
    int mid = (l+r)>>1;  
    build(l,mid,index<<1);  
    build(mid+1,r,index<<1|1);  
    pushup(index);  
}  
void updata(int l,int r,int index,int val){  
    if(l <= tree[index].l && r >= tree[index].r){  
        //在原来的值的基础上加上val,因为该区间有tree[index].r-tree[index].l+1  
        //个数，所以区间和 以及 最值为：  
        tree[index].sum += (tree[index].r-tree[index].l+1)*val;  
        tree[index].mn += val;  
        tree[index].mx += val;  
        tree[index].add += val;//延时标记  
  
        return ;  
    }  
    pushdown(index);  
    int mid = (tree[index].l+tree[index].r)>>1;  
    if(l <= mid){  
        updata(l,r,index<<1,val);  
    }  
    if(r > mid){  
        updata(l,r,index<<1|1,val);  
    }  
    pushup(index);  
}  
int query(int l,int r,int index){  
    if(l <= tree[index].l && r >= tree[index].r){  
        return tree[index].sum;  
        //return tree[index].mx;  
        //return tree[index].mn;  
    }  
    pushdown(index);  
    int mid = (tree[index].l+tree[index].r)>>1;  
    int ans = 0;  
    int Max = 0;  
    int Min = inf;  
    if(l <= mid){  
        ans += query(l,r,index<<1);  
        //Max = max(query(l,r,index<<1),Max);  
        //Min = min(query(l,r,index<<1),Min);  
    }  
    if(r > mid){  
        ans += query(l,r,index<<1|1);  
        //Max = max(query(l,r,index<<1|1),Max);  
        //Min = min(query(l,r,index<<1|1),Min);  
    }  
    return ans;  
    //return Max;  
    //return Min;  
}  
int main()  
{  
    int n,m,q,x,y,z;  
    while(~scanf("%d%d",&n,&m)){  
        build(1,n,1);  
        while(m--){  
            scanf("%d",&q);  
            if(q == 1){  
                cout<<"查询:(x,y)"<<endl;  
                scanf("%d %d",&x,&y);  
                cout<<query(x,y,1)<<endl;  
            }  
            else{  
                cout<<"更新(x,y)为z："<<endl;  
                scanf("%d %d %d",&x,&y,&z);  
                updata(x,y,1,z);  
                for(int i = 1; i <= n; ++i){  
                    printf("a[%d] = %d\n",i,query(i,i,1));  
                }  
            }  
        }  
    }  
    return 0;  
}
