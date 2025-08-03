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

template <typename T> istream& operator >> (istream& in, vector<T>& vec) {for (T& element : vec) in >> element; return in;}
template <typename T> ostream& operator << (ostream& out, vector<T>& vec) {for (T& element : vec) out << element << " "; return out;}
template <typename T> ostream& operator << (ostream& out, set<T>& st) {for (const T& element : st) out << element << " "; return out;}

bool is_square(int x) {
    int y = sqrt(x);
    return y * y == x;
}

void solve() {
    vector<pii> a(3);
    int area = 0;
    for (int i = 0; i < 3; i++) {
        cin >> a[i].fi >> a[i].se;
        if (a[i].fi > a[i].se) {
            swap(a[i].fi, a[i].se);
        }
        area += a[i].fi * a[i].se;
    }
    if (!is_square(area)) {
        cout << 0;
        return;
    }
    sort(all(a));
    if (a[0].fi + a[1].fi + a[2].fi == a[0].se && a[0].se == a[1].se && a[1].se == a[2].se) {
        cout << a[0].se;
        return;
    } 
    int d = sqrt(area);
    for (int i = 0; i < 3; i++) {
        if (a[i].se == d) {
            if (a[(i + 1) % 3].se == a[(i + 2) % 3].se && a[(i + 1) % 3].fi + a[(i + 2) % 3].fi == d && a[(i + 1) % 3].se + a[i].fi == d) {
                cout << d;
                return;
            }
        }
    }
    cout << 0;
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}