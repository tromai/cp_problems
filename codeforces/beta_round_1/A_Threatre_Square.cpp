#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    long long n, m, a;
    cin >> n >> m >> a;

    // because res can be n * m, which can get up to 10^18.
    long long res;

    long long x = (n + a - 1) / a;
    long long y = (m + a - 1) / a;

    res = x * y;
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}