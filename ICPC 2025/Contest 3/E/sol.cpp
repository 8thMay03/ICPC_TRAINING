/*
    Author: kamine
    Created: 2025-08-10 13:07:45
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t x, y;
    cin >> x >> y;

    int64_t d = llabs(x - y);
    if (d <= 1) cout << "Bob";
    else cout << "Alice";
}