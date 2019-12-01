#include<iostream>
#include<algorithm>
using namespace std;
struct Edge {
	int x, y;
	int cost;
	friend istream& operator>>(istream& in, Edge& e) {
		in >> e.x >> e.y >> e.cost;
		--e.x; --e.y;
		return in;
	}
	void build(int x, int y, int cost) {
		this->x = x; this->y = y; this->cost = cost;
	}
};
class Union {
private:
	int *eles;
public:
	Union(int n) {
		eles = new int[n];
		for (int i = 0; i < n; i++) {
			eles[i] = i;
		}
	}
	int find(int x) {
		int fx = eles[x];
		if (x != fx) {
			eles[x] = find(fx);
		}

		return eles[x];
	}
	void unionSet(int x, int y) {
		int rx = find(x);
		int ry = find(y);
		eles[ry] = rx;
	}
	bool inUnion(int x, int y) {
		return find(x) == find(y);
	}
};
int main()
{
	long long int total_cost = 0;
	Edge* edges;
	int n, m;
	cin >> n >> m;
	Union u(n + 1);
	edges = new Edge[m + n];
	//input dry path
	for (int i = 0; i < m; i++) {
		cin >> edges[i];
	}
	//input water path
	int cost;
	int harbor_num = 0;
	for (int i = 0; i < n; i++) {
		cin >> cost;
		if (cost >= 0) {
			edges[m+harbor_num].build(i, n, cost);
			++harbor_num;
		}

	}

	//sort edges
	int edge_num = m + harbor_num;
	sort(edges, edges + edge_num,
		[](const Edge& e1, const Edge& e2)->bool {return e1.cost < e2.cost; }
	);
	//Kruskal build MST
	int harbor_count = 0;
	int last_harbor_cost = -1;
	for (int i = 0; i < edge_num; i++) {
		if (edges[i].cost < 0) {  //all the money road should be available
			u.unionSet(edges[i].x, edges[i].y);
			total_cost += edges[i].cost;
		}
		else if (!u.inUnion(edges[i].x, edges[i].y)) {
			u.unionSet(edges[i].x, edges[i].y);
			total_cost += edges[i].cost;
			if (edges[i].y == n) {
				last_harbor_cost = edges[i].cost;
				harbor_count++;
			}
		}
	}
	//if harbor city == 1 then remove this edge cost
	if (harbor_count == 1)
		total_cost -= last_harbor_cost;

	cout << total_cost;
	//system("pause");
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