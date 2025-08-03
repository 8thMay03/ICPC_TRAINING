/*
    Author: kamine
    Created: 2025-08-03 08:31:18
*/
#include <bits/stdc++.h>

using namespace std;

int64_t L(int n) {
    if (n == 0) {
        return 2;
    }
    if (n == 1) {
        return 1;
    }
    return L(n - 1) + L(n - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << L(n);
}