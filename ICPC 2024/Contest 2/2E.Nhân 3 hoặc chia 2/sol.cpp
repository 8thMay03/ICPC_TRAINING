/*
    Author: kamine
    Created: 2024-09-04 15:40:40
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x % 2 == 0) {
            x /= 2;
            ans++;
        }
    }
    cout << ans << '\n';
}