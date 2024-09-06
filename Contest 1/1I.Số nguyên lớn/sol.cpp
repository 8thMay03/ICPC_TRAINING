/*
    Author: kamine
    Created: 2024-09-04 12:30:54
*/
#include <bits/stdc++.h>

using namespace std;

bool check(string s) {
    if (s.size() > 18 || s.size() < 10) {
        return false;
    }
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    long long sum = 0;
    while (cin >> s) {
        if (check(s)) {
            sum += stoll(s);
        }
    }
    cout << sum << '\n';
}