/*
    Created by kamine
*/
#include <bits/stdc++.h>

using namespace std;

bool is_lucky(int n) {
    while (n) {
        if (n % 10 != 4 && n % 10 != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

// Count the number of connected components in the graph without lucky edges
// For each node in a connected component, the number of ways to choose 2 nodes in the same connected component is (s * (s - 1)) / 2 

int n;
vector<bool> vis(100005, false);
vector<vector<int>> adj(100005);
map<pair<int, int>, int> lucky;

int dfs(int u) {
    vis[u] = true;
    int res = 1;
    for (int v : adj[u]) {
        if (!vis[v] && !lucky[{u, v}] && !lucky[{v, u}]) {
            res += dfs(v);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (is_lucky(w)) {
            lucky[{u, v}] = 1;
            lucky[{v, u}] = 1;
        }
    }
    vector<int> sz;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            sz.push_back(dfs(i));
        }
    }
    long long ans = 0;
    for (int s : sz) {
        int cnt = n - s;
        ans += 1LL * s * cnt * (cnt - 1);
    }
    cout << ans << '\n';
}