//بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;
void Ma3rof();
int n,m;
int grid[200][200];
int DP[200][200];
bool can(int i,int j){
    return (0 < i && i <= n && 0 < j && j <= m && !grid[i][j]);
}
int calc(int i,int j){
    if (i == n && j == m) {
        return 1;
    }
    if (!can(i, j)) {
        return 0;
    }
    int &ret = DP[i][j];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    ret += calc(i + 1, j);
    ret += calc(i, j + 1);
    return ret;
}
signed main(){
    Ma3rof();
    int t=1;
    cin >> t;
    while(t--){
        string line;
        getline(cin, line);
        memset(DP, -1, sizeof DP);
        memset(grid, 0, sizeof grid);
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            string s;
            getline(cin, s);
            string temp = "0";
            for (char j : s) {
                if (j == ' ') {
                    int k = stoi(temp);
                    grid[x][k] = 1;
                    temp = "0";
                } else {
                    temp.push_back(j);
                }
            }
            if (!temp.empty()) {
                int k = stoi(temp);
                grid[x][k] = 1;
            }
        }
        cout << calc(1, 1) << '\n';
        if(t)cout << '\n';
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