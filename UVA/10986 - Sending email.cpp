//بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;
void Ma3rof();
signed main(){
    Ma3rof();
    int Test = 1, c = 1;
    cin >> Test;
    while (Test--) {
        cout << "Case #" << c++ << ": ";
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        vector<int> dis(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dis[s] = 0;
        q.push({0, s});
        while (!q.empty()) {
            auto node = q.top();
            q.pop();
            int p = node.second;
            int w = node.first;
            for (auto ch: graph[p]) {
                if (dis[ch.first] > w + ch.second) {
                    dis[ch.first] = w + ch.second;
                    q.push({dis[ch.first], ch.first});
                }
            }
        }
        if (dis[t] < 1e9) {
            cout << dis[t] << '\n';
        } else {
            cout << "unreachable\n";
        }
    }
    return 0;
}
void Ma3rof() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*
     * Ahmed ma3rof
*/
