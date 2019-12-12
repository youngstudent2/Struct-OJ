#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int k;//记录当前结点编号 
	struct node *next;
}*v;
int ans = 0; int *ru;
int cmp(const void *a,const void *b){
    return *(int*)b-*(int*)a;
}
void topsort(int n)
{
	int i;
	struct node *p;
	int *stack = (int*)malloc(sizeof(int)*n), top = -1;
	for (i = n-1; i >= 0; i--)
		if (ru[i] == 0)stack[++top] = i;//入度为0的点入栈 

	while (top > -1)                  //栈非空时循环 
	{
		p = &v[stack[top--]];        //取出栈顶元素 
		printf("%d ", stack[top + 1]);
        int count = 0;
		while (p->next != NULL)       //枚举该点所有后继 
		{
			p = p->next;
            
			if (--ru[p->k] == 0){      //若去除一条边后入度为0则入栈 
				stack[++top] = p->k;
                ++count;
            }
            qsort(stack+top-count+1,count,sizeof(int),cmp);
		}
	}
}
int main()
{
	int n, m;
	struct node *p, *pp;
	int i, a, b;
	scanf("%d%d", &n, &m);
	ru = (int*)malloc(sizeof(int)*n);
	v = (struct node*)malloc(sizeof(struct node)*n);
	for (i = 0; i < n; i++)     //初始化：将所有点的入度置0，指针置空 
	{
		ru[i] = 0;
		v[i].next = NULL;
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		ru[b]++;
		p = &v[a];
		while (p->next != NULL)p = p->next;//找到与a点直接相连的最后一个点 
		pp = (struct node*)malloc(sizeof(struct node));    //开辟一个新的表 
		pp->next = NULL;
		pp->k = b;                      //该表对应的结点编号为b 
		p->next = pp;

	}

	topsort(n);
	//system("pause");
	//printf("\nans=%d",ans);	
	return 0;
}
/*

5 6
1 2
3 1
1 0
4 1
4 0
3 0

5 6
0 1
0 2
3 1
3 2
2 4
1 4
*/