/*
    Author: kamine
    Created: 2025-08-10 08:04:08
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int k;
    cin >> k;

    sort(s.begin(), s.end());
    int cur = 1;
    while (cur < k && next_permutation(s.begin(), s.end())) {
        cur++;
    }

    cout << s;
}