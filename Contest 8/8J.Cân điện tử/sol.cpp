#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
int parent[MAXN], dist[MAXN]; // parent: cha của đỉnh, dist: khoảng cách tới cha

// Tìm gốc của đỉnh u, đồng thời thực hiện path compression
int find(int u) {
    if (u == parent[u]) return u;
    int root = find(parent[u]);
    dist[u] += dist[parent[u]]; // Cập nhật khoảng cách
    return parent[u] = root;
}

// Hợp nhất 2 tập hợp chứa u và v
void union_sets(int u, int v, int d) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        parent[root_v] = root_u;
        dist[root_v] = dist[u] - dist[v] + d; // Cập nhật khoảng cách tương đối
    }
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int N, M;
		cin >> N >> M;

		// Khởi tạo DSU
		for (int i = 1; i <= N; ++i) {
			parent[i] = i;
			dist[i] = 0;
		}

		for (int i = 0; i < M; ++i) {
			char type;
			cin >> type;
			if (type == '!') {
				int u, v, d;
				cin >> u >> v >> d;
				if (find(u) == find(v)) {
					// Kiểm tra xem có mâu thuẫn không
					if (dist[v] - dist[u] != d) {
						cout << "Mâu thuẫn" << endl;
					}
				} else {
					union_sets(u, v, d);
				}
			} else {
				int u, v;
				cin >> u >> v;
				if (find(u) == find(v)) {
					cout << dist[v] - dist[u] << endl;
				} else {
					cout << "UNKNOWN" << endl;
				}
			}
		}
	}
    return 0;
}
