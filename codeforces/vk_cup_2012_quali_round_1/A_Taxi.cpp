#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int count;
    cin >> count;

    std::map<int, int> counter = {
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
    };

    for (int i = 0; i < count; i++) {
        int num;
        cin >> num;
        counter[num] = counter[num] + 1;
    }

    int res = counter[4];

    // Fit cars with 3-member group + 1 member group.
    res += counter[3];
    counter[1] = max(counter[1] - counter[3], 0);

    // Fit cars with 2 2-member groups.
    res += counter[2] / 2;

    counter[2] = counter[2] % 2;
    // Fit car with 2-member group and 2 * 1-member group.
    res += counter[2];
    counter[1] = max(counter[1] - counter[2] * 2, 0);

    // Fit remaining 1 member groups.
    res += (counter[1] + 4 - 1) / 4;

    cout << res;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}