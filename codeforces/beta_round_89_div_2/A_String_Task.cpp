#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

const set<char> vowels = {'A', 'O', 'Y', 'E', 'U', 'I', 'a', 'o', 'y', 'e', 'u', 'i'};

void solve() {
    string s;
    cin >> s;

    for (char c: s) {
        if (vowels.find(c) == vowels.end()) {
            cout << ".";
            if ('A' <= c && c <= 'Z') {
                char lower = c + ('a' - 'A');
                cout << lower;
            } else {
                cout << c;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}