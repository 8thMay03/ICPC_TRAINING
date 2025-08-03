/*
    Author: kamine
    Created: 2024-09-01 10:47:11
*/
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), diff;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Mảng diff thể hiện sự chênh lệch giữa ai và bi
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        diff.push_back(a[i] - b[i]);
    }
    sort(diff.rbegin(), diff.rend());
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        sum += diff[i];
        if (sum < 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0;
}