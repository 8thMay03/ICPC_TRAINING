/*
    Author: kamine
    Created: 2024-09-21 18:19:09
*/
#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

int n, m, up, down, l, r;
vector<bool> vis;
vector<vector<int>> adj;
vector<Point> a;


void dfs(int u) {
    vis[u] = true;
    up = max(up, a[u].y);
    down = min(down, a[u].y);
    l = min(l, a[u].x);
    r = max(r, a[u].x);
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n + 1, {});
    vis.resize(n + 1, false);
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            up = -1e9, down = 1e9, l = 1e9, r = -1e9;
            dfs(i);
            ans = min((up - down) * 2 + (r - l) * 2, ans);
        }
    }
    cout << ans << endl;
}