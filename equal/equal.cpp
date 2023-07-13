/**
 * Code by longtqtqn
 */
#include <bits/stdc++.h>
using namespace std;
int dp[1012][1013];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i <= 1002; ++i) {
        for (int j = 0; j <= 1002; ++j) {
            dp[i][j] = 1e9;
        }
    }
    for (int i = 0; i <= 1004; ++i) {
        dp[i][1003] = 0;
        dp[i][1004] = 0;
    }
    for (int j = 0; j <= 1004; ++j) {
        dp[1003][j] = 0;
    }
    set<int> setj;
    for (int j = 0; j < n; ++j) {
        int a;
        cin >> a;
        a += 2;
        ++dp[a][1004];
        ++dp[1003][a];
        dp[a][a] = 0;
        setj.insert(a);
    }
    for (const int &j : setj) {
        queue<int> q;
        q.push(j);
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            int a = dp[i][j];
            if (i - 1 >= 0 && a + 1 < dp[i - 1][j]) {
                dp[i - 1][j] = a + 1;
                dp[i - 1][1003] += (a + 1) * dp[1003][j];
                dp[i - 1][1004] += dp[1003][j];
                q.push(i - 1);
            }
            if (i - 2 >= 0 && a + 1 < dp[i - 2][j]) {
                dp[i - 2][j] = a + 1;
                dp[i - 2][1003] += (a + 1) * dp[1003][j];
                dp[i - 2][1004] += dp[1003][j];
                q.push(i - 2);
            }
            if (i - 5 >= 0 && a + 1 < dp[i - 5][j]) {
                dp[i - 5][j] = a + 1;
                dp[i - 5][1003] += (a + 1) * dp[1003][j];
                dp[i - 5][1004] += dp[1003][j];
                q.push(i - 5);
            }
        }
    }

    int rs = INT_MAX;
    for (int i = 0; i < 1002; ++i) {
        if (dp[i][1004] == n) {
            rs = min(rs, dp[i][1003]);
        }
    }
    cout << rs <<"\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
