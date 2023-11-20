#include <bits/stdc++.h>
using namespace std;
void Ma3rof();
class DisjointSet{ // zero index
private:
    vector<int> parent, rank, size;
public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }else if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] > size[ulp_v]) {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        } else {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
    }
};
signed main(){
    Ma3rof();
    int n, m;
    int T = 1;
    while (cin >> n >> m) {
        if (!n && !m) break;
        DisjointSet ds(n + 1);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            ds.unionBySize(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += (i == ds.findParent(i));
        }
        cout << "Case " << T++ << ": " << ans << '\n';
    }
}
void Ma3rof() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*
     * Ahmed ma3rof
*/