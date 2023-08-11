/**
 * Code by longtqtqn
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int &x : prices) {
        cin >> x;
    }

    int64_t curMax = prices[n - 1];
    int64_t rs = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (prices[i] < curMax) {
            rs += curMax - prices[i];
        } else {
            curMax = prices[i];
        }
    }

    cout << rs << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

}