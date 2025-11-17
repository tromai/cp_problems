#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

// Input is 1 <= x <= 1000;
const set<int> lucky = {
    4,
    7,
    44,
    47,
    74,
    77,
    444,
    777,
    474,
    477,
    744,
    774,
    747,
    447,
};

void solve() {
    int input;
    cin >> input;

    for (int luck : lucky) {
        if (input % luck == 0) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}