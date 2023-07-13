/**
 * Code by longtqtqn
 */
#include <bits/stdc++.h>
using namespace std;

bool f[1004][1004];

void solve() {
    string a, b;
    cin >> a >> b;

    int sa = a.size();
    int sb = b.size();

    for (int j = 0; j < sb; ++j) {
        for (int i = 0; i < sa; ++i) {
            f[j][i] = false;
        }
    }

    for (int i = 0; i < sa; ++i) {
        if (isupper(a[i])) {
            if (a[i] != b[0]) {
                break;
            }
            f[0][i] = true;
        }
        if ((i > 0 && f[0][i - 1]) || toupper(a[i]) == b[0]) {
            f[0][i] = true;
        }
    }

    for (int j = 1; j < sb; ++j) {
        for (int i = j; i < sa; ++i) {
            if (islower(a[i])) {
                if (f[j][i - 1] || f[j - 1][i - 1] && toupper(a[i]) == b[j]) {
                    f[j][i] = true;
                }
            } else {
                if (a[i] == b[j] && f[j - 1][i - 1]) {
                    f[j][i] = true;
                }
            }
        }
    }

    if (f[sb - 1][sa - 1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }


}
