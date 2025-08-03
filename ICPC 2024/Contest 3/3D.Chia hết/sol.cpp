/*
    Author: kamine
    Created: 2024-09-04 17:07:55
*/
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    unordered_map<ll, ll> mp;
    mp[0] = 1;
    ll sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum = (sum + x) % m;
        ans += mp[sum];
        mp[sum]++;
    }
    cout << ans;
}