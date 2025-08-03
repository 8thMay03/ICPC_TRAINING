#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    multiset<int> ends;
    for (int i = 0; i < n; ++i) {
        auto it = ends.lower_bound(a[i]);
        if (it != ends.begin()) {
            --it; // tìm phần tử < A[i] lớn nhất
            ends.erase(it);
        }
        ends.insert(a[i]);
    }
    cout << ends.size() << '\n';
}
