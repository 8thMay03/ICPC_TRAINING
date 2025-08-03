/*
    Author: kamine
    Created: 2024-09-04 22:02:10
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<double> st;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            cout << -1;
            return 0;
        }
        if (a == 0 && b == 0) continue;
        if (a == 0) {
            if (b != 0) st.insert(-1.0 * c / b);
        } else {
            int tmp = a;
            tmp = __gcd(tmp, b);
            tmp = __gcd(tmp, c);
            a /= tmp; b /= tmp; c /= tmp;
            int delta = b * b - 4 * a * c;
            if (delta < 0) continue;
            if (delta == 0) {
                st.insert(-1.0 * b / (2 * a));
                continue;
            }
            st.insert((-1.0 * b - sqrt(delta)) / (2 * a));
            st.insert((-1.0 * b + sqrt(delta)) / (2 * a));
        }
    }
    cout << st.size() << '\n';
}