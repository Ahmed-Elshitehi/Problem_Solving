//بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;
void Ma3rof();
class DisjointSet{ // zero index
private:
    vector<int> parent, size;
public:
    DisjointSet(int n) {
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
    int size_of(int i){
        return size[findParent(i)];
    }
};
void AC() {
    int n;
    cin >> n;
    map<string, int> id;
    DisjointSet ds(n * 3);
    for (int i = 0; i < n; ++i) {
        string s, t;
        cin >> s >> t;
        if (!id[s]) {
            id[s] = id.size() + 1;
        }
        if (!id[t]) {
            id[t] = id.size() + 1;
        }
        ds.unionBySize(id[s], id[t]);
        cout << ds.size_of(id[s]) << '\n';
    }
    for (int i = 0; i < n; ++i) {

    }
}
signed main(){
    Ma3rof();
    int Test_Cases = 1;
    cin >> Test_Cases;
    for (int i = 1; i <= Test_Cases; ++i) {
        AC();
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