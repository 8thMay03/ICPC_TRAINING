#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//Convex Hull Trick
struct Line {
    ll m, c;
    double xLeft;
    bool isQuery;

    Line(ll m = 0, ll c = 0) : m(m), c(c), xLeft(-1e18), isQuery(false) {}
    ll valueAt(ll x) const {
        return m * x + c;
    }
    bool operator<(const Line& other) const {
        if (!other.isQuery) return m < other.m;
        return xLeft < other.xLeft;
    }
};

struct CHT {
    deque<Line> hull;

    bool isBad(const Line& l1, const Line& l2, const Line& l3) {
        return (l3.c - l1.c) * (l1.m - l2.m) <= (l2.c - l1.c) * (l1.m - l3.m);
    }

    void addLine(ll m, ll c) {
        Line l3 = Line(m, c);
        while (hull.size() >= 2 && isBad(hull[hull.size() - 2], hull[hull.size() - 1], l3)) {
            hull.pop_back();
        }
        hull.push_back(l3);
    }

    ll getBest(ll x) {
        while (hull.size() >= 2 && hull[0].valueAt(x) >= hull[1].valueAt(x)) {
            hull.pop_front();
        }
        return hull[0].valueAt(x);
    }
};

int main() {
    int N;
    ll C;
    cin >> N >> C;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    vector<ll> dp(N, LLONG_MAX);
    dp[0] = 0;

    CHT cht;
    cht.addLine(-2 * H[0], H[0] * H[0] + dp[0]);

    for (int i = 1; i < N; ++i) {
        dp[i] = cht.getBest(H[i]) + H[i] * H[i] + C;
        cht.addLine(-2 * H[i], H[i] * H[i] + dp[i]);
    }

    cout << dp[N - 1] << endl;

    return 0;
}
