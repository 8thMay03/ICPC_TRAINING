/*
    Author: kamine
    Created: 2024-09-04 16:52:59
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int idx;
        cin >> idx;
        mp[idx]++;
    }
    vector<pair<int, int>> vp;
    for (auto [idx, cnt] : mp) {
        vp.emplace_back(idx, cnt);
    }
    sort(vp.begin(), vp.end(), [&](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });
    int idx = 0;
    while (idx < vp.size() && vp[idx].second == vp[0].second) {
        idx++;
    }
    if (idx == vp.size()) {
        cout << "NONE";
    } else {
        cout << vp[idx].first;
    }
}