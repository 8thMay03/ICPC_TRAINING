#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = INT_MAX;
    for (int i : a) {
        auto it = lower_bound(b.begin(), b.end(), i);
        if (it != b.end()) ans = min(ans, abs(*it - i));
        if (it != b.begin()) {
            --it;
            ans = min(ans, abs(*it - i));
        }
    }

    cout << ans;
}
