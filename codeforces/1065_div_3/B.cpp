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

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        };

        if (v[0] != - 1 && v[n - 1] != -1) {
            cout << abs(v[n-1] - v[0]) << endl;
            for (int i = 0; i < n; i++) {
                if (v[i] == -1) {
                    cout << 0 << " ";
                } else {
                    cout << v[i] << " ";
                }
            };
            cout << endl;
        } else if (v[0] == -1 && v[n - 1] != -1) {
            cout << 0 << endl;
            cout << v[n - 1] << " ";
            for (int i = 1; i < n; i++) {
                if (v[i] == -1) {
                    cout << 0 << " ";
                } else {
                    cout << v[i] << " ";
                }
            };
            cout << endl;
        } else if (v[0] != -1 && v[n - 1] == -1) {
            cout << 0 << endl;
            for (int i = 0; i < n - 1; i++) {
                if (v[i] == -1) {
                    cout << 0 << " ";
                } else {
                    cout << v[i] << " ";
                }
            };
            cout << v[0] << " ";
            cout << endl;
        } else if (v[0] == -1 && v[n - 1] == -1) {
            cout << 0 << endl;
            for (int i = 0; i < n; i++) {
                if (v[i] == -1) {
                    cout << 0 << " ";
                } else {
                    cout << v[i] << " ";
                }
            };
            cout << endl;
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}