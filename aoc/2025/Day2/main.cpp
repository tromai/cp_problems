#include <bits/stdc++.h>
#include <string>

using namespace std;

bool valid(string s) {
    if (s.size() % 2 != 0) {
        return true;
    }

    if (s.size() == 1) {
        return true;
    }

    int left = 0;
    int right = s.size() / 2;

    for (long i = 0; i < long(s.size() / 2); i++) {
        if (s[left] != s[right]) {
            return true;
        }
        left++;
        right++;
    }
    return false;
}

bool valid2(string s) {
    // Double the string and remove the first and last characters.
    string new_s = s.substr(1, s.size() - 1) + s.substr(0, s.size() - 1);
    if (new_s.find(s) != new_s.npos) {
        // If find orignal S then there is a repetition pattern.
        // and it is not valid.
        return false;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;

    stringstream ss(s);

    string t;
    char del = ',';

    long long res1 = 0;
    long long res2 = 0;
    while (getline(ss, t, del)) {
        string first_str = t.substr(0, t.find("-"));
        string second_str = t.substr(t.find("-") + 1, t.size() - 1);

        long long first =  stoll(first_str);
        long long second = stoll(second_str);

        for (long long i = first; i <= second; i ++) {
            if (!valid(to_string(i))) {
                res1 += i;
            }
            if (!valid2(to_string(i))) {
                res2 += i;
            }
        }
    }

    cout << "Part 1: " << res1 << endl;
    cout << "Part 2: " << res2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
