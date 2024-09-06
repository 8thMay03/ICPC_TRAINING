/*
    Author: kamine
    Created: 2024-09-04 14:56:26
*/
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    vector<int> mp(mx + 1);
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    for (int i = mx; i >= 1; i--) {
        if (mp[i] > 1) {
            cout << i << endl;
            return;
        }
        int cnt = 0;
        for (int j = i; j <= mx; j += i) {
            if (mp[j]) cnt++;
            if (cnt == 2) {
                cout << i << endl;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}