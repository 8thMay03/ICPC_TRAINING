/*
    Author: kamine
    Created: 2024-09-01 08:37:42
*/
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

vector<vector<int>> C(101, vector<int>(101));

void init() {
    for (int i = 0; i <= 100; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = 1LL * res * a % mod;
        }
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    init();
    long long ans = 0;
    int x = power(2, even);
    // Để tổng chẵn thì cần chọn (2t) số lẻ kết hợp với tất cả các tập con của số chẵn
    if (k == 0) {
        for (int i = 0; i <= odd; i += 2) {
            ans = (ans + 1LL * C[odd][i] * x) % mod;
        }
    } else { // Để tổng lẻ thì cần chọn (2t + 1) số lẻ kết hợp với tất cả các tập con của số chẵn
        for (int i = 1; i <= odd; i += 2) {
            ans = (ans + 1LL * C[odd][i] * x) % mod;
        }
    }
    cout << ans << '\n';
}