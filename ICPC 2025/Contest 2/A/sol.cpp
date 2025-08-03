/*
    Author: kamine
    Created: 2025-08-03 08:00:22
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i];
    }
    if (sum > a[n - 1]) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}