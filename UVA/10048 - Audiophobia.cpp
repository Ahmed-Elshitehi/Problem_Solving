//بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mx = 1e16;
void min_self(int &a, int b) {
    a = min(a, b);
}
signed main(){
    Ma3rof();
    int t = 0;
    while (++t) {
        int c, s, q;
        cin >> c >> s >> q;
        if (!c && !s && !q) break;
        if (t != 1) {
            cout << "\n\n";
        }
        cout << "Case #" << t << '\n';
        vector<vector<int>> matrix(c, vector<int>(c, mx));
        for (int i = 0; i < c; ++i) {
            matrix[i][i] = 0;
        }
        for (int i = 0; i < s; ++i) {
            int c1, c2, d;
            cin >> c1 >> c2 >> d;
            c1--, c2--;
            min_self(matrix[c1][c2], d);
            min_self(matrix[c2][c1], d);
        }
        for (int k = 0; k < c; ++k) {
            for (int i = 0; i < c; ++i) {
                for (int j = 0; j < c; ++j) {
                    min_self(matrix[i][j], max(matrix[i][k], matrix[k][j]));
                }
            }
        }
        while (q--) {
            int c1, c2;
            cin >> c1 >> c2;
            c1--, c2--;
            if (matrix[c1][c2] >= mx) {
                cout << "no path";
            } else {
                cout << matrix[c1][c2];
            }
            if (q) {
                cout << '\n';
            }
        }
    }
}
/*
     * Ahmed ma3rof
*/