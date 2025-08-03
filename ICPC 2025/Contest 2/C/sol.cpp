#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        return tie(x,y) < tie(other.x, other.y);
    }
};

using Edge = pair<Point, Point>;

map<Point, vector<Point>> adj;
set<pair<Point, Point>> visited;
vector<vector<Point>> faces;

double polygon_area(const vector<Point>& poly) {
    int n = poly.size();
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i+1)%n;
        s += 1LL * poly[i].x * poly[j].y;
        s -= 1LL * poly[j].x * poly[i].y;
    }
    return abs(s) / 2.0;
}

// Trả về góc từ a -> b (so sánh để tìm trái nhất)
double angle(const Point& a, const Point& b) {
    return atan2(b.y - a.y, b.x - a.x);
}

// Tìm polygon bắt đầu từ cạnh (u -> v)
void trace_face(Point u, Point v) {
    vector<Point> face;
    Point start = u, cur = v;
    face.push_back(u);

    while (true) {
        face.push_back(cur);
        visited.insert({u, cur});
        auto& neighbors = adj[cur];

        // Tìm đỉnh tiếp theo trái nhất từ cur (so với u -> cur)
        double base_ang = angle(cur, u);
        Point next_pt;
        double max_ang = -10;

        for (auto& nei : neighbors) {
            if (nei == u) continue;
            double ang = angle(cur, nei) - base_ang;
            if (ang <= 0) ang += 2*M_PI;
            if (ang > max_ang) {
                max_ang = ang;
                next_pt = nei;
            }
        }

        if (next_pt == start) break;

        u = cur;
        cur = next_pt;
    }

    faces.push_back(face);
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1 = {x1, y1}, p2 = {x2, y2};
        adj[p1].push_back(p2);
        adj[p2].push_back(p1);
    }

    // Sắp xếp các hàng xóm theo góc để duyệt
    for (auto& [pt, vec] : adj) {
        sort(vec.begin(), vec.end(), [&](Point a, Point b) {
            return atan2(a.y - pt.y, a.x - pt.x) < atan2(b.y - pt.y, b.x - pt.x);
        });
    }

    // Tìm tất cả face
    for (auto& [u, vec] : adj) {
        for (Point v : vec) {
            if (!visited.count({u, v})) {
                trace_face(u, v);
            }
        }
    }

    // Tính diện tích từng face
    vector<double> areas;
    for (auto& face : faces) {
        double A = polygon_area(face);
        if (A > 0.0)
            areas.push_back(A);
    }

    // Loại bỏ face lớn nhất (mặt ngoài)
    double max_area = *max_element(areas.begin(), areas.end());
    double result = 0;
    for (double a : areas) {
        if (abs(a - max_area) < 1e-6) continue; // bỏ mặt ngoài
        result += a * a;
    }

    cout << fixed << setprecision(6) << result << '\n';
}
