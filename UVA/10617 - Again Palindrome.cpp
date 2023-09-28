//بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 150;
int DP[N][N];
string s;
int cal(int i, int j) {
    if (i == j) {
        return 1;
    }
    if (i + 1 == j) {
        return 2 + (s[i] == s[j]);
    }
    int &ret = DP[i][j];
    if (~ret) {
        return ret;
    }
    ret = 0;
    if (s[i] == s[j]) {
        ret += cal(i + 1, j - 1) + 1;
    }
    ret += cal(i + 1, j);
    ret += cal(i, j - 1);
    ret -= cal(i + 1, j - 1);
    return ret;
}
void Ma3rof();
signed main(){
    Ma3rof();
    int Test = 1;
    cin >> Test;
    while (Test--) {
        cin >> s;
        memset(DP, -1, sizeof DP);
        cout << cal(0, (int) s.size() - 1) << '\n';
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
