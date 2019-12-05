#include<iostream>
using namespace std;
#define maxn 200
bool visited[51];
int nums[51];
int c;
int num_fetch(char* s, int v) {
	if (*s == 0) return -1;
	if (v == 2 && *(s + 1) == 0)return -1;
	if (v == 1) {
		return *s - '0';
	}
	if (v == 2) {
		int val = *s - '0';
		val = val * 10 + *(s + 1) - '0';
		if (val > 50)return -1;
		return val;
	}
	return -1;
}
bool test() {
	int i = 0;
	int n = c;
	while (!visited[i])++i;
	while (n > 0) {
		if (!visited[i++])return false;
		--n;
	}
	return true;
}
void dfs(char *s) {
	if (*s == 0) {
		if (!test())return;
		for (int i = 0; i < c; i++) {
			cout << nums[i] << ' ';
		}
		//cout << endl;
		return;
	}
	int val;
	if ((val = num_fetch(s, 1)) != -1 && !visited[val]) {
		nums[c++] = val;
		visited[val] = true;
		dfs(s + 1);
		c--;
		visited[val] = false;
	}
	if ((val = num_fetch(s, 2)) != -1 && !visited[val]) {
		nums[c++] = val;
		visited[val] = true;
		dfs(s + 2);
		c--;
		visited[val] = false;
	}
	return;
}



int main()
{
	for (int i = 0; i <= 50; i++)visited[i] = false;
	c = 0;
	char s[maxn];
	cin >> s;
	dfs(s);
	//system("pause");
	return 0;
}
/*
111221496710358
*/