#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int64_t a;
    cin >> a;
    
    for (int64_t b = 1; b <= 100000; b++) {
        if (b == a) continue;
        int64_t c2 = 2 * a * a - b * b;
        if (c2 <= 0) continue;
        int64_t c = sqrt(c2);
        if (c * c != c2) continue;  
        if (c == a || c == b) continue;
        if (c > 100000) continue;
        cout << "YES";
        return 0;
    }
    cout << "NO";
}
