#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<vector<int>> st;

    SegmentTree(int n) : n(n) {
        st.resize(4 * n);
    }

    void build(vector<int> &a, int id, int l, int r) {
        if (l == r) {
            st[id] = {a[l]};
            return;
        }
        int m = (l + r) / 2;
        build(a, id * 2, l, m);
        build(a, id * 2 + 1, m + 1, r);
        st[id].resize(st[id * 2].size() + st[id * 2 + 1].size());
        merge(st[id * 2].begin(), st[id * 2].end(),
              st[id * 2 + 1].begin(), st[id * 2 + 1].end(),
              st[id].begin());
    }

    void update(int id, int l, int r, int pos, int oldVal, int newVal) {
        // xóa oldVal và chèn newVal
        auto it = lower_bound(st[id].begin(), st[id].end(), oldVal);
        if (it != st[id].end() && *it == oldVal) st[id].erase(it);
        st[id].insert(lower_bound(st[id].begin(), st[id].end(), newVal), newVal);

        if (l == r) return;
        int m = (l + r) / 2;
        if (pos <= m) update(id * 2, l, m, pos, oldVal, newVal);
        else update(id * 2 + 1, m + 1, r, pos, oldVal, newVal);
    }

    int query(int id, int l, int r, int u, int v, int X) {
        if (r < u || v < l) return INT_MAX;
        if (u <= l && r <= v) {
            auto it = upper_bound(st[id].begin(), st[id].end(), X);
            if (it == st[id].end()) return INT_MAX;
            return *it;
        }
        int m = (l + r) / 2;
        return min(query(id * 2, l, m, u, v, X),
                   query(id * 2 + 1, m + 1, r, u, v, X));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];

    SegmentTree tree(N);
    tree.build(a, 1, 1, N);

    while (M--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, val;
            cin >> u >> val;
            tree.update(1, 1, N, u, a[u], val);
            a[u] = val;
        } else {
            int u, v, X;
            cin >> u >> v >> X;
            int ans = tree.query(1, 1, N, u, v, X);
            if (ans == INT_MAX) cout << -1 << "\n";
            else cout << ans << "\n";
        }
    }
}
