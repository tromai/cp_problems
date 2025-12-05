#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int part1 = 0;
    int part2 = 0;
    int curr = 50;
    for (int i = 0; i < n; i++) {
        string ins;
        cin >> ins;

        string rotation = ins.substr(0, 1);
        string num_str = ins.substr(1, ins.size());

        int num;
        try {
            num = std::stoi(num_str);
        } catch (const std::exception& e) {
            cout << "OH NO!" << endl;
        }

        // Add wrap around and remain in the same place
        // if the rotation is a multiple of 100 + n;
        part2 += num / 100;
        num = num % 100;

        int new_val;
        // Perform rotation
        if (rotation == "L") {
            new_val = (curr - num);
            if (new_val < 0 && curr != 0) {
                part2++;
            }
            // e.g. -18 -> 82
            // e.g. 48 -> 48
            curr = (100 + new_val) % 100;
        } else {
            new_val = (curr + num);

            if (new_val > 100 && curr != 0) {
                part2++;
            }

            // e.g. 118 -> 18
            // e.g. 48 -> 48
            curr = (100 + new_val) % 100;
        }

        if (curr == 0) {
            part1++;
        }
    }

    cout << "Part1: " << part1 << endl;
    cout << "Part2: " << part1 + part2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
