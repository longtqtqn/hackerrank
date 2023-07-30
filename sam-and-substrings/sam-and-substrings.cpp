/**
 * Code by longtqtqn
 */
#include <bits/stdc++.h>

using namespace std;
const int mmod = 1e9 + 7;
int64_t dp[200005];

int main() {
    string s;
    cin >> s;
    
    int64_t rs = 0;
    s = " " + s;
    for (int i = 1; i < s.size(); ++i) {
        dp[i] =(dp[i - 1] * 10 % mmod + i * (s[i] - '0') % mmod);
        rs = (rs + dp[i]) % mmod;
    }

    cout << rs;
}