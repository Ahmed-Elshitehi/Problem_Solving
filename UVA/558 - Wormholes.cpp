//بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;
void Ma3rof();
void AC() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
    }
    vector<int> dis(n, 1e10);
    dis[0] = 0;
    for (int k = 0; k < n - 1; ++k) {
        for (int i = 0; i < n; ++i) {
            for (auto j: graph[i]) {
                int u = i;
                int v = j.first;
                int w = j.second;
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto j: graph[i]) {
            int u = i;
            int v = j.first;
            int w = j.second;
            if (dis[u] + w < dis[v]) {
                cout << "possible\n";
                return;
            }
        }
    }
    cout << "not possible\n";
}
signed main(){
    Ma3rof();
    int Test_Cases = 1;
    cin >> Test_Cases;
    while (Test_Cases--) {
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