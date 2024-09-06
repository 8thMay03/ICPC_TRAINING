/*
    Created by kamine
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    long long ans = 0; // Number of pairs of students that are compatible
    for (int i = 0; i < n; i++) {
        vector<int> a(5);
        for (int j = 0; j < 5; j++) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        // Generate all possible subsets of a
        for (int mask = 1; mask < (1 << 5); mask++) {
            string s = "";
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                if (mask & (1 << j)) {
                    s += to_string(a[j]) + "!";
                    cnt++;
                }
            }
            // If the subset appeared before, it means that we found a pair of students that are compatible with the same favorite food
            // Add the number of pairs of students that are compatible to ans.
            // But it can be counted more than one time. 
            // When we find a pair of students that are compatible with "x" favorite food, then that pair have 2^x-1 same favorite subsets, it is an odd.
            // So we just need to add when cnt is odd and subtract when cnt is even.
            if (cnt & 1) {
                ans += mp[s];
            } else {
                ans -= mp[s];
            }
            mp[s]++;
        }
    }
    ans = (1LL * n * (n - 1)) / 2 - ans;
    cout << ans << '\n';
    return 0;
}