#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
struct node
{
	int k;//记录当前结点编号 
	struct node *next;
}*v;
int *ru;
char *coin;
int *topOrder;
int k=0;
inline int max(int a,int b){
	return a>b?a:b;
}

int topsort(int n)
{
	int i;
	struct node *p;
	int *stack = (int*)malloc(sizeof(int)*n), top = -1;
	for (i = n - 1; i >= 0; i--)
		if (ru[i] == 0)stack[++top] = i;//入度为0的点入栈 
	int c = 0;
	while (top > -1)                  //栈非空时循环 
	{
		++c;
		p = &v[stack[top--]];        //取出栈顶元素 
		topOrder[k++]=p->k;
		while (p->next != NULL)       //枚举该点所有后继 
		{
			p = p->next;
			if (--ru[p->k] == 0) {      //若去除一条边后入度为0则入栈 
				stack[++top] = p->k;
			}
		}
	}
	return c==n;
}



int main()
{
	int n, m;
	struct node *p, *pp;
	int i, a, b;
	scanf("%d%d", &n, &m);
	ru = (int*)malloc(sizeof(int)*n);
	v = (struct node*)malloc(sizeof(struct node)*n);
	topOrder = (int*)malloc(sizeof(int)*n);
	coin = new char[n];
	cin >> coin;
	for (int i = 0; i < n; i++)
		coin[i] -= 'a';
	for (i = 0; i < n; i++)     //初始化：将所有点的入度置0，指针置空 
	{
		ru[i] = 0;
		v[i].k = i;
		v[i].next = NULL;
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		--a; --b;
		ru[b]++;
		p = &v[a];
		while (p->next != NULL)p = p->next;
		pp = (struct node*)malloc(sizeof(struct node));
		pp->next = NULL;
		pp->k = b;
		p->next = pp;
	}

	if (!topsort(n)) {
		printf("-1");
		return 0;
	}

	int **f=(int**)malloc(sizeof(int*)*26);
	for(int i=0;i<26;i++){
		f[i]=new int[n];
		for(int j=0;j<n;j++)f[i][j]=0;
	}
	for(int i=0;i<n;i++)f[coin[i]][i]=1;
	for(int i=0;i<n;i++){
		p=v+topOrder[i];
		pp=p->next;
		while(pp){
			int c1=coin[pp->k];
			int c2=coin[p->k];
			if(c1==c2)
				f[c1][pp->k]=max(f[c1][pp->k],f[c1][p->k]+1);
			else{
				f[c1][pp->k]=max(f[c1][pp->k],f[c1][p->k]);
				f[c2][pp->k]=max(f[c2][pp->k],f[c2][p->k]+1);
			}
			
			pp=pp->next;
		}

	}
	int ans=0;
	for(int i=0;i<n;i++){
		const int tmp = f[coin[i]][i];
		if(tmp>ans)ans=tmp;
	}
/*
	for(int i=0;i<26;i++,cout<<endl)
		for(int j=0;j<n;j++)
			cout<<f[i][j]<<' ';
*/
	printf("%d",ans);

	return 0;
}
/*
6 6
aacabc
1 2
1 3
3 5
3 6
4 2
4 1

3 3
abc
1 2
2 3
3 1

5 6
bcaaa
1 3
1 2
1 4
2 3
3 5
4 2

8 10
bcaaabab
1 3
1 2
1 4
2 3
3 5
4 2
4 6
6 7
7 8
8 2
*/