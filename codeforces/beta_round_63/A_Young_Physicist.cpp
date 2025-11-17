#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int x = 0, y = 0, z = 0;

    for (int i = 0; i < n; i++) {
        int t_x, t_y, t_z;
        cin >> t_x >> t_y >> t_z;

        x += t_x;
        y += t_y;
        z += t_z;
    }

    if (x == 0 && y == 0 && z == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}