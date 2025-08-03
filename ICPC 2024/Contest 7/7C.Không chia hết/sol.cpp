/*
    Author: kamine
    Created: 2024-09-01 09:24:01
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }    
    int ans = 0;
    // Xét các số từ nhỏ đến lớn, từ các số đó, xóa toàn bộ các số chia hết cho nó ra khỏi map;
    for (auto [k, v] : mp) {
        ans += (v == 1);
        for (int i = k * 2; i <= 1e6; i += k) {
            mp.erase(i);
        }
    }
    // Đếm số lượng còn lại trong map, những số này ko chia hết cho bất kỳ số nào trong map (loại bỏ trường hợp có 2 số giống nhau thì ta chỉ lấy số xuất hiện 1 lần)
    cout << ans << '\n';
}