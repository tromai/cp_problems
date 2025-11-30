#include <bits/stdc++.h>
#include <cmath>

using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, yellow, red;
        cin >> n >> yellow >> red;

        int max_possible = min(n, red + yellow / 2);
        cout << max_possible << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
