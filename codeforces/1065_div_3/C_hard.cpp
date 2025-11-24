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

        // XOR identity is 0.
        // 0 ^ 1 = 1
        // 0 ^ 0 = 0
        int total_xor = 0;

        for (int i = 0; i < n; i++) {
            total_xor = total_xor ^ a[i] ^ m[i];
        }

        if (total_xor == 0) {
            // XOR is associative and commulative.
            // If XOR of all elements is 0 -> meaning if XOR of all a[i] == XOR of all m[i]
            // And because XOR is associative and commulative, we can freely pick n element from either a or m, the 
            // result would be the same. This means that there is no way Ajisa or Mai can win.
            cout << "Tie" << endl;
            continue;
        } 

        // If the total XOR is not 0. We care about the most significant 1 bit of the total XOR.
        // The one with the turn where the XOR has this significant bit 1 will be the winner.
        int bit_i = 0;
        for (int i = 0; i < 20; i++) {
            if (total_xor & (1 << i)) {
                bit_i = i;
            }
        }

        int index1 = 0;
        for (int i = 0; i < n; i++) {
            int curr_xor = a[i] ^ m[i];
            if (curr_xor & (1 << bit_i)) {
                // turn is 1-based index
                index1 = i + 1;
            }
        }

        if (index1 % 2 == 0) {
            cout << "Mai" << endl;
        } else {
            cout << "Ajisai" << endl;
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}