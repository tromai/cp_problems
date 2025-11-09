#include <bits/stdc++.h>
#include <vector>

using namespace std;

int get_mex(const vector<int> &vi) {
    set<int> si;
    for (int x : vi) {
        si.emplace(x);
    }

    int mex = 0;
    while (si.find(mex) != si.end()) {
        mex ++;
    }

    return mex;
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

        cout << get_mex(vi) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}