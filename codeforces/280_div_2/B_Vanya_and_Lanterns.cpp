#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    long long l;
    cin >> n >> l;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    // The range needs to cover by both the first and last light.
    double max_space = max(v[0], l - v[n - 1]);

    // Loop up to n - 2 because if i == n - 1 we don't have the next element to calculate the distance.
    for (int i = 0; i < n - 1; i++) {
        max_space = max(
            max_space,
            // Divide the space between 2 lights so that the radius is minimal.
            (v[i + 1] - v[i]) * 1.0 / 2
        );
    }

    cout << setprecision(10) << max_space;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}