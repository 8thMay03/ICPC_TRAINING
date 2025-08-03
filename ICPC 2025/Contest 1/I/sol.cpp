#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;

// Sàng nguyên tố
vector<int> get_primes(int limit) {
    vector<bool> is_prime(limit + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= limit; j += i)
                is_prime[j] = false;
        }
    }
    return primes;
}

// Đếm số mũ của p trong n!
int count_p_in_factorial(int n, int p) {
    int count = 0;
    while (n > 0) {
        n /= p;
        count += n;
    }
    return count;
}

// Đếm số ước của C(K, N)
long long count(int n, int k, const vector<int>& primes) {
    if (k == 0 || k == n) return 1;
    map<int, int> exponents;
    for (int p : primes) {
        int e = count_p_in_factorial(n, p) - count_p_in_factorial(k, p) - count_p_in_factorial(n - k, p);
        if (e > 0) {
            exponents[p] = e;
        }
    }
    long long result = 1;
    for (auto& it : exponents) {
        result *= (it.second + 1);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> primes = get_primes(MAXN);
    int n, k;
    while (cin >> n >> k) {
        cout << count(n, k, primes) << '\n';
    }
}
