#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// https://codeforces.com/blog/entry/148782
// This is quite tricky to wrap my head around.
void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> m;
        for (int i = 0; i < n*2; i++) {
            int e;
            cin >> e;
            m[e] += 1;
        }

        int x = 0, y = 0, z = 0;
        for (int i = 1; i <= 2 * n; i ++) {
            if (m[i] == 0) {
                continue;
            }
            if (m[i] % 2 != 0) {
                x++;
            } else if (m[i] % 4 != 0) {
                y++;
            } else {
                z++;
            }
        }

        int res = x + 2*y + 2*z;
        if (x == 0 && z % 2 != 0) {
            res = res - 2;
        }
        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
