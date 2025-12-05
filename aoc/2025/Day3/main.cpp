#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long max_battery(string s, int k) {
    vector<int> stack;
    
    int size = int(s.size());
    int to_remove = size - k;

    for (int i = 0; i < size; i++) {
        int num = stoi(s.substr(i, 1));
        while (
            !stack.empty()
            && stack.back() < num
            && to_remove > 0
        ) {
            stack.pop_back();
            to_remove --;
        }
        stack.push_back(num);
    }
    
    long long res = 0;
    for (int i = 0; i < k; i++) {
        res += pow(10, k - i - 1) * stack[i];
    }
    
    return res;
}

void solve() {
    int n;
    cin >> n;
    long long res1 = 0;
    long long res2 = 0;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        res1 += max_battery(s, 2);
        res2 += max_battery(s, 12);
    }
    
    cout << "Part 1: " << res1 << endl;
    cout << "Part 2: " << res2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
