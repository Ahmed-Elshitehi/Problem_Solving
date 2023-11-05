#include <bits/stdc++.h>
using namespace std;
void Ma3rof();
signed main(){
    Ma3rof();
    int TEST;
    cin >> TEST;
    for (int t = 0; t < TEST; ++t) {
        if (t) {
            cout << '\n';
        }
        string s;
        getline(cin, s);
        int n, m;
        cin >> n >> m;
        map<string, vector<pair<string, int>>> graph;
        for (int i = 0; i < m; ++i) {
            string a, b;
            int c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        map<string, bool> vis;
        priority_queue<pair<int, pair<string, string >>> q;
        q.push({0, {graph.begin()->first, "-1"}});
        int ans = 0;
        while (!q.empty()) {
            string node = q.top().second.first;
            string p = q.top().second.second;
            int w = -q.top().first;
            q.pop();
            if (vis[node]) continue;
            vis[node] = true;
            if (p != "-1") {
                ans += w;
            }
            for (auto [a, b]: graph[node]) {
                q.push({-b, {a, node}});
            }
        }
        cout << ans << '\n';
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