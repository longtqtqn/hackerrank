/**
 * Code by longtqtqn
 */
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define mmod ((int)1e9 + 7)
int n, k , x;
int dp[2][100005];

int32_t main() {
    cin >> n >> k >> x;

    if (x != 1) {
        dp[1][1] = 1;
        dp[0][1] = k - 2;
    } else {
        dp[0][1] = k - 1;
    }

    for (int i = 2; i < n - 1; ++i) {
        dp[0][i] = (dp[0][i - 1] * (k - 2) % mmod +  dp[1][i - 1] * (k - 1)) % mmod;
        dp[1][i] = dp[0][i - 1];
    }

    cout << dp[0][n - 2];
}