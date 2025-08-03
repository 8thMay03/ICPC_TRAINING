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

int count(int n) {
    return 9 * ((1 << (n - 1)) * 9 - 8);
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += count(i);
    }
    int digit = s[0] - '0';
    ans += count(n) / 9 * (digit - 1);
    int num = stoll(s);
    for (int i = digit * pow(10, n - 1); i <= num; i++) {
        int bitmask = 0;
        int temp = i;
        // Xây dựng bitmask cho số hiện tại
        while (temp > 0) {
            int digit = temp % 10;
            bitmask |= (1 << digit); // Bật bit tương ứng với chữ số
            temp /= 10;
        }
        // Đếm số bit được bật trong bitmask
        if (__builtin_popcount(bitmask) <= 2) {
            ++ans;
        }
    }
    cout << ans << endl;
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}