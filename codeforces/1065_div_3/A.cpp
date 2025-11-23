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

        if (n % 2 != 0 || n < 2) {
            cout << 0 << endl;
        } else {
            long long count = 0;
            for (int x = 0; x < n / 4 + 1; x ++) {
                for (int y = 0; y < n / 2 + 1; y ++) {
                    // cout << x << " -- " << y << endl;
                    if (4 * x + 2 * y == n) {
                        count++;
                    }
                }
            }
            cout << count << endl;
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}