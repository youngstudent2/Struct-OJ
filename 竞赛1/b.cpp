#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main()
{
    int m, n;
    stack<int> s1;
    queue<int> s2;
    int a[1001];
    cin >> n >> m;
    for (int i = 0; i < n; i++)s1.push(n - i - 1);
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++) {
        while (!s1.empty()&&s1.top() < a[i]) { 
            s2.push(s1.top());
            s1.pop();
        }
        if (s2.size() > m) {
            cout << "NO";
            return 0;
        }
        if (!s1.empty()&&s1.top() == a[i]) {
            s1.pop();
        }
        else if (!s2.empty()&&s2.front() == a[i]) {
            s2.pop();
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
 
    //system("pause");
    return 0;
}
/*
10 3
1 2 0 4 5 7 3 9 8 6
 
 
*/