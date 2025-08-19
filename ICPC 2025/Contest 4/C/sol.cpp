#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    auto check = [&](int x, int y, int dx, int dy) {
        int dot = 0;
        for (int k = 0; k < 6; k++) {
            int nx = x + dx * k, ny = y + dy * k;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) return false;
            if (grid[nx][ny] == '.') dot++;
        }
        return dot <= 2;
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (check(i, j, 0, 1) || check(i, j, 1, 0) ||
                check(i, j, 1, 1) || check(i, j, 1, -1)) {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";
    return 0;
}
