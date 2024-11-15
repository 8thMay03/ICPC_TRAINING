/*
    Author: kamine
    Created: 2024-09-23 20:59:54
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
    int l = 0, r = n - 1;
    int time1 = 0, time2 = 0;
    int cnt1 = 0, cnt2 = 0;
    while (l <= r) {
        if (time1 <= time2) {
            cnt1++;
            time1 += a[l++];
        } else {
            cnt2++;
            time2 += a[r--];
        }
    }
    cout << cnt1 << ' ' << cnt2;
}