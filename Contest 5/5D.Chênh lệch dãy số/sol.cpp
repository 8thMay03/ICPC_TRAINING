/*
    Author: kamine
    Created: 2024-09-04 21:56:35
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for (int i = 0; i + k - 1 < n; i++) {
        ans = min(ans, a[i + k - 1] - a[i]);
    }
    cout << ans << '\n';
}