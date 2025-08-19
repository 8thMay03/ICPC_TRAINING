#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;
    long long u, v;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<Point> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i].x >> pts[i].y;
        pts[i].u = pts[i].x + pts[i].y;
        pts[i].v = pts[i].x - pts[i].y;
    }

    // find top 2 / bottom 2 for u and v
    auto top2 = [&](auto getter) {
        array<pair<long long,int>,2> mx = {{{LLONG_MIN,-1},{LLONG_MIN,-1}}};
        array<pair<long long,int>,2> mn = {{{LLONG_MAX,-1},{LLONG_MAX,-1}}};
        for (int i = 0; i < N; i++) {
            long long val = getter(pts[i]);
            if (val > mx[0].first) { mx[1]=mx[0]; mx[0]={val,i}; }
            else if (val > mx[1].first) { mx[1]={val,i}; }
            if (val < mn[0].first) { mn[1]=mn[0]; mn[0]={val,i}; }
            else if (val < mn[1].first) { mn[1]={val,i}; }
        }
        return make_pair(mx, mn);
    };

    auto u_ext = top2([](const Point &p){return p.u;});
    auto v_ext = top2([](const Point &p){return p.v;});

    // candidate points to remove
    set<int> cand;
    cand.insert(u_ext.first[0].second);
    cand.insert(u_ext.first[1].second);
    cand.insert(u_ext.second[0].second);
    cand.insert(u_ext.second[1].second);
    cand.insert(v_ext.first[0].second);
    cand.insert(v_ext.first[1].second);
    cand.insert(v_ext.second[0].second);
    cand.insert(v_ext.second[1].second);

    long long ans = LLONG_MAX;
    for (int id : cand) {
        long long max_u = (id != u_ext.first[0].second ? u_ext.first[0].first : u_ext.first[1].first);
        long long min_u = (id != u_ext.second[0].second ? u_ext.second[0].first : u_ext.second[1].first);
        long long max_v = (id != v_ext.first[0].second ? v_ext.first[0].first : v_ext.first[1].first);
        long long min_v = (id != v_ext.second[0].second ? v_ext.second[0].first : v_ext.second[1].first);
        long long diam = max(max_u - min_u, max_v - min_v);
        ans = min(ans, diam);
    }
    cout << ans << "\n";
    return 0;
}
