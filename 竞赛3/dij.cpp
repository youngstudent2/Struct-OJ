	#include<cstdio>
	#include<cstdlib>
	#include<algorithm>
	#include<iostream>
	#include<math.h>
	#include<queue>
	#include<cstring>
	#include<string>
	using namespace std;	
	typedef long long LL;
	#define MAX 30010
	#define INF 1<<30
 
	struct edge {
		int to;
		LL cost;
	}temp;
	int V;
	vector<edge>G[MAX];
	LL d[MAX];
	int used[MAX];
 
	void dij() {
		while (true) {
			int p = 0;
			for (int i = 1; i <= V; i++) {
				if (d[i] < d[p] && used[i] == 0) p = i;
			}//找出距离最小的点
			if (p == 0)break;
			used[p] = 1;
			for (int i = 0; i < G[p].size(); i++) {
				d[G[p][i].to] = min(d[G[p][i].to], d[p] + G[p][i].cost);
			}//用距离最小的点松弛
		}
	}
 
	int main() {
		//ios::sync_with_stdio(false);
		int n;
		scanf_s("%d%d", &V, &n);//V个学生 n个关系 学生下标从1开始
		for (int i = 0; i < n; i++) {
			edge temp; int from;
			scanf_s("%d%d%lld", &from, &temp.to, &temp.cost);
			G[from].push_back(temp);
		}
		//fill(d, d + V + 1, INF);
		for (int i = 0; i <= V; i++)d[i] = INF;
		memset(used,0,sizeof(used));
		for (int i = 0; i < G[1].size(); i++) {
			d[G[1][i].to] = G[1][i].cost;
		}
		d[1] = 0;//初始化
		dij();
		printf("%lld\n", d[V]);
	}
 
