#include <bits/stdc++.h>
#include <cmath>
#include <string>

using namespace std;

long long solve_part1(vector<string> lines) {
    // Fill data
    vector<vector<long long>> data;    
    for (int i = 0; i < int(lines.size() - 1); i++) {
        istringstream iss(lines[i]);
        vector<long long> parts;
        string token;
        
        while (iss >> token) {
            parts.push_back(
                stol(token)
            );
        }

        data.push_back(parts);
    }
    
    // Fill ops
    vector<string> ops;
    string op_line = lines[lines.size() - 1];
    istringstream iss(op_line);
    string token;
    while (iss >> token) {
        ops.push_back(
            token
        );
    }
    
    // Assuming the number of ops is equal to number of each number in each data line.    
    int line_element_count = int(ops.size());
    int data_line_count = int(data.size());
    vector<long long> results;
    for (int i = 0; i < line_element_count; i++) {
        if (ops[i] == "+") {
            long long res = 0;
            for (int j = 0; j < data_line_count; j++) {
                res += data[j][i];
            }
            results.push_back(res);
        } else if (ops[i] == "*") {
            long long res = 1;
            for (int j = 0; j < data_line_count; j++) {
                res *= data[j][i];
            }
            results.push_back(res);
        }
    }
    
    long long part1 = 0;
    for (auto a : results) {
        part1 += a;
    }
    
    return part1;
}

long long solve_part2(vector<string> lines) {
    int data_lines_count = int(lines.size() - 1);

    // Fill ops and the maximum digit for each column.
    string op_line = lines[lines.size() - 1];
    vector<int> ops_pos;
    for (int i = 0; i < int(op_line.size()); i++) {
        if (op_line[i] != ' ') {
            ops_pos.push_back(i);
        }
    }
    
    long long res = 0;
    
    for (int i = 0; i < int(ops_pos.size()); i++) {
        int digit;
        if (i == int(ops_pos.size()) - 1) {
            digit =  int(op_line.size()) - ops_pos[i];
        } else {
            digit = ops_pos[i + 1] - ops_pos[i] - 1;
        }

        vector<int> eles;
        for (int j = ops_pos[i]; j < ops_pos[i] + digit; j++) {
            string col_ele = "";
            for (int k = 0; k < data_lines_count; k++) {
                string s(1, lines[k][j]); 
                if (s != " ") {
                    col_ele += s;
                }
            }
            eles.push_back(stoi(col_ele));
        }
        
        if (op_line[ops_pos[i]] == '*') {
            long long res_col = 1;
            for (int ele : eles) {
                res_col *= ele;
            }
            res += res_col;
        } else {
            long long res_col = 0;
            for (int ele : eles) {
                res_col += ele;
            }
            res += res_col;
        }
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
