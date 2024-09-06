/*
    Author: kamine
    Created: 2024-09-04 21:45:02
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> lmax(n), rmin(n);
    lmax[0] = a[0];
    for (int i = 1; i < n; i++) {
        lmax[i] = max(lmax[i - 1], a[i]);
    }
    rmin[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rmin[i] = min(rmin[i + 1], a[i]);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == lmax[i] && a[i] == rmin[i]) {
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << ' ';
    for (int i = 0; i < min((int)ans.size(), 100); i++) {
        cout << ans[i] << ' ';
    }
}