#include <bits/stdc++.h>
using namespace std;
void Ma3rof();
string s, t;
int n, m;
const int N = 101;
int DP[N][N];
int cal(int i = 0, int j = 0) {
    if (i >= n || j >= m) {
        return 0;
    }
    int &ret = DP[i][j];
    if (~ret) {
        return ret;
    }
    if (s[i] == t[j]) {
        ret = cal(i + 1, j + 1) + 1;
    } else {
        ret = max(cal(i + 1, j), cal(i, j + 1));
    }
    return ret;
}
signed main() {
    Ma3rof();
    int Test = 1;
    while (true) {
        getline(cin, s);
        if (s == "#") {
            break;
        }
        getline(cin, t);
        memset(DP, -1, sizeof DP);
        n = (int) s.size();
        m = (int) t.size();
        cout << "Case #" << Test << ": " << "you can visit at most ";
        cout << cal(0, 0) << " cities.\n";
        Test++;
    }
}
void Ma3rof() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*
     * Ahmed Ma3rof
*/