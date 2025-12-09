#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

struct Point3D {
    int x;
    int y;
    int z;
    
    bool operator<(const Point3D pt) const {
        if (x != pt.x) return x < pt.x;
        if (y != pt.y) return y < pt.y;
        return z < pt.z;
    }
    
    bool operator==(const Point3D pt) const {
        if (x == pt.x && y == pt.y && z == pt.z) {
            return true;
        } 
        return false;
    }
    
    double distance(Point3D pt) {
        return pow(x - pt.x, 2) + pow(y - pt.y, 2) + pow(z - pt.z, 2);
    }

    void print() {
        cout << "(" << x << "," << y << "," << z << ")" << endl;
    }
};

int find(vector<int> &parents, int i) {
    int res = i;
    
    while (parents[res] != res) {
        parents[res] = parents[parents[res]];
        res = parents[res];
    }
    
    return res;
}

int my_union(vector<int> &parents, vector<int> &rank, int i, int j) {
    int root_i = find(parents, i);
    int root_j = find(parents, j);
    
    if (root_i == root_j) {
        return rank[root_i];
    } else {
        if (rank[root_i] < rank[root_j]) {
            parents[root_i] = root_j;
            rank[root_j] += rank[root_i];
            return rank[root_j];
        } else {
            parents[root_j] = root_i;
            rank[root_i] += rank[root_j];
            return rank[root_i];
        }
    }
}

int solve_part1(
    vector<Point3D> pts,
    vector<tuple<double, int, int>> distances
) {
    sort(distances.begin(), distances.end());

    vector<int> parents;
    vector<int> rank;
    for (int i = 0; i < int(pts.size()); i++) {
        parents.push_back(i);
        rank.push_back(1);
    }
    
    // Connecting 1000 times from the problem statement.
    // This is 10 for the small example.
    for (int i = 0; i < 1000; i++) {
        auto [dis, x ,y] = distances[i];
        my_union(parents, rank, x, y);
    }

    sort(rank.begin(), rank.end());
    long long res = 1;
    for (int i = int(rank.size() - 1); i > int(rank.size() - 4); i--) {
        res *= rank[i];
    }
    
    return res;
}

long long solve_part2(
    vector<Point3D> pts,
    vector<tuple<double, int, int>> distances
) {
    sort(distances.begin(), distances.end());

    vector<int> parents;
    vector<int> rank;
    for (int i = 0; i < int(pts.size()); i++) {
        parents.push_back(i);
        rank.push_back(1);
    }

    int last_x;
    int last_y;
    for (int i = 0; i < int(distances.size()); i++) {
        auto [dis, x ,y] = distances[i];
        int latest_rank = my_union(parents, rank, x, y);
        last_x = x;
        last_y = y;
        if (latest_rank == int(pts.size())) {
            break;
        }
    }
    
    return long(pts[last_x].x) * long(pts[last_y].x);
}


void solve() {    
    string line;
    vector<Point3D> pts;
    while (getline(cin, line)) {
        if (line.empty())
            continue;

        Point3D pt; 
        stringstream ss(line);
        string item;

        getline(ss, item, ',');
        pt.x  = stoi(item);
        getline(ss, item, ',');
        pt.y  = stoi(item);
        getline(ss, item, ',');
        pt.z  = stoi(item);

        pts.push_back(pt);
    }

    vector<tuple<double, int, int>> distances;
    set<tuple<int, int>> visited;
    for (int i = 0; i < int(pts.size()); i++) {
        for (int j = 0; j < int(pts.size()); j++) {
            if (
                j == i 
                || visited.find(make_tuple(i, j)) != visited.end()
                || visited.find(make_tuple(j, i)) != visited.end()
            ) {
                continue;
            }

            visited.insert(make_tuple(i,j));
            visited.insert(make_tuple(j,i));

            double distance = pts[i].distance(pts[j]);
            distances.push_back(
                make_tuple(distance, i, j)
            );
        }
    }
    

    cout << "Part 1:" << solve_part1(pts, distances) << endl;
    cout << "Part 2:" << solve_part2(pts, distances) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
