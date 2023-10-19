#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void dfs(int node, vector<vector<int>> &graph, vector<bool> &vis) {
    vis[node] = true;
    for (int child: graph[node]) {
        if (!vis[child])
            dfs(child, graph, vis);
    }
    ans.push_back(node);
}
signed main(){
    int n, m;
    while (cin >> n >> m) {
        if (!n && !m) break;
        ans.clear();
        vector<vector<int>> graph(n + 1);
        vector<bool> vis(n + 1);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                dfs(i, graph, vis);
            }
        }
        std::reverse(ans.begin(), ans.end());
        for (int &i: ans) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}