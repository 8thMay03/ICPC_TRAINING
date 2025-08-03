#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

struct Node {
    int len;        // chiều dài đoạn
    int max_free;   // đoạn liên tiếp lớn nhất các ghế trống
    int prefix;     // số ghế trống từ đầu đoạn
    int suffix;     // số ghế trống từ cuối đoạn
    int lazy = -1;  // -1: không gì, 0: làm trống, 1: đặt người
} seg[4 * MAXN];

int N, M, refused = 0;

void apply(int id, int val) {
    seg[id].lazy = val;
    if (val == 0) {
        seg[id].max_free = seg[id].prefix = seg[id].suffix = seg[id].len;
    } else {
        seg[id].max_free = seg[id].prefix = seg[id].suffix = 0;
    }
}

void push(int id) {
    if (seg[id].lazy != -1) {
        apply(id << 1, seg[id].lazy);
        apply(id << 1 | 1, seg[id].lazy);
        seg[id].lazy = -1;
    }
}

void pull(int id) {
    seg[id].prefix = seg[id << 1].prefix;
    if (seg[id << 1].prefix == seg[id << 1].len)
        seg[id].prefix += seg[id << 1 | 1].prefix;

    seg[id].suffix = seg[id << 1 | 1].suffix;
    if (seg[id << 1 | 1].suffix == seg[id << 1 | 1].len)
        seg[id].suffix += seg[id << 1].suffix;

    seg[id].max_free = max({seg[id << 1].max_free, seg[id << 1 | 1].max_free,
                            seg[id << 1].suffix + seg[id << 1 | 1].prefix});
}

void build(int id, int l, int r) {
    seg[id].len = r - l + 1;
    seg[id].max_free = seg[id].prefix = seg[id].suffix = seg[id].len;
    seg[id].lazy = -1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        apply(id, val);
        return;
    }
    push(id);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    pull(id);
}

int query(int id, int l, int r, int k) {
    if (seg[id].max_free < k) return -1;
    if (l == r) return l;
    push(id);
    int mid = (l + r) >> 1;
    if (seg[id << 1].max_free >= k)
        return query(id << 1, l, mid, k);
    if (seg[id << 1].suffix + seg[id << 1 | 1].prefix >= k)
        return mid - seg[id << 1].suffix + 1;
    return query(id << 1 | 1, mid + 1, r, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    build(1, 1, N);

    for (int i = 0; i < M; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "A") {
            int k;
            cin >> k;
            int pos = query(1, 1, N, k);
            if (pos == -1) refused++;
            else update(1, 1, N, pos, pos + k - 1, 1);
        } else {
            int a, b;
            cin >> a >> b;
            update(1, 1, N, a, b, 0);
        }
    }
    cout << refused << '\n';
    return 0;
}
