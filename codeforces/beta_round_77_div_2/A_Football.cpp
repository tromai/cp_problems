#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    string s;

    cin >> s;

    char last = 'A';
    int count = 0;
    for (char c : s) {
        if (c == last) {
            count ++;
            if (count == 7) {
                cout << "YES";
                return;
            }
        } else {
            last = c;
            count = 1;
        }
    }
    cout << "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}