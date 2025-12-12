#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

void combine(
    vector<int>& arr,
    vector<vector<int>> &res,
    int start,
    vector<int>& current,
    int k
) {
    if ((int) current.size() == k) {
        res.push_back(current);
        return;
    }

    for (int i = start; i < (int) arr.size(); i++) {
        current.push_back(arr[i]);
        combine(arr, res, i + 1, current, k);
        current.pop_back();
    }
}

long long encode(const vector<int> &target) {
    long long res = 0;
    int size = target.size();
    for (int i = 0; i < size; i++) {
        res += 1 << target[i];
    }
    
    return res;
}

int jolt_cal(
    vector<vector<int>>& toggles,
    vector<int>& target,
    map<tuple<long long, int>, int> &cache,
    int start,
    int count
) {
    // cout << "START: " << start << endl;
    // cout << "COUNT: " << count << endl;
    // for (auto a : target) {
    //     cout << a << " ";
    // }
    // cout << endl;
    
    tuple<long long, int> key = make_tuple(
        encode(target), 
        count
    );
    if (cache.find(key) != cache.end()) {
        return cache.find(key)->second;
    }
    
    bool all_0 = true;
    for (auto a : target) {
        if (a != 0) {
            all_0 = false;
        }
        
        if (a < 0) {
            // A very big.
            // This state mean going this path is not desirable.
            return 100000;
        }
    }

    if (all_0) {
        return count;
    }
    
    // No more to add + cannot reach target
    if (start >= (int) toggles.size()) {
        return 100000;
    }
    
    int res = 100000;
    
    // Pick current one
    vector<int> curr_tog = toggles[start];
    for (int tog : curr_tog) {
        target[tog] -= 1;
    }
    
    res = min(res, jolt_cal(toggles, target, cache, start, count + 1));
    // Skipping this one.
    for (int tog : curr_tog) {
        target[tog] += 1;
    }
    res = min(res, jolt_cal(toggles, target, cache, start + 1, count));
    
    cache[key] = res;
    return res;
}

void solve() {    
    string line;
    
    long long res_part_1 = 0;
    long long res_part_2 = 0;
    while (getline(cin, line)) {
        if (line.empty())
            continue;

        // [.##.] (3) (1,3) (2) (2,3) (0,2) (0,1) {3,5,4,7}
        int light_start = line.find("[");
        int light_end = line.find("]");
        
        string light_str = line.substr(light_start + 1, light_end - light_start - 1);
        int num_lights = (int) light_str.size();
        int light_bits = 0;
        for (int i = 0; i < num_lights; i++) {
            if (light_str[i] == '#') {
                light_bits += 1 << (num_lights - i - 1);
            }
        }
        
        vector<int> toggles;
        vector<vector<int>> toggles_org;
        // Capture the toggles (3) (1,3) (2) (2,3) (0,2) (0,1)
        regex toggleRe("\\(([^)]*)\\)");
        smatch m;
        auto it = line.cbegin();
        while (regex_search(it, line.cend(), m, toggleRe)) {
            string inside = m[1];
            
            string tmp;
            stringstream ss(inside);
            int bitMask = 0;

            vector<int> tog;
            
            while (getline(ss, tmp, ',')) {
                // 0 mean the first light
                bitMask += 1 << (num_lights - stoi(tmp) - 1);
                tog.push_back(stoi(tmp));
            }
            toggles.push_back(bitMask);
            toggles_org.push_back(tog);
            it = m.suffix().first;
        }
        
        vector<vector<int>> combs;
        vector<int> curr = {};
        for (int i = 0; i < num_lights; i++) {
            combine(toggles, combs, 0, curr, i);
            curr = {};
        }
        
        int curr_count_part_1 = 0;
        for (auto a : combs) {
            int tmp = light_bits;
            for (auto b : a) {
                tmp = tmp ^ b;
            }
            if (tmp == 0) {
                curr_count_part_1 = (int) a.size();
                break;
            }
        }
                
        res_part_1 += curr_count_part_1;

        vector<int> jolts;
        regex jolts_re("\\{([^}]*)\\}");
        if (regex_search(line, m, jolts_re)) {
            string inside = m[1];
            string tmp;
            stringstream ss(inside);
            while (getline(ss, tmp, ',')) {
                jolts.push_back(stoi(tmp));
            }
        }
        
        // cout << "JOLTS" << endl;
        // for (auto j : jolts) {
        //     cout << j << " ";
        // }
        // cout << endl;
        
        // for (auto a: toggles_org) {
        //     for (auto b : a) {
        //         cout << b << " ";
        //     }
        //     cout << endl;
        // }
        
        map<tuple<long long, int>, int> cache;
        int curr_part_2 = jolt_cal(
            toggles_org,
            jolts,
            cache,
            0,
            0
        );
        // Only happen if there is no solution.
        // This won't happen in the aoc data set.
        if (curr_part_2 == 100000) {
            continue;
        } else {
            res_part_2 += curr_part_2;
        }
    }

    cout << "Part 1: " << res_part_1 << endl;
    cout << "Part 2: " << res_part_2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
