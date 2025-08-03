/*
    Author: kamine
    Created: 2024-09-06 21:22:40
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n[3];
    cin >> n[0] >> n[1] >> n[2];
    vector<string> s[3];
    map<string, int> mp[3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n[i]; j++) {
            int cnt;
            string x;
            cin >> x >> cnt;
            mp[i][x] += cnt;
            s[i].push_back(x);
        }
    }
    vector<string> ans;
    for (int i = 0; i < n[0]; i++) {
        if (mp[0][s[0][i]] >= 20 && mp[1][s[0][i]] >= 20 && mp[2][s[0][i]] >= 20) {
            ans.push_back(s[0][i]);
            mp[0][s[0][i]] = 0;
            mp[1][s[0][i]] = 0;
            mp[2][s[0][i]] = 0;
        }
    }
    cout << ans.size() << ' ';
    for (string &x : ans) {
        cout << x << ' ';
    }
}