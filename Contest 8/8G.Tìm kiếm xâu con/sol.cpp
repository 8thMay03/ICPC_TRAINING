/*
	Author: kamine
	Created: 2024-09-08 08:37:42
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();
	for (int i = 0; i + m - 1 < n; i++) {
		if (s1.substr(i, m) == s2) {
			cout << i + 1 << ' ';
		}
	}
}