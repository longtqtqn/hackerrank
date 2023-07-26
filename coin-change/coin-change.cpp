/**
 * Code by longtqtqn
 */
#include <bits/stdc++.h>

using namespace std;
#define int int64_t
int dp[51][251];
int n, m;

int32_t main() {

    cin >> n >> m;
    vector<int> c(m);
    for (int &i : c) {
        cin >> i;
        dp[i][i] = 1;
    }
    sort(c.begin(), c.end());

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < c.size(); ++j) {
            for (int jj = j; jj < c.size(); ++jj) {
                if (i + c[jj] <= n) {
                    dp[c[jj]][i + c[jj]] += dp[c[j]][i];
                }
            }

        }
    }

    int rs = 0;
    for (const int &x : c) {
        rs += dp[x][n];
    }

    cout << rs;
}
