#include<iostream>
#include<vector>
using namespace std;
 
vector<int> find(int n, vector< vector<int> >& edges) {
    auto leaves = vector<int>();
    if (n == 1) {
        leaves.emplace_back(0);
        return leaves;
    }
    // first: number of neighbors. second: sum of all neighbors.
    auto path = vector< pair<size_t, size_t> >(n);
    for (auto& e : edges) {
        const int f = e.front();
        const int b = e.back();
        path[f].first++;
        path[f].second += b;
        path[b].first++;
        path[b].second += f;
    }
    // find all leaves which only have one neighbor
    for (auto i = 0; i < path.size(); ++i) {
        if (path[i].first == 1)
            leaves.emplace_back(i);
    }
    auto new_end = leaves.end();
    // The MHT only have 2 cases. One node, or two nodes share the same edge.
    while (n > 2) {
        auto oit = leaves.begin();  // output iterator, rewrite leaves from begining.
        for (auto b = leaves.begin(); b < new_end; ++b, --n) {
            // since the leaf have only one neighbor, the sum is the neighbor's node id
            const int dest = path[*b].second;
            path[dest].second -= *b;
            if (--path[dest].first == 1)
                * oit++ = dest; // add next leaf
        }
        new_end = oit;  // new tail
    }
    
    leaves.erase(new_end, leaves.end());    // erase unnecessary spaces
    return leaves;
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        return 0;
    }
    vector< vector<int> > edges;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        edges.push_back(vector<int>({x,y}));
    }
    vector<int> res = find(n, edges);
    if (res.size() == 1) {
        cout << res[0];
        /*
        if (res[0] == 0) {
            cout << endl << n << m << endl;
            for (auto& e : edges) {
                cout << e[0] << ' ' << e[1] << endl;
            }
        }*/
    }
    else if (res.size() == 2) {
        if (res[0] < res[1])cout << res[0] << ' ' << res[1];
        else cout << res[1] << ' ' << res[0];
    }
    //system("pause");
    return 0;
}
/*
10 3
1 0
1 2
1 3
 
10 0
*/