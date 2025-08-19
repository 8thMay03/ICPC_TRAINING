/*
    Author: kamine
    Created: 2025-08-10 08:08:21
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());
    int ans = 0, left = 0, right = n - 1;
    while (left <= right) {
        int sum = a[left] + a[right];
        if (sum <= c) {
            ans++;
            left++, right--;
        } else {
            ans++;
            right--;
        }
    }

    cout << ans;
}