/*
    Author: kamine
    Created: 2024-09-04 17:07:55
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (i * 4 + j * 7 == n) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}