#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int s, n;
    cin >> s >> n;

    map<int, int> ds;
    for (int i = 0; i < n; i++) {
        int strength, bonus;
        cin >> strength >> bonus;
        // If we use [] operator, the default value for int is 0 inserted.
        ds[strength] += bonus;
    }

    // Map is already sorted according to keys.
    for (map<int, int>::iterator it = ds.begin(); it != ds.end(); ++it) {
        if (s > it->first) {
            s += it -> second;
        } else {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}