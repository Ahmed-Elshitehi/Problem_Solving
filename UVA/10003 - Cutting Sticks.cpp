#include <bits/stdc++.h>
using namespace std;
void IO();
int DP[1001][1001];
int l, n;
vector<int> a;
// DP[i][j] --> minimum cost if we have Stick in range i, j
int cal(int i, int j) {
    int &ret = DP[i][j];
    if (~ret) return ret;
    ret = 1e9;
    int k = lower_bound(a.begin(), a.end(), i) - a.begin();
    for (; k < n && a[k] < j; ++k) {
        ret = min(ret, cal(i, a[k]) + cal(a[k] + 1, j) + j - i + 1);
    }
    if (ret == 1e9) ret = 0;
    return ret;
}
signed main() {
    IO();
    while (true) {
        cin >> l;
        if (!l) break;
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        a.push_back(l);
        memset(DP, -1, sizeof DP);
        cal(1, l);
        cout << "The minimum cutting is " << cal(1, l) << ".\n";
    }
}
void IO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
}