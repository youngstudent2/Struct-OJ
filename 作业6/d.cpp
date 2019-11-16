#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct BadGuys {
	int g1, g2;
	int val;
	friend istream& operator >>(istream& in, BadGuys& bg) {
		in >> bg.g1 >> bg.g2 >> bg.val;
		bg.g1--; bg.g2--;
		return in;
	}
	friend ostream& operator <<(ostream& out, const BadGuys& bg) {
		out << bg.g1 << ' ' << bg.g2 << ' ' << bg.val;
		return out;
	}
	bool operator <(const BadGuys& bg) {
		return val < bg.val;
	}
};
struct element {
	int father;
	int relation;
	//relation x.rel-y.rel: 0-same 1-bad_relation
};
class Union {
private:
	element *eles;
	void update_relation(int &r, int &fr) {
		r = (r + fr) % 2;
	}
public:
	Union(int n) {
		eles = new element[n];
		for (int i = 0; i < n; i++) {
			eles[i].father = i;
			eles[i].relation = 0;
		}
	}
	int find(int x) {
		int fx = eles[x].father;
		if (x != fx) {
			eles[x].father = find(fx);
			update_relation(eles[x].relation, eles[fx].relation);
		}

		return eles[x].father;
	}
	void unionSet(int x, int y) {
		int rx = find(x);
		int ry = find(y);
		eles[ry].father = rx;
		eles[ry].relation = (2 - eles[y].relation + eles[x].relation + 1) % 2;
	}
	bool inUnion(int x, int y) {
		return find(x) == find(y);
	}
	bool inSet(int x, int y) {
		return eles[x].relation == eles[y].relation;
	}
};

int check(Union& u, vector<BadGuys>& bgs) {
	for (auto& bg : bgs) {
		int &x = bg.g1, &y = bg.g2;
		if (u.inUnion(x, y)) {
			if (u.inSet(x, y)) {
				return bg.val;
			}
		}
		else {
			u.unionSet(x, y);
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<BadGuys> badguys(m);

	for (auto& bg : badguys)
		cin >> bg;
	//按val下降排序
	sort(badguys.begin(), badguys.end(),
		[](const BadGuys& a, const BadGuys& b)->bool {return a.val > b.val; }
	);

	//通过种类并查集逐条检验，找到无法分组（即由于先前的分组导致他们已经被分到了在同一组）的一对，则这一对就是最大的坏蛋
	Union u(n);
	cout << check(u, badguys) << endl;

	/*
	for (auto& bg : badguys)
		cout << bg << endl;
	*/
	//system("pause");
	return 0;
}
/*
2 1
1 2 20
*/