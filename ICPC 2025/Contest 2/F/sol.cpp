#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_CAP = 100 * 100 + 5; // max total capacity
int dp[105][MAX_CAP]; // dp[k][c] = max soda with k bottles and total capacity c

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    int total_soda = 0;

    for (int &x : A) {
        cin >> x;
        total_soda += x;
    }
    for (int &x : B) cin >> x;

    // Khởi tạo dp
    for (int i = 0; i <= n; ++i)
        fill(dp[i], dp[i] + MAX_CAP, -INF);
    dp[0][0] = 0;

    // DP
    for (int i = 0; i < n; ++i) {
        for (int k = i; k >= 0; --k) {
            for (int c = MAX_CAP - 1 - B[i]; c >= 0; --c) {
                if (dp[k][c] != -INF) {
                    int new_c = c + B[i];
                    int new_soda = dp[k][c] + A[i];
                    dp[k+1][new_c] = max(dp[k+1][new_c], new_soda);
                }
            }
        }
    }

    // Tìm K nhỏ nhất và T nhỏ nhất
    int ans_K = n + 1, ans_T = INF;
    for (int k = 1; k <= n; ++k) {
        for (int c = total_soda; c < MAX_CAP; ++c) {
            if (dp[k][c] != -INF) {
                int T = total_soda - dp[k][c];
                if (k < ans_K || (k == ans_K && T < ans_T)) {
                    ans_K = k;
                    ans_T = T;
                }
            }
        }
    }

    cout << ans_K << ' ' << ans_T << '\n';
    return 0;
}
