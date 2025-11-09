#include <bits/stdc++.h>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int team_count;
        cin >> team_count;

        int result = (team_count - 1) * 2;

        cout << result << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}