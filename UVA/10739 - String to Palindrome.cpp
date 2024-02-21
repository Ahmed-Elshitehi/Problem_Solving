//بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;
void IO();
string s;
int DP[1000][1000];
int cal(int i, int j){
    if (i >= j) return 0;
    int &ret = DP[i][j];
    if (~ret) return ret;
    ret = cal(i + 1, j - 1) + (s[i] != s[j]);
    ret = min(ret, cal(i + 1, j) + 1);
    ret = min(ret, cal(i, j - 1) + 1);
    return ret;
}
signed main() {
    IO();
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> s;
        memset(DP, -1, sizeof DP);
        cout << "Case " << i << ": " << cal(0, s.size() - 1) << '\n';
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