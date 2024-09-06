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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    double p;
    if (k == 1) {
        // Find the median
        sort(all(a));
        if (n & 1) {
            p = a[n / 2];
        } else {
            p = (a[n / 2] + a[n / 2 - 1]) / 2.0;
        }
    } else {
        // Find the average
        p = sum / n;
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += pow(abs(a[i] - p), k);
    }
    cout << fixed << setprecision(2) << ans << "\n";
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}