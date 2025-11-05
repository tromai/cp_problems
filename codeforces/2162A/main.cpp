#include <bits/stdc++.h>
#include <vector>

using namespace std;

int max_average(vector<int>& vi) {
    sort(vi.begin(), vi.end());
    return vi.back();
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;

        vector<int> vi(len);
        for (int k = 0; k < len; k++) {
            cin >> vi[k];
        }

        int max_avg = max_average(vi);
        cout << max_avg << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}