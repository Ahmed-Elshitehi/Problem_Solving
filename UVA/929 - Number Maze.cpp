//بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;
void Ma3rof();
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool can(int i, int j, int n, int m) {
    return (i < n && i >= 0 && j < m && j >= 0);
}
signed main(){
    Ma3rof();
    int Test = 1;
    cin >> Test;
    while (Test--) {
        int n, m;
        cin >> n >> m;
        int grid[n][m], dis[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                dis[i][j] = 1e9;
            }
        }
        set<pair<int, pair<int, int>>> q;
        q.insert({grid[0][0], {0, 0}});
        dis[0][0] = grid[0][0];
        while (!q.empty()) {
            auto node = q.begin();
            q.erase(q.begin());
            int x = node->second.first, y = node->second.second;
            int w = node->first;
            for (int i = 0; i < 4; ++i) {
                int a = x + dx[i], b = y + dy[i];
                if (can(a, b, n, m)) {
                    if (dis[a][b] > w + grid[a][b]) {
                        dis[a][b] = w + grid[a][b];
                        q.insert({dis[a][b], {a, b}});
                    }
                }
            }
        }
        cout << dis[n - 1][m - 1] << '\n';
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