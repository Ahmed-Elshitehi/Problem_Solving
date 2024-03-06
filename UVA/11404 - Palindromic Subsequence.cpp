#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int n, DP[N][N];
string DP2[N][N];
string s;
int cal(int i, int j) {
    if (i > j) return 0;
    if (i == j) return 0;
    int &ret = DP[i][j];
    if (~ret) return ret;
    if (s[i] == s[j]) {
        ret = cal(i + 1, j - 1);
    } else {
        ret = 1 + min(cal(i + 1, j),
                      cal(i, j - 1));
    }
    return ret;
}
string build(int i, int j) {
    if (i > j) return "";
    string &t = DP2[i][j];
    if (DP2[i][j] != "-1")
        return t;
    t = "";
    if (i == j) {
        t += s[i];
        return t;
    }
    if (s[i] == s[j]) {
        t = s[i] + build(i + 1, j - 1) + s[j];
    } else {
        int optimal = cal(i, j);
        if (cal(i + 1, j) == cal(i, j - 1)) {
            t = min(build(i + 1, j),
                    build(i, j - 1));
        } else if (optimal == 1 + cal(i + 1, j)) {
            t = build(i + 1, j);
        } else {
            t = build(i, j - 1);
        }
    }
    return t;
}
signed main() {
    while (cin >> s) {
        n = (int) s.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                DP[i][j] = -1;
                DP2[i][j] = "-1";
            }
        }
        cout << build(0, n - 1) << '\n';
    }
}