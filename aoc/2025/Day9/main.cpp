#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#include <string>
#include <tuple>

using namespace std;

struct Point2D {
    int x;
    int y;
    
    bool operator<(const Point2D pt) const {
        if (x != pt.x) return x < pt.x;
        
        return y < pt.y;
    }
    
    bool operator==(const Point2D pt) const {
        if (x == pt.x && y == pt.y) {
            return true;
        } 
        return false;
    }
    
    double distance(Point2D pt) {
        return pow(x - pt.x, 2) + pow(y - pt.y, 2);
    }

    string direction(Point2D pt) {
        if (x == pt.x) {
            if (y < pt.y) {
                return "RIGHT";
            } else {
                return "LEFT";
            }
        } else {
            if (x < pt.x) {
                return "DOWN";
            } else {
                return "UP";
            }
        }
    }
    
    void print() {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

long long part_1(vector<Point2D> pts) {
    set<tuple<int, int>> visited;
    long long res = 0;

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

            long long curr_area = (long) abs(pts[i].x - pts[j].x + 1) * abs(pts[i].y - pts[j].y + 1);
            if (curr_area >= res) {
                res = curr_area;
            }
        }
    }

    return res;
}

void solve() {    
    string line;
    
    vector<Point2D> pts;
    
    while (getline(cin, line)) {
        if (line.empty())
            continue;

        stringstream ss(line);
        string item;

        Point2D pt; 
        getline(ss, item, ',');
        pt.x  = stoi(item);
        getline(ss, item, ',');
        pt.y  = stoi(item);
        
        pts.push_back(
            pt
        );
    }
    
    cout << "Part 1:" << part_1(pts) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
}
