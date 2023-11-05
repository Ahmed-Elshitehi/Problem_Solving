#include <bits/stdc++.h>
using namespace std;
void Ma3rof();

void max_self(int &a, int b) {
    a = max(a, b);
}
void min_self(int &a, int b) {
    a = min(a, b);
}
signed main(){
    Ma3rof();
    int n, m;
    while (cin >> n >> m) {
        if (!n && !m) break;
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        vector<bool> vis(n);
        priority_queue<pair<int, pair<int, int>>> q;
        q.push({0, {1, -1}});
        int ans = 0;
        while (!q.empty()) {
            int node = q.top().second.first;
            int p = q.top().second.second;
            int w = -q.top().first;
            q.pop();
            if (vis[node]) continue;
            vis[node] = true;
            if (p != -1) {
                max_self(ans, w);
            }
            for (auto [a, b]: graph[node]) {
                q.push({-b, {a, node}});
            }
        }
        if (std::count(vis.begin(), vis.end(), true) != n) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << ans << '\n';
        }
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