//بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;
class DisjointSet{ // zero index
private:
    vector<int> parent, size;
public:
    DisjointSet(int n = 2e5 + 7) {
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
    int get_max_size(){ // look here
        return *max_element(size.begin(), size.end());
    }
};
signed main(){
    int Test_Cases = 1;
    cin >> Test_Cases;
    for (int T = 1; T <= Test_Cases; ++T) {
        int n, m;
        cin >> n >> m;
        DisjointSet ds(n + 1);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            ds.unionBySize(a, b);
        }
        cout << ds.get_max_size() << '\n'; // take a look at the implementation
    }
}