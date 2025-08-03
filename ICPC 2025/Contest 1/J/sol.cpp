#include <bits/stdc++.h>

#define int long long

using namespace std;

const int INF = 1e18;

struct SegmentTree {
    vector<int> tree;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, INF);
    }

    void update(int idx, int val, int node = 0, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (l == r) {
            tree[node] = min(tree[node], val);
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, node * 2 + 1, l, mid);
        else
            update(idx, val, node * 2 + 2, mid + 1, r);
        tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
    }

    int query(int ql, int qr, int node = 0, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (ql > qr) return INF;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        int left_res = INF, right_res = INF;
        if (ql <= mid)
            left_res = query(ql, qr, node * 2 + 1, l, mid);
        if (qr > mid)
            right_res = query(ql, qr, node * 2 + 2, mid + 1, r);
        return min(left_res, right_res);
    }
};

struct Island {
    int h, p;
    int id;
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Island> islands(n);
    for (int i = 0; i < n; i++) {
        cin >> islands[i].h >> islands[i].p;
    }
    Island start = islands[0];
    sort(islands.begin(), islands.end(), [](const Island& a, const Island& b) {
        return a.h < b.h;
    });
    int start_index = -1;
    for (int i = 0; i < n; i++) {
        if (islands[i].h == start.h && islands[i].p == start.p) {
            start_index = i;
            break;
        }
    }
    int base_cost = 0;
    for (int i = 0; i < n; i++) {
        base_cost += islands[i].p;
    }

    // Left part: islands with index < start_index
    int M_left = -1;
    vector<Island> left_islands;
    for (int i = 0; i < start_index; i++) {
        left_islands.push_back(islands[i]);
        M_left = max(M_left, islands[i].h + islands[i].p);
    }

    // Right part: islands with index >= start_index
    vector<Island> right_islands;
    for (int i = start_index; i < n; i++) {
        right_islands.push_back(islands[i]);
    }
    int m_right = right_islands.size();

    // Case 1: no islands in right part
    if (m_right == 0) {
        int add_cost = max(0LL, start.h - M_left);
        cout << base_cost + add_cost << endl;
        return 0;
    }

    // DP for right part (forward)
    vector<int> dp_forward(m_right, INF);
    if (m_right > 0) {
        vector<int> aint_x;
        for (int i = 0; i < m_right; i++) {
            aint_x.push_back(right_islands[i].h);
            aint_x.push_back(right_islands[i].h + right_islands[i].p);
        }
        sort(aint_x.begin(), aint_x.end());
        aint_x.erase(unique(aint_x.begin(), aint_x.end()), aint_x.end());
        int m = aint_x.size();

        auto get_idx = [&](int x) {
            return lower_bound(aint_x.begin(), aint_x.end(), x) - aint_x.begin();
        };

        SegmentTree tree1(m), tree2(m);
        dp_forward[0] = 0;
        int pos0 = get_idx(right_islands[0].h + right_islands[0].p);
        tree1.update(pos0, 0);
        tree2.update(pos0, 0 - (right_islands[0].h + right_islands[0].p));

        for (int i = 1; i < m_right; i++) {
            int h_i = right_islands[i].h;
            int L1 = get_idx(h_i);
            int option1 = tree1.query(L1, m - 1);

            int R2 = h_i - 1;
            int R2_idx = upper_bound(aint_x.begin(), aint_x.end(), R2) - aint_x.begin() - 1;
            int option2 = INF;
            if (R2_idx >= 0) {
                option2 = tree2.query(0, R2_idx) + h_i;
            }

            dp_forward[i] = min(option1, option2);

            int pos = get_idx(right_islands[i].h + right_islands[i].p);
            tree1.update(pos, dp_forward[i]);
            tree2.update(pos, dp_forward[i] - (right_islands[i].h + right_islands[i].p));
        }
    }

    // Backward DP for right part (excluding start island)
    vector<int> dp_back;
    if (m_right > 1) {
        vector<Island> right_back;
        for (int i = 1; i < m_right; i++) {
            right_back.push_back(right_islands[i]);
        }
        int m_back = right_back.size();

        vector<int> aint_x;
        for (int i = 0; i < m_back; i++) {
            aint_x.push_back(right_back[i].h);
            aint_x.push_back(right_back[i].h + right_back[i].p);
        }
        sort(aint_x.begin(), aint_x.end());
        aint_x.erase(unique(aint_x.begin(), aint_x.end()), aint_x.end());
        int m = aint_x.size();

        auto get_idx = [&](int x) {
            return lower_bound(aint_x.begin(), aint_x.end(), x) - aint_x.begin();
        };

        SegmentTree tree1(m), tree2(m);
        dp_back.assign(m_back, INF);
        for (int i = m_back - 1; i >= 0; i--) {
            if (i == m_back - 1) {
                dp_back[i] = 0;
            } else {
                int L1 = get_idx(right_back[i].h + right_back[i].p);
                int option1 = tree1.query(0, L1);

                int R2 = right_back[i].h + right_back[i].p;
                int R2_idx = upper_bound(aint_x.begin(), aint_x.end(), R2) - aint_x.begin();
                int option2 = INF;
                if (R2_idx < m) {
                    option2 = tree2.query(R2_idx, m - 1) - (right_back[i].h + right_back[i].p);
                }
                dp_back[i] = min(option1, option2);
            }

            int pos = get_idx(right_back[i].h);
            tree1.update(pos, dp_back[i]);
            tree2.update(pos, dp_back[i] + right_back[i].h);
        }
    }

    // Calculate additional cost
    int add_cost = 0;
    if (left_islands.empty()) {
        add_cost = dp_forward[m_right - 1];
    } else {
        int option1 = dp_forward[m_right - 1] + max(0LL, start.h - M_left);
        int option2 = INF;
        if (m_right > 1) {
            for (int i = 0; i < (int)dp_back.size(); i++) {
                int cost_bridge = max(0LL, right_islands[i + 1].h - M_left);
                option2 = min(option2, cost_bridge + dp_back[i]);
            }
        } else {
            option2 = INF;
        }
        add_cost = min(option1, option2);
    }

    cout << base_cost + add_cost << endl;

    return 0;
}