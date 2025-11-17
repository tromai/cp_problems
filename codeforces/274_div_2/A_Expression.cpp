#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int a,b,c;
    cin >> a >> b >> c;

    vector<int> list = {
        a + b + c,
        a + b * c,
        (a + b) * c,
        a * b + c,
        a * (b + c),
        a * b * c,
    };

    int res = *max_element(list.begin(), list.end());

    cout << res;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}