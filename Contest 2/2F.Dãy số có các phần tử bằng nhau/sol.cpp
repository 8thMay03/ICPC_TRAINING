/*
    Author: kamine
    Created: 2024-09-05 07:18:25
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int pos = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            pos = i;
        }
    }
    // Đếm số lượng phần từ ở bên trái và bên phải của phần tử 1
    int left = pos, right = n - 1 - pos;
    int ans = 0;
    // Mỗi lần ta sẽ được biến đổi k - 1 phần tử
    ans += ceil(1.0 * left / (k - 1));
    if (left % (k - 1) != 0) {
        right -= (k - 1) - left % (k - 1);
    }
    ans += ceil(1.0 * right / (k - 1));
    cout << ans << '\n';
}