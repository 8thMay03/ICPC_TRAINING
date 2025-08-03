/*
    Author: kamine
    Created: 2024-09-01 08:31:27
*/
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    cin >> k;
    vector<int> sz(k);
    for (int i = 0; i < k; i++) {
        cin >> sz[i];
    }
    map<int, int> mp;
    for (int i = 0; i < k; i++) {
        set<int> st;
        for (int j = 0; j < sz[i]; j++) {
            int x;
            cin >> x;
            st.insert(x);
        }
        for (int x : st) {
            mp[x]++;
        }
    }
    for (auto [x, y] : mp) {
        if (y == k) {
            cout << x << ' ';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}