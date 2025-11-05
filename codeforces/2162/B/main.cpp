#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> remove_eles(const vector<int> &vi) {
    vector<int> res;

    for (int i = 0; i < int(vi.size()); i++) {
        if (vi[i] == 0) {
            res.emplace_back(i);
        }
    }

    return res;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;

        string s;
        cin >> s;

        vector<int> vi;
        for (char c : s) {
            vi.push_back(c - '0');
        }

        vector<int> res = remove_eles(vi);
        cout << res.size() << "\n";
        for (int k = 0; k < int(res.size()); k ++) {
            // This problem use 1-based indices.
            cout << res[k] + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}