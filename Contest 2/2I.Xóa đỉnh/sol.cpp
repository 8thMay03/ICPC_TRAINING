/*
    Created by kamine
*/
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> par(200001), sz(200001), adj[200001];
vector<bool> is_add(200001, false);

void init() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
}

bool connect(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    init();
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int cnt = 0;
    vector<string> ans(n, "NO");
    // Thay vì xóa từng đỉnh ra khỏi đồ thi, ta thêm từng đỉnh vào đồ thi.
    for (int i = n - 1; i >= 0; i--) {
        int u = p[i];
        // Thêm đỉnh u vào đồ thi.
        is_add[u] = true;
        // Mỗi khi thêm 1 đỉnh vào đồ thi, ta tăng số thành phần liên thông lên 1.
        cnt++;
        // Duyệt tất cả các đỉnh kề với đỉnh u.
        for (int v : adj[u]) {
            if (is_add[v]) {
                // Nếu 2 đỉnh u, v đã được thêm vào đồ thi, ta kiểm tra xem chúng có cùng thành phần liên thông không.
                // Nếu cùng thành phần liên thông, ta giảm số thành phần liên thông đi 1, vì là đồ thi nên sẽ không bị kiểm tra với 1 thành phần liên thông 2 lần.
                if (connect(u, v)) {
                    cnt--;
                }
            }
        }
        // Nếu số thành phần liên thông bằng 1, ta gán "YES" cho kết quả.
        if (cnt == 1) {
            ans[i] = "YES";
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}