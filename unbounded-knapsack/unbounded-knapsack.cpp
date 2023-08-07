/**
 * Code by longtqtqn
 */
#include <bits/stdc++.h>

using namespace std;

int a[2002];
int n, k;
void solve() {
    cin >> n >> k;
    vector<bool> dp(k + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= k) {
            dp[a[i]] = true;
        }
    }

    dp[0] = true;
    for (int i = 0; i < k; ++i) {
        if(dp[i]) {
            for (int j = 0; j < n; ++j) {
                if (i + a[j] <= k) {
                    dp[i + a[j]] = true;
                }
            }
        }
    }

    while (k >= 0) {
        if (dp[k]) {
            cout << k << "\n";
            return;
        }
        --k;
    }
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
}