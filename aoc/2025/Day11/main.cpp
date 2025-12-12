#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

int traverse(
    map<string, vector<string>> &adjs,
    set<string> &visited,
    string root
) {
    if (root == "out") {
        return 1;
    }
    
    int res = 0;
    visited.insert(root);
    vector<string> &neighbors = adjs[root];
    for (string nei : neighbors) {
        if (visited.find(nei) == visited.end()) {
            res += traverse(adjs, visited, nei);
        }
    }

    visited.erase(root);
    return res;
}

long long traverse2(
    map<string, vector<string>> &adjs,
    // For checking cycle
    set<string> &visited,
    map<tuple<string, int>, long long> &cache,
    // Store the remaining required keys in the path.
    // If we visit a require key -> remove it from this set.
    set<string> &needed,
    string root
) {
    if (root == "out") {
        if (needed.empty()) {
            return 1;
        }
        return 0;
    }

    tuple<string, int> cacheKey = make_tuple(root, (int) needed.size());
    if (cache.find(cacheKey) != cache.end()) {
        return cache[cacheKey];
    }
 
    long long res = 0;
    visited.insert(root);

    int found = needed.count(root);
    if (found) {
        needed.erase(root);
    }

    vector<string> &neighbors = adjs[root];
    for (string nei : neighbors) {
        if (visited.find(nei) == visited.end()) {
            res += traverse2(adjs, visited, cache, needed, nei);
        }
    }

    visited.erase(root);
    if (found) {
        needed.insert(root);
    }

    cache[cacheKey] = res;
    return res;
}

void solve() {    
    string line;
    map<string, vector<string>> adjs;
    while (getline(cin, line)) {
        if (line.empty())
            continue;
        
        stringstream ss(line);
        string part;
        vector<string> parts;
        while (getline(ss, part, ' ')) {
            parts.push_back(part);
        }
        
        // Assuming all node name has 3 characters.
        string first = parts[0].substr(0, 3);

        vector<string> to;
        for (int i = 1; i < (int) parts.size(); i++) {
            to.push_back(parts[i]);
        }

        if (adjs.find(first) == adjs.end()) {
            adjs[first] = to;
        } else {
            adjs[first].insert(adjs[first].end(), to.begin(), to.end());
        }
    }
        
    set<string> visited;
    int res_part_1 = traverse(
        adjs,
        visited,
        "you"
    );
    
    set<string> visited2;
    map<tuple<string, int>, long long> cache;
    set<string> needed = {"fft", "dac"};
    long long res_part_2 = traverse2(
        adjs,
        visited2,
        cache,
        needed,
        "svr"
    );

    cout << "Part 1: " << res_part_1 << endl;
    cout << "Part 2: " << res_part_2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
