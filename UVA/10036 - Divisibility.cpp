//بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;
void Ma3rof();
int n, k;
vector<int> v;
int DP[10001][101];
int cal(int i, int r) {
    if (i == n) {
        return (r == 0);
    }
    int &ret = DP[i][r];
    if (~ret) {
        return ret;
    }
    ret = max(ret, cal(i + 1, (((r + (v[i] % k + k) % k)) + k) % k));
    ret = max(ret, cal(i + 1, (((r - (v[i] % k + k) % k)) + k) % k));
    return ret;
}
signed main(){
    Ma3rof();
    int t=1;
    cin >> t;
    while(t--){
        cin >> n >> k;
        v.resize(n);
        memset(DP, -1, sizeof DP);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        if (cal(1, (((v[0] % k) + k) % k))) {
            cout << "Divisible\n";
        } else {
            cout << "Not divisible\n";
        }
    }
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
