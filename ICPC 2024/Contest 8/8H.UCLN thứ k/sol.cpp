/*
	Author: kamine
	Created: 2024-09-08 08:32:17
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, k;
	cin >> a >> b >> k;
	vector<int> v;
	for (int i = 1; i <= min(a, b); i++) {
		if (a % i == 0 && b % i == 0) {
			v.push_back(i);
		}
	}
	cout << v[v.size() - k] << '\n';
}