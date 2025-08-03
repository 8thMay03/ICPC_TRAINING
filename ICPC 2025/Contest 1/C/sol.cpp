#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int l = 0, r = s.size() - 1;
    while (s[l] != 'A') l++;
    while (s[r] != 'Z') r--;
    cout << r - l + 1;
}
