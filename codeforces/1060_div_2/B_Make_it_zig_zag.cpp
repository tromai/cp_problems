#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

int get_operation_count(vector<int> &vi) {
    int size = int(vi.size());

    // Find the prefix max for all indices.
    vector<int> pre(size);
    pre[0] = vi[0];
    for (int i = 1; i < size; i++) {
        pre[i] = max(pre[i - 1], vi[i]);
    }

    int res = 0;

    // Note that the question uses 1-based index.
    // We are going through all "odd" indices here.
    // The intuition is as, the number of operation 1 for each
    // odd index is max(0, vi[i] - min(pre[i - 1], pre[i + 1]))
    // You need to handle the first and last element separately too.
    for (int i = 0; i < size; i += 2) {
        int diff;

        if (i == 0) {
            diff = vi[i] - pre[i + 1];
        } else if (i == size - 1) {
            diff = vi[i] - pre[i - 1];
        } else {
            diff = vi[i] - min(pre[i + 1], pre[i - 1]);
        }

        if (diff >= 0) {
            res += diff + 1;
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

        vector<int> vi(len);
        for (int k = 0; k < len; k++) {
            cin >> vi[k];
        }

        cout << get_operation_count(vi) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}