/**
 * Code by longtqtqn
 */
#include <bits/stdc++.h>

using namespace std;

int n;
int b[100005];
int dp[2][100005];
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    dp[0][0] = 0;
    dp[1][0] = 0;

    for (int i = 1; i < n; ++i) {
        dp[0][i] = max(abs(b[i] - b[i - 1]) + dp[0][i - 1], (b[i] - 1) + dp[1][i - 1]);
        dp[1][i] = b[i - 1] - 1 + dp[0][i - 1];
    }

    cout << max(dp[0][n - 1], dp[1][n - 1]) <<"\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}