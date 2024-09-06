/*
    Author: kamine
    Created: 2024-09-04 12:16:48
*/
#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
vector<bool> col(15, false), diag1(30, false), diag2(30, false);

void Try(int row) {
    for (int i = 1; i <= n; i++) {
        if (!col[i] && !diag1[row + i] && !diag2[row - i + n]) {
            col[i] = diag1[row + i] = diag2[row - i + n] = true;
            if (row == n) {
                cnt++;
            }
            else if (row < n) {
                Try(row + 1);
            }
            col[i] = diag1[row + i] = diag2[row - i + n] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Try(1);
    cout << cnt << '\n';
}