#include <bits/stdc++.h>
#include <vector>

using namespace std;

/**
 * Intuition: we only need to protect a 1 if there is at least k-1 0s infront of
 * it, or the last 1 is k index before it.
 * We should only protect the first 1.
 */
int get_protected(string s, int k) {
    int res = 0;
    int last_1_index = -1;

    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == '1') {
            if (last_1_index == -1) {
                // First 1
                res++;
            } else if (i - last_1_index >= k) {
                res++;
            }
            last_1_index = i;
        }
    }

    return res;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int len, k;
        cin >> len;
        cin >> k;

        string s;
        cin >> s;

        cout << get_protected(s, k) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}