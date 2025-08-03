/*
    Author: kamine
    Created: 2024-09-23 21:36:22
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt25 = 0, cnt50 = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 100) {
            if (cnt50 && cnt25) {
                cnt50--;
                cnt25--;
            } else if (cnt25 >= 3) {
                cnt25 -= 3;
            } else {
                flag = false;
            }
        } else if (x == 50) {
            if (cnt25) {
                cnt25--;
            } else {
                flag = false;
            }
            cnt50++;
        } else {
            cnt25++;
        }
    }
    cout << (flag ? "YES" : "NO");
}