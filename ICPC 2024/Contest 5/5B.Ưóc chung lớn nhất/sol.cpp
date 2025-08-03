/*
    Author: kamine
    Created: 2024-09-05 08:37:23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int tmp = m / n;
    while (tmp) {
        if (m % tmp == 0) {
            cout << tmp << '\n';
            return 0;
        }
        tmp--;
    }
}