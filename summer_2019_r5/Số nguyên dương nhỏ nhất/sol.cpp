/*
	Author: kamine
	Created: 2024-09-08 20:42:27
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (k == 0) {
		if (1 < a[0]) {
			cout << 1;
		} else {
			cout << -1;
		}
		return 0;
	}
	if (k == n) {
		cout << a[n - 1] << '\n';
		return 0;
	}
	if (k > 2 && a[k - 1] == a[k - 2]) {
		cout << -1 << '\n';
		return 0;
	}
	if (k < n && a[k] == a[k - 1]) {
		cout << -1 << '\n';
		return 0;
	}
	cout << a[k - 1] << '\n';
}