#include <bits/stdc++.h>

using namespace std;

void M3rof();

#define int long long
int n, T, V;
signed main(){
    M3rof();
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> V >> T;
        int cost = 1e18;
        cout << "Case " << i << ": ";
        for (int j = 0; j < (1LL << n); ++j) {
            bitset<21> b(j);
            int cost_p = 0, gane = 0;
            for (int k = 0; k < n; ++k) {
                if (b[k]) {
                    gane += a[k].first;
                    cost_p += a[k].second;
                }
            }
            gane *= T;
            if (gane >= V) {
                cost = min(cost, cost_p);
            }
        }
        if (cost == 1e18) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << cost << '\n';
        }
    }
}
void M3rof() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
}
/*
        M3rof
*/