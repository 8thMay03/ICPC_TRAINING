#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // sử dụng set để lưu các đoạn còn trống
    set<pair<int, int>> st;
    st.insert({1, n});
    int res = 0;

    while (q--) {
        char c;
        cin >> c;

        if (c == 'A') {
            int k;
            cin >> k;

            int flag = 1;
            // Duyệt từ nhỏ tới lớn xem có đoạn nào có độ dài >= k
            for (auto [l, r] : st) {
                if (r - l + 1 >= k) {
                    st.erase({l, r});
                    st.insert({l + k, r});
                    flag = 0;
                    break;
                }
            }

            res += flag;
        } else {
            int a, b;
            cin >> a >> b;

            // Khi muốn thêm đoạn [a, b] vào trong set, ta cần kiểm tra xem [a, b] có đè lên đoạn nào trong set, hay là nối tiếp đoạn nào đó trong set
            // Ta sẽ bắt đầu kiểm tra từ đoạn [l, r] mà l < a
            auto it = st.lower_bound({a, 0});
            if (it != st.begin()) --it;

            vector<pair<int, int>> to_merge; // Dùng để lưu các đoạn mà nối tiếp hay bị đè lên bởi a, b. Ta cần xóa tất cả các đoạn này rồi thêm đoạn mới vào sau
            int new_l = a, new_r = b;

            // Điều kiện chỉ xét các đoạn nối tiếp, hoặc đè lên đoạn [a, b]
            while (it != st.end() && it->first <= b + 1) {
                int l = it->first, r = it->second;

                if (r < a - 1) {
                    ++it;
                    continue;
                }

                new_l = min(new_l, l);
                new_r = max(new_r, r);
                to_merge.push_back(*it);
                ++it;
            }

            for (auto &p : to_merge) {
                st.erase(p);
            }

            st.insert({new_l, new_r});
        }
    }

    cout << res;
}