/*
    Author: kamine
    Created: 2025-08-10 08:01:10
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, s;
    cin >> k >> s;

    int ans = 0;
    for (int x = 0; x <= k; x++) {
        for (int y = 0; y <= k; y++) {
            int z = s - x - y;
            ans += (z >= 0 && z <= k);
        }
    }

    cout << ans;
}