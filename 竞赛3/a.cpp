#include<iostream>
using namespace std;
int ans = 0, n, l, t = 0, *ls;
bool *B;
struct Edge {
	int y, next;
};
Edge* a;
void dfs(int k) {
	for (int i = ls[k]; i>0; i = a[i].next)
		if (B[a[i].y] == false) {
			B[a[i].y] = true;
			dfs(a[i].y);
		}
}
int main() {
	int x, y;
	int n, m, k;
	scanf("%d%d%d", &m, &n, &k);
	a = new Edge[(k << 1)+2];
	ls = new int[n*m+2];
	B = new bool[n*m+2];
	for (int i = 0; i < n*m; i++) {
		B[i] = false;
	}
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &x, &y);
		a[++t].y = y; a[t].next = ls[x]; ls[x] = t;
		a[++t].y = x; a[t].next = ls[y]; ls[y] = t;
	}
	for (int i = 1; i <= n*m; ++i)
		if (B[i] == false) {
			B[i] = true;
			dfs(i);
			ans++;
		}
	printf("%d", ans);
	//system("pause");
}
/*
5 4
16
2 3
1 5
5 9
4 8
7 8
9 10
10 11
11 12
10 14
12 16
14 18
17 18
15 19
19 20
9 13
13 17

*/