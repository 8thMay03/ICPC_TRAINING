/*
    Author: kamine
    Created: 2024-09-06 21:20:30
*/
#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;   
    int ans = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (is_prime(i) && is_prime(n - i)) {
            ans++;
        }
    }
    cout << ans << '\n';
}