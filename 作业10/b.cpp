#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 32767	//INF表示∞
typedef struct  				
{
	int **edges; 		        
	int n, e;   				
} MGraph;						


int* Dijkstra(MGraph &g, int v, int **&driver)
{
	int n = g.n, totaln = g.n * 2;
	int *dist = new int[totaln], *path = new int[totaln];
	int *s = new int[totaln];
	int mindis, i, j, u;
	for (i = 0; i < g.n; i++)
	{
		dist[i] = 1 == driver[v][i] ? g.edges[v][i] : INF;   	//距离初始化
		s[i] = 0;                		//s[]置空

	}
	for (i = 0; i < g.n; i++)
	{
		dist[i + n] = 2 == driver[v][i] ? g.edges[v][i] : INF;   	//距离初始化
		s[i + n] = 0;                		//s[]置空
	}

	s[v] = 1;		
	s[v + n] = 1;
	for (i = 0; i < totaln; i++)    			
	{
		mindis = INF;				
		for (j = 0; j < totaln; j++)     	
			if (s[j] == 0 && dist[j] < mindis)
			{
				u = j;
				mindis = dist[j];
			}
		s[u] = 1;               	
		if (u < n) {
			for (j = 0; j < n; j++)     	
				if (s[j + n] == 0)
					if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j + n] && 2 == driver[u][j])
					{
						dist[j + n] = dist[u] + g.edges[u][j];
					}
		}
		else {
			for (j = 0; j < n; j++)     	
				if (s[j] == 0)
					if (g.edges[u - n][j] < INF && dist[u] + g.edges[u - n][j] < dist[j] && 1 == driver[u-n][j])
					{
						dist[j] = dist[u] + g.edges[u - n][j];
					}
		}
	}
	return dist;
}
void inputHandle(int &n, MGraph &g, int** &driver) {
	int m;
	cin >> n >> m;
	g.n = n; g.e = m;
	g.edges = new int*[n];
	driver = new int*[n];

	for (int i = 0; i < n; i++) {
		g.edges[i] = new int[n];
		driver[i] = new int[n];
		for (int j = 0; j < n; j++) {
			g.edges[i][j] = INF;
		}
	}
	int s, e, l, c;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> l >> c;
		g.edges[s][e] = l;
		driver[s][e] = c;
	}

}
int main()
{
	int n;
	MGraph g;
	int **driver;
	inputHandle(n, g, driver);
	int *res1 = Dijkstra(g, 0, driver);
	int *res2 = res1 + n;
	res1[0] = 0; res2[0] = 0;
	int output;
	for (int i = 0; i < n; i++) {
		output = res1[i] < res2[i] ? res1[i] : res2[i];
		if (output >= INF)output = -1;
		cout << output << ' ';
	}
	//system("pause");
	return 0;
}