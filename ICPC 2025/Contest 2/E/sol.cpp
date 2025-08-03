#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
const int MAXN = 200000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<ll> pow2(MAXN + 10);
    pow2[0] = 1;
    for (int i = 1; i <= MAXN + 5; i++) {
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }

    int T;
    cin >> T;
    while (T--) {
        int N;
        ll K;
        cin >> N >> K;
        vector<ll> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        if (N == 0) {
            cout << 0 << '\n';
            continue;
        }

        vector<pair<ll, ll>> B;
        for (ll a : A) {
            ll r = a % K;
            ll t = (a - r) / K;
            B.push_back({r, t});
        }
        sort(B.begin(), B.end());

        vector<tuple<ll, ll, int>> agg;
        ll cur_r = B[0].first;
        ll cur_t = B[0].second;
        int count = 1;
        for (int i = 1; i < B.size(); i++) {
            if (B[i].first == cur_r && B[i].second == cur_t) {
                count++;
            } else {
                agg.push_back(make_tuple(cur_r, cur_t, count));
                cur_r = B[i].first;
                cur_t = B[i].second;
                count = 1;
            }
        }
        agg.push_back(make_tuple(cur_r, cur_t, count));

        vector<vector<pair<ll, int>>> residue_groups;
        if (agg.size() > 0) {
            vector<pair<ll, int>> temp;
            ll current_r = get<0>(agg[0]);
            temp.push_back({get<1>(agg[0]), get<2>(agg[0])});
            for (int i = 1; i < agg.size(); i++) {
                if (get<0>(agg[i]) == current_r) {
                    temp.push_back({get<1>(agg[i]), get<2>(agg[i])});
                } else {
                    residue_groups.push_back(temp);
                    temp.clear();
                    current_r = get<0>(agg[i]);
                    temp.push_back({get<1>(agg[i]), get<2>(agg[i])});
                }
            }
            residue_groups.push_back(temp);
        }

        ll total_ways = 1;
        for (auto &arr : residue_groups) {
            ll dp0 = 1;
            ll dp1 = 0;
            ll prev_t = -1;
            for (int i = 0; i < arr.size(); i++) {
                ll t_val = arr[i].first;
                int cnt = arr[i].second;
                ll ways_here = (pow2[cnt] - 1 + mod) % mod;

                if (i == 0) {
                    dp0 = 1;
                    dp1 = ways_here;
                } else {
                    if (t_val == prev_t + 1) {
                        ll new_dp0 = (dp0 + dp1) % mod;
                        ll new_dp1 = (dp0 * ways_here) % mod;
                        dp0 = new_dp0;
                        dp1 = new_dp1;
                    } else {
                        ll new_dp0 = (dp0 + dp1) % mod;
                        ll new_dp1 = (new_dp0 * ways_here) % mod;
                        dp0 = new_dp0;
                        dp1 = new_dp1;
                    }
                }
                prev_t = t_val;
            }
            ll ways_this = (dp0 + dp1) % mod;
            total_ways = (total_ways * ways_this) % mod;
        }

        ll ans = (total_ways - 1 + mod) % mod;
        cout << ans << '\n';
    }
    return 0;
}

// ### Giải thích cách làm bằng tiếng Việt

// **Bài toán:**  
// Cho một mảng A[] gồm N phần tử và một số nguyên dương K. Yêu cầu đếm số dãy con khác rỗng trong A[] sao cho không có hai phần tử nào trong dãy con có giá trị tuyệt đối hiệu bằng K. Kết quả cần được in ra với modulo 998244353.

// **Cách tiếp cận:**

// 1. **Nhóm các phần tử theo modulo K:**  
//    - Hai phần tử a và b sẽ có |a - b| = K nếu chúng cùng nhóm khi chia dư cho K. Ví dụ, nếu a ≡ r mod K và b ≡ r mod K, thì |a - b| sẽ là bội của K. Do đó, ta nhóm các phần tử theo phần dư khi chia cho K.

// 2. **Biểu diễn phần tử trong từng nhóm:**  
//    - Mỗi phần tử a trong nhóm r có thể viết dưới dạng a = r + t*K, với t là số nguyên không âm. Việc này giúp chúng ta chuyển bài toán về xử lý các giá trị t trong từng nhóm r.

// 3. **Quy hoạch động trong từng nhóm:**  
//    - Với mỗi nhóm r, ta sắp xếp các giá trị t. Bài toán giờ trở thành chọn các phần tử sao cho không có hai phần tử liên tiếp (vì |t_i - t_j| = 1 sẽ tương ứng với |a_i - a_j| = K).
//    - Sử dụng quy hoạch động:
//      - `dp0`: Số cách tạo dãy con đến phần tử hiện tại mà không chọn phần tử đó.
//      - `dp1`: Số cách tạo dãy con đến phần tử hiện tại mà có chọn phần tử đó.
//      - Nếu t hiện tại bằng t trước đó cộng 1, ta không thể chọn cả hai, nên `dp1` được cập nhật từ `dp0` của bước trước.
//      - Ngược lại, ta có thể chọn phần tử hiện tại bất kể trạng thái trước đó.
//      - Số cách chọn phần tử hiện tại là \(2^{\text{số lượng}} - 1\) (tất cả tập con khác rỗng của các phần tử giống nhau).

// 4. **Tính kết quả cuối cùng:**  
//    - Tổng số dãy con hợp lệ (bao gồm dãy rỗng) là tích của kết quả từ tất cả các nhóm.
//    - Kết quả cuối cùng là tổng này trừ đi 1 (loại bỏ dãy rỗng) và lấy modulo 998244353.

// **Giải thích chi tiết từng bước:**

// 1. **Tiền xử lý:**  
//    - Tính trước các lũy thừa của 2 modulo 998244353 để sử dụng khi tính số tập con khác rỗng của các phần tử giống nhau.

// 2. **Nhóm các phần tử:**  
//    - Mỗi phần tử a được biểu diễn thành (r, t), với r = a % K và t = (a - r) / K.
//    - Sắp xếp các cặp (r, t) và gộp các phần tử có cùng r và t lại để đếm số lượng.

// 3. **Xử lý từng nhóm r:**  
//    - Với mỗi nhóm r, sắp xếp các giá trị t.
//    - Sử dụng quy hoạch động để tính số dãy con hợp lệ:
//      - Khởi tạo `dp0 = 1` (không chọn phần tử nào) và `dp1` là số cách chọn phần tử đầu tiên.
//      - Duyệt qua các phần tử tiếp theo:
//        - Nếu t hiện tại bằng t trước đó + 1, không thể chọn cả hai, nên `dp1` mới = `dp0` cũ * số cách chọn phần tử hiện tại.
//        - Ngược lại, `dp1` mới = (`dp0` + `dp1`) * số cách chọn phần tử hiện tại.
//      - Cập nhật `dp0` và `dp1` sau mỗi bước.

// 4. **Tính toán kết quả:**  
//    - Tích các kết quả từ tất cả các nhóm r.
//    - Trừ đi 1 để loại dãy rỗng và lấy modulo.

// **Ví dụ minh họa:**

// Xét test ví dụ 3:
// - Input: N=4, K=2, A=[2,4,7,9]
// - Các phần tử được nhóm theo r:
//   - r=0: t=1 (2), t=2 (4)
//   - r=1: t=3 (7), t=4 (9)
// - Với nhóm r=0:
//   - t=1: có 1 phần tử → số cách chọn: 1
//   - t=2: có 1 phần tử → số cách chọn: 1
//   - Không có t liên tiếp nên tổng cách: (1 + 1) + (1 * 1) = 3 (bao gồm dãy rỗng)
// - Với nhóm r=1:
//   - Tương tự, tổng cách: 3
// - Tích các nhóm: 3 * 3 = 9
// - Trừ dãy rỗng: 9 - 1 = 8
// - Kết quả: 8

// **Kết luận:**  
// Cách tiếp cận này hiệu quả bằng việc nhóm các phần tử và sử dụng quy hoạch động để đếm số dãy con hợp lệ, đảm bảo không có hai phần tử nào có hiệu đúng bằng K.