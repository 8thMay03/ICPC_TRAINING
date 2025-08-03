/*
    Author: kamine
    Created: 2024-09-04 22:00:39
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, int> mp;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        ans += mp[s];
        mp[s]++;
    }
    cout << ans << '\n';
}