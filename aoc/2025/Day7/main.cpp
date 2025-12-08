#include <bits/stdc++.h>
#include <cmath>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

int solve_part1(vector<string> lines) {
    int start = lines[0].find("S");
    
    queue<tuple<int, int>> q;
    q.push((make_tuple(0, start)));
    set<tuple<int, int>> visited = {make_tuple(0, start)};
    
    int max_width = lines[0].size();
    int max_height = lines.size();
    int res = 0;

    while (!q.empty()) {
        vector<tuple<int, int>> beam_pos;
        while (!q.empty()) {
            beam_pos.push_back(q.front());
            q.pop(); 
        }
        
        for (tuple<int, int> pos : beam_pos) {
            int x = get<0>(pos);
            int y = get<1>(pos);
            if (lines[x][y] == '^') {
                res ++;
                // Remember when it split, x stays the same.
                tuple<int, int> split1 = make_tuple(x, y + 1);
                if (
                    y + 1 < max_width 
                    // && x + 1 < max_height
                    && visited.find(split1) == visited.end()
                ) {
                    q.push(split1);
                    visited.insert(split1);
                }

                tuple<int, int> split2 = make_tuple(x, y - 1);
                if (
                    y - 1 >= 0
                    // && x + 1 < max_height
                    && visited.find(split2) == visited.end()
                ) {
                    q.push(split2);
                    visited.insert(split2);
                }
            } else {
                tuple<int, int> no_split = make_tuple(x + 1, y);
                if (
                    x + 1 < max_height
                    && visited.find(no_split) == visited.end()
                ) {
                    q.push(no_split);
                    visited.insert(no_split);
                }
            }
        } 
    }
    return res;
}

long long traverse(
    const vector<string> lines, 
    map<tuple<int, int>, long long> &cache, 
    int x, 
    int y
) {
    if (
        x < 0
        || y < 0
        || x >= int(lines.size())
        || y >= int(lines[0].size())
    ) {
        return 0;
    }
    
    if (
        cache.find(make_tuple(x, y)) != cache.end()
    ) {
        return cache.at(make_tuple(x, y));
    }

    if (x == int(lines.size() - 1)) {
        cache[make_tuple(x, y)] = 1;
        return 1;
    }
    
    long long res;
    if (
        x < int(lines.size()) - 1
        && lines[x + 1][y] == '^'
    ) {
        res = traverse(lines, cache, x + 1, y - 1) + traverse(lines, cache, x + 1, y + 1);
        cache[make_tuple(x, y)] = res;
        return res;
    } else {
        res = traverse(lines, cache, x + 1, y);
        cache[make_tuple(x, y)] = res;
        return res;
    }
}

long long solve_part2(vector<string> lines) {
    int start = lines[0].find("S");
    map<tuple<int, int>, long long> cache;
    
    long long res = traverse(lines, cache, 0, start);
    for (const auto& [key, value] : cache) {
        std::cout << get<0>(key) << "," << get<1>(key) << " - " << value << "\n";
    }
    
    return res;
}


void solve() {    
    vector<string> lines;
    string line;
    while (getline(cin, line)) {
        if (line.empty())
            continue;

        lines.push_back(line);
    }
    
    cout << "Part 1:" << solve_part1(lines) << endl;
    cout << "Part 2:" << solve_part2(lines) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
