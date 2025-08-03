/*
    Author: kamine
    Created: 2025-08-03 08:53:19
*/
#include <bits/stdc++.h>

using namespace std;

class DSU {
  public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dsu.merge(u, v);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dsu.sz[i]);
    }
    cout << ans;
}