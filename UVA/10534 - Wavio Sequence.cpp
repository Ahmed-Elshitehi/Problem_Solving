#include <bits/stdc++.h>
using namespace std;
void M3rof();
signed main(){
    M3rof();
    int n;
    while (cin >> n && n) {
        vector<int> a(n + 1), LIS(n + 1, 1), LDS(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<int> temp;
        temp.push_back(a[1]);
        for (int i = 2; i <= n; i++) {
            auto it = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            if (it == temp.size())
                temp.push_back(a[i]);
            else {
                temp[it] = a[i];
            }
            LIS[i] = it + 1;
        }
        temp.clear();
        temp.push_back(a[n]);
        for (int i = n-1; i >= 1; i--) {
            auto it = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            if(it==temp.size())
                temp.push_back(a[i]);
            else{
                temp[it] = a[i];
            }
            LDS[i] = it + 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int l = min(LIS[i], LDS[i]) * 2 - 1;
            if (l & 1)
                ans = max(ans, l);
        }
        cout << ans << endl;
    }
    return 0;
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