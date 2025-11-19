#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int length = s.size();
    string a(s);

    if (isupper(s[0])) {
        for (int i = 0; i < length; i++) {
            if (!isupper(s[i])) {
                cout << s;
                return;
            } else {
                a[i] = s[i] + 'a' - 'A';
            }
        }
    } else {
        a[0] = s[0] - ('a' - 'A');
        for (int i = 1; i < length; i++) {
            if (!isupper(s[i])) {
                cout << s;
                return;
            } else {
                a[i] = s[i] + 'a' - 'A';
            }
        }
    }

    cout << a;

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}