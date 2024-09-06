#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define faster() ios::sync_with_stdio(false); cin.tie(0);
#define pi 3.14159265358979323846
#define N 1000005

using namespace std;

template <typename T> istream& operator >> (istream& in, vector<T>& vec) {for (T& element : vec) in >> element; return in;}
template <typename T> ostream& operator << (ostream& out, vector<T>& vec) {for (T& element : vec) out << element << " "; return out;}
template <typename T> ostream& operator << (ostream& out, set<T>& st) {for (const T& element : st) out << element << " "; return out;}

void solve() {
    int n, s, e, u, d;
    cin >> n >> s >> e >> u >> d;
    vector<bool> vis(n + 1, false);
    queue<pair<int, int>> q;
    q.push({s, 0});
    vis[s] = true;
    while (q.size()) {
        auto [cur, step] = q.front();
        q.pop();
        if (cur == e) {
            cout << step << endl;
            return;
        }
        if (cur + u <= n && !vis[cur + u]) {
            vis[cur + u] = true;
            q.push({cur + u, step + 1});
        }
        if (cur - d >= 1 && !vis[cur - d]) {
            vis[cur - d] = true;
            q.push({cur - d, step + 1});
        }
    }
    cout << -1 << endl;
}

signed main() {
    faster();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}