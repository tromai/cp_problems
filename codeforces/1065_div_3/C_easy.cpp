#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> m(n);
        for (int i = 0; i < n; i++) {
            cin >> m[i];
        }

        int last_differ_index = -1;
        // XOR identity is 0.
        // 0 ^ 1 = 1
        // 0 ^ 0 = 0
        int total_xor = 0;

        for (int i = 0; i < n; i++) {
            total_xor = total_xor ^ a[i] ^ m[i];

            if (a[i] != m[i]) {
                last_differ_index = i;
            }
        }

        if (total_xor == 0) {
            // XOR is associative and commulative.
            // If XOR of all elements is 0 -> meaning if XOR of all a[i] == XOR of all m[i]
            // And because XOR is associative and commulative, we can freely pick n element from either a or m, the 
            // result would be the same. This means that there is no way Ajisa or Mai can win.
            cout << "Tie" << endl;
        } else {
            // Turn is 1-based index
            if ((last_differ_index + 1) % 2 != 0) {
                cout << "Ajisai" << endl;
            } else {
                cout << "Mai" << endl;
            }
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}