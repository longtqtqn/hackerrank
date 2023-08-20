/**
 * Code by longtqtqn
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> arr;
    cin >> n;
    arr.resize(n);

    for (int &x : arr) {
        cin >> x;
    }

    vector<int> F (n, INT_MAX);
    int rs = 0;
    F[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        auto it = lower_bound(F.begin(), F.end(), arr[i]);
        rs = max(rs, (int)(it - F.begin() + 1));
        *it = arr[i];
    }

    cout << rs;
}
