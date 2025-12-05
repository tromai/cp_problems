#include <bits/stdc++.h>
#include <cmath>
#include <locale>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<tuple<long long,long long>> ranges;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string first_str = s.substr(0, s.find("-"));
        string second_str = s.substr(s.find("-") + 1);

        ranges.push_back(
            make_tuple(stoll(first_str), stoll(second_str))
        );
    }

    std::sort(ranges.begin(), ranges.end());

    long long res1 = get<1>(ranges[0]) - get<0>(ranges[0]) + 1;
    long long lastR = get<1>(ranges[0]);

    for (int i = 1; i < int(ranges.size()); i++) {
        long long left = get<0>(ranges[i]);
        long long right = get<1>(ranges[i]);

        if (left > lastR) {
            // Disjoint
            res1 += right - left + 1;
            lastR = right;
        } else {
            // Overlapping
            if (right - lastR > 0) {
                res1 += right - lastR;
            }
            lastR = max(lastR, right);
        }
    }


    long long res2 = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        long long num = stoll(s);

        for (tuple<long long, long long> t : ranges) {
            if (num <= get<1>(t) && num >= get<0>(t)) {
                res2++;
                break;
            }
        }
    }

    cout << "Part 1:" << res2 << endl;
    cout << "Part 2:" << res1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
