#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define faster() ios::sync_with_stdio(false); cin.tie(0);
#define pi 3.14159265358979323846
#define N 1000005

using namespace std;

template<typename T>
istream &operator >>(istream &in, vector<T> &vec) {
    for (T &element: vec) in >> element;
    return in;
}

template<typename T>
ostream &operator <<(ostream &out, vector<T> &vec) {
    for (T &element: vec) out << element << " ";
    return out;
}

template<typename T>
ostream &operator <<(ostream &out, set<T> &st) {
    for (const T &element: st) out << element << " ";
    return out;
}

bool isSort(vector<int> a) {
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    cin >> a;
    if (isSort(a)) {
        cout << 0 << endl;
        return;
    }
    queue<pair<vector<int>, int>> q;
    map<vector<int>, int> vis;
    q.emplace(a, 0);
    vis[a] = 1;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        int step = top.se;
        vector<int> v = top.fi;
        for (int i = 0; i < 2 * n; i += 2) {
            swap(v[i], v[i + 1]);
        }
        if (!vis[v]) {
            if (isSort(v)) {
                cout << step + 1;
                return;
            }
            vis[v] = 1;
            q.emplace(v, step + 1);
        }
        v = top.fi;
        for (int i = 0; i < n; i++) {
            swap(v[i], v[i + n]);
        }
        if (!vis[v]) {
            if (isSort(v)) {
                cout << step + 1;
                return;
            }
            vis[v] = 1;
            q.emplace(v, step + 1);
        }
    }
    cout << -1;
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}
