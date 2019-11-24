#include<iostream>
#include<set>
using namespace std;
struct node1 {
	int val;
	int time;
	node1(int a, int b) :time(a), val(b) {}
	bool operator <(const node1& n)const {
		return val < n.val;
	}
};
struct node2 {
	int val;
	int time;
	node2(int a, int b) :time(a), val(b) {}
	bool operator <(const node2& n)const {
		return val > n.val;
	}
};
int main()
{
	int n, tmp, time = 0;
	set<node1> set1;
	set<node2> set2;
	set<node1>::iterator pre1, suc1;
	set<node2>::iterator pre2, suc2;
	scanf("%d%d", &n, &tmp);
	set1.insert(node1(time, tmp));
	set2.insert(node2(time, tmp));
	++time;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &tmp);
		node1 tmpNode1(time, tmp);
		node2 tmpNode2(time, tmp);
		++time;
		pre1 = set1.lower_bound(tmpNode1);
		//suc1=set1.upper_bound(tmpNode1);
		pre2 = set2.lower_bound(tmpNode2);
		//suc2=set2.upper_bound(tmpNode2);
		if (pre1 == set1.end())printf("%d ", pre2->val);
		else if (pre2 == set2.end())printf("%d ", pre1->val);
		//cout << *pre1 << *pre2 << endl;
		
		else printf("%d ", pre1->time >= pre2->time ? pre1->val : pre2->val);
		set1.insert(tmpNode1);
		set2.insert(tmpNode2);
	}
	//system("pause");
	return 0;
}
/*
5
5 3 4 9 6
5
1252372126 320842920 1690857990 1211251133 1393487776

*/