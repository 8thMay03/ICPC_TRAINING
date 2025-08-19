#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 20;

struct State {
    int a, b, c;
    bool operator < (const State &o) const {
        if (a != o.a)
            return a < o.a;
        if (b != o.b)
            return b < o.b;
        return c < o.c;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    map<State, int> dp, ndp;

    for (int x = 1; x <= M; x++) {
        dp[{x, INF, INF}] = 1;
    }

    for (int i = 1; i < N; i++) {
        ndp.clear();
        for (auto [st, val] : dp) {
            int a = st.a, b = st.b, c = st.c;
            for (int x = 1; x <= M; x++) {
                if (x <= a) {
                    State ns = {x, b, c};
                    (ndp[ns] += val) %= MOD;
                }
                else if (x <= b) {
                    State ns = {a, x, c};
                    (ndp[ns] += val) %= MOD;
                }
                else if (x <= c) {
                    State ns = {a, b, x};
                    (ndp[ns] += val) %= MOD;
                }
            }
        }
        dp.swap(ndp);
    }

    long long ans = 0;
    for (auto [st, val] : dp) {
        if (st.c < INF) { 
            ans = (ans + val) % MOD;
        }
    }
    cout << ans << "\n";
}
