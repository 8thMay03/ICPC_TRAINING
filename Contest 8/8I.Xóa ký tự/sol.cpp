/*
	Author: kamine
	Created: 2024-09-08 09:34:57
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	stack<char> st;
	for (char c : s) {
        if (!st.empty() && st.top() != c) {
            st.pop(); 
        } else {
            st.push(c);
        }
    }
	cout << n - st.size() << '\n';
}