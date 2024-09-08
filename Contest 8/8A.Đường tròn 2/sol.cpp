/*
	Author: kamine
	Created: 2024-09-08 09:22:21
*/
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-7;

struct Point {
    double x, y;
};

// Tính khoảng cách giữa 2 điểm
double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Tìm tâm và bán kính của đường tròn từ 2 điểm
pair<Point, double> circleFrom2Points(const Point& A, const Point& B) {
    Point center = {(A.x + B.x) / 2, (A.y + B.y) / 2};
    double radius = dist(A, B) / 2;
    return {center, radius};
}

// Tìm tâm và bán kính của đường tròn từ 3 điểm
pair<Point, double> circleFrom3Points(const Point& A, const Point& B, const Point& C) {
    double d = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    Point center;
    center.x = ((A.x * A.x + A.y * A.y) * (B.y - C.y) + (B.x * B.x + B.y * B.y) * (C.y - A.y) + (C.x * C.x + C.y * C.y) * (A.y - B.y)) / d;
    center.y = ((A.x * A.x + A.y * A.y) * (C.x - B.x) + (B.x * B.x + B.y * B.y) * (A.x - C.x) + (C.x * C.x + C.y * C.y) * (B.x - A.x)) / d;
    double radius = dist(center, A);
    return {center, radius};
}

// Kiểm tra xem một điểm có nằm trong hình tròn hay không
bool isInCircle(const Point& p, const Point& center, double r) {
    return dist(p, center) <= r + EPS;
}

// Thuật toán Welzl để tìm hình tròn bao phủ nhỏ nhất
pair<Point, double> welzl(vector<Point>& P, vector<Point> R, int n) {
    if (n == 0 || R.size() == 3) {
        if (R.size() == 0) return {{0, 0}, 0};
        if (R.size() == 1) return {R[0], 0};
        if (R.size() == 2) return circleFrom2Points(R[0], R[1]);
        return circleFrom3Points(R[0], R[1], R[2]);
    }
    
    Point p = P[n-1];
    auto d = welzl(P, R, n-1);
    
    if (isInCircle(p, d.first, d.second)) {
        return d;
    }
    
    R.push_back(p);
    return welzl(P, R, n-1);
}

// Hàm chính để tìm hình tròn nhỏ nhất bao phủ tất cả các điểm
pair<Point, double> findMinCircle(vector<Point>& points) {
    random_shuffle(points.begin(), points.end());
    return welzl(points, {}, points.size());
}

int main() {
    int N;
    cin >> N;
    
    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    auto result = findMinCircle(points);
    
    // In ra bán kính với độ chính xác 6 chữ số thập phân
    cout << fixed << setprecision(6) << result.second << endl;
    
    return 0;
}
