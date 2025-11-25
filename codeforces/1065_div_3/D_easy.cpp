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

        // Intuition: 
        // If the maximum of a suffix of the array is the length of that suffix.
        // This mean that suffix contains element from 1 -> Max and the suffix
        // will contain elemetns from Max + 1 -> N. This mean that every elements in the 
        // suffix cannot connect to the prefix, meaning that there will be at least 2 different
        // connected components.
        // References: https://youtu.be/IWGqL9LOOhU?t=3922
        int max_suffix = -1;
        bool has_disconnected_comps = false;
        for (int i = n - 1; i > 0; i--) {
            max_suffix = max(max_suffix, a[i]);
            if (max_suffix == (n - i)) {
                has_disconnected_comps = true;
                break;
            }
        }

        if (has_disconnected_comps == true) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }

    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}