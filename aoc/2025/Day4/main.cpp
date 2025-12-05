#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

// Directions for ease of calculation.
vector<tuple<int, int>> DIRS {
    // Horizontal
    make_tuple(0, 1),
    make_tuple(0, -1),
    
    // Vertical
    make_tuple(1, 0),
    make_tuple(-1, 0),
    
    // Diagonals
    make_tuple(-1, -1),
    make_tuple(-1, 1),
    make_tuple(1, 1),
    make_tuple(1, -1),
};

void print_grid(vector<vector<char>> grid) {
    for (int i = 0; i < int(grid.size()); i++) {
        for (int j = 0; j < int(grid[i].size()); j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << "------" << endl;
}

int calculate(vector<vector<char>> grid, int n, int level) {
    int res = 0;
    
    queue<tuple<int,int>> q;
    set<tuple<int,int>> s;
    
    int MAX_X = n;
    int MAX_Y = int(grid[0].size());
    
    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_Y; j++) {
            if (grid[i][j] != '@') {
                continue;
            }

            int count = 0;
            for (tuple<int, int> dir : DIRS) {
                int x = get<0>(dir) + i;
                int y = get<1>(dir) + j;
                if (
                    0 <= x
                    && x < MAX_X
                    && 0 <= y
                    && y < MAX_Y
                    && grid[x][y] != '.'
                ) {
                    count ++;
                }
            }

            if (count < 4) {
                q.push(make_tuple(i, j));
            }

            grid[i][j] = '0' + count;
        }
    }
    
    while (!q.empty() && level != 0) {
        vector<tuple<int, int>> eles;
        while (!q.empty()) {
            eles.push_back(q.front());
            q.pop();
        }

        for (auto ele: eles) {
            int x = get<0>(ele);
            int y = get<1>(ele);
    
            s.insert(ele);

            // Lower the count of adjacent towels.
            for (tuple<int, int> dir : DIRS) {
                int new_x = get<0>(dir) + x;
                int new_y = get<1>(dir) + y;
                tuple<int, int> t = make_tuple(new_x, new_y);
                if (
                    0 <= new_x
                    && new_x < MAX_X
                    && 0 <= new_y
                    && new_y < MAX_Y
                    && grid[new_x][new_y] != '.'
                    && grid[new_x][new_y] != '0'
                    && grid[new_x][new_y] != '1'
                    && grid[new_x][new_y] != '2'
                    && grid[new_x][new_y] != '3'
                ) {
                    int new_count = grid[new_x][new_y] - '0' - 1;
                    grid[new_x][new_y] = '0' + new_count;
                    if (
                        new_count < 4
                        && s.find(t) == s.end()
                    ) {
                        q.push(t);
                    }
                }
            }

            grid[x][y] = '.';
            res += 1;
        }
        
        level--;
    }
    
    return res;
}

void solve() {
    int n;
    cin >> n;

    // Parse the grid
    vector<vector<char>> grid;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        vector<char> row;
        
        for (char c : s) {
            row.push_back(c);
        }
        
        grid.push_back(row);
    }
    
    cout << "Part 1: " << calculate(grid, n, 1) << endl;
    cout << "Part 2: " << calculate(grid, n, -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
