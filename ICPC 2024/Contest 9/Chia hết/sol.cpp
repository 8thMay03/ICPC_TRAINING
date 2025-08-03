/*
    Author: kamine
    Created: 2024-09-21 18:19:09
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cur = 0;
    while (cur < n) {
        bool flag = false;
        for (int i = cur + 1; i < n; i++) {
            if (a[i] % a[cur] == 0) {
                cout << a[i] << endl;
                cur = i + 1;
                flag = true;
                break;
            }
        }
        if (!flag) break;
    }
}