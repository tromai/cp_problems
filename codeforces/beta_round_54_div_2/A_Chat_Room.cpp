#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    string s;

    cin >> s;

    string target = "hello";
    int curr = 0;

    for (char c : s) {
        if (c == target[curr]) {
            curr += 1;
            if (curr == 5) {
                cout << "YES";
                return;
            }
        }
    }

    cout << "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}