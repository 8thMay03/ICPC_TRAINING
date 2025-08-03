/*
    Author: kamine
    Created: 2024-09-04 10:44:56
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int q;
    cin >> q;
    map<int, int> mp;
    while (q--) {
        int x;
        cin >> x;
        mp[x - 1]++;
    }
    int cnt = 0;
    for (int i = 0; i < s.size() / 2; i++) {
        cnt += mp[i];
        if (cnt & 1) {
            swap(s[i], s[s.size() - i - 1]);
        }
    }
    cout << s << '\n';
}