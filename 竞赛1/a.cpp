#include<iostream>
using namespace std;
#define maxn 101
bool outside(int a, int m, int n, int nextx, int nexty) {
    return nextx < a || nexty < a || nextx >= m - a || nexty >= n - a;
}
int main()
{
    int n, m;
    int matrix[maxn][maxn];
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    const int dx[4] = { 0,1,0,-1 };
    const int dy[4] = { 1,0,-1,0 };
    int dir = 0;
    int count = m * n;
    int nowx = 0, nowy = 0;
    int a = 0;
    while (count > 0) {
        cout << matrix[nowx][nowy] << ' ';
        count--;
        if (outside(a, m, n, nowx + dx[dir], nowy + dy[dir]) || (nowx - a - 1 == 0 && dir == 3))++dir;
        if (dir > 3) {
            dir = 0; ++a;
        }
        nowx += dx[dir];
        nowy += dy[dir];
 
         
    }
    //system("pause");
    return 0;
}