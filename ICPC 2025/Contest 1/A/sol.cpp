#include <bits/stdc++.h>

using namespace std;

using Point = pair<int, int>;

int count_triangles(const vector<Point>& points) {
    int n = points.size();
    long long total = 1LL * n * (n - 1) * (n - 2) / 6;
    long long collinear = 0;

    for (int i = 0; i < n; ++i) {
        map<pair<int, int>, int> slopes;
        int xi = points[i].first, yi = points[i].second;

        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int xj = points[j].first, yj = points[j].second;
            int dx = xj - xi;
            int dy = yj - yi;

            int g = __gcd(dx, dy);
            dx /= g;
            dy /= g;

            // Chuẩn hóa vector hướng
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }

            slopes[{dx, dy}]++;
        }
        for (auto& [_, count] : slopes) {
            if (count >= 2) {
                collinear += 1LL * count * (count - 1) / 2;
            }
        }
    }

    // Mỗi tam giác thẳng hàng bị đếm 3 lần (mỗi đỉnh 1 lần)
    collinear /= 3;

    return total - collinear;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    cout << count_triangles(points) << '\n';
    return 0;
}
