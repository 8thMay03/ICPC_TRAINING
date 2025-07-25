#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

void compress(vector<vector<int>>& a) {
    vector<int> vals;
    for (const auto& row : a) {
        for (int val : row) {
            vals.push_back(val);
        }
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < (int)vals.size(); ++i) {
        mp[vals[i]] = i;
    }
    for (auto& row : a) {
        for (auto& val : row) {
            val = mp[val];
        }
    }
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (4));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }
    compress(a);
    int max_x = INT_MIN, max_y = INT_MIN, min_x = INT_MAX, min_y = INT_MAX;
    map<pair<pii, pii>, int> blocked;
    for (int i = 0; i < n; i++) {
        int xa = a[i][0], ya = a[i][1], xb = a[i][2], yb = a[i][3];
        max_x = max({max_x, xa, xb});
        min_x = min({min_x, xa, xb});
        max_y = max({max_y, ya, yb});
        min_y = min({min_y, ya, yb});
        for (int x = xa; x < xb; x++) {
            if (ya > 0) {
                blocked[{{x, ya}, {x, ya - 1}}] = 1;
                blocked[{{x, ya - 1}, {x, ya}}] = 1;
            }
            if (yb > 0) {
                blocked[{{x, yb}, {x, yb - 1}}] = 1;
                blocked[{{x, yb - 1}, {x, yb}}] = 1;
            }
        }
        for (int y = ya - 1; y >= yb; y--) {
            if (xa > 0) {
                blocked[{{xa, y}, {xa - 1, y}}] = 1;
                blocked[{{xa - 1, y}, {xa, y}}] = 1;
            }
            if (xb > 0) {
                blocked[{{xb, y}, {xb - 1, y}}] = 1;
                blocked[{{xb - 1, y}, {xb, y}}] = 1;
            }
        }
    }
    // cerr << max_x << ' ' << min_x << ' ' << max_y << ' ' << min_y << endl;
    int ans = 0;
    vector<vector<bool>> vis(max_x + 1, vector<bool> (max_y + 1, false));
    for (int i = 0; i <= max_x; i++) {
        for (int j = 0; j <= max_y; j++) {
            if (!vis[i][j]) {
                // cerr << "-----------------------------" << endl;
                // cerr << i << ' ' << j << endl;
                ans++;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                vis[i][j] = true;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx <= max_x && ny >= 0 && ny <= max_y && !vis[nx][ny] && !blocked[{{x, y}, {nx, ny}}]) {
                            // cerr << nx << ' ' << ny << endl;
                            q.emplace(nx, ny);
                            vis[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
