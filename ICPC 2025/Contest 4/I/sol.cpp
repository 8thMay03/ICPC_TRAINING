#include <bits/stdc++.h>

using namespace std;

long long digit_sum(long long x) {
    long long s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long N;
        int S;
        cin >> N >> S;

        if (digit_sum(N) <= S) {
            cout << 0 << "\n";
            continue;
        }

        long long ans = 0;
        long long power = 1;
        for (int i = 0; i < 19; i++) { // 10^18 có tối đa 19 chữ số
            int d = (N / power) % 10;
            if (d != 0) {
                long long add = power * (10 - d);
                ans += add;
                N += add;
                if (digit_sum(N) <= S) break;
            }
            power *= 10;
        }
        cout << ans << "\n";
    }
}

// Ý tưởng thuật toán:
//     Tính digit sum của N. Nếu ≤ S → in 0.
//     Nếu không:
    //     Ta lần lượt xét từ hàng đơn vị sang trái.
    //     Với mỗi chữ số, ta tính số cần cộng để làm cho các chữ số bên phải trở thành 0 (làm N thành bội của 10, 100, 1000, ...).
    //     Sau khi cộng, kiểm tra digit sum mới. Nếu ≤ S → ta dừng.
    //     Đáp án là giá trị cộng nhỏ nhất tìm được.
    //     Vì 𝑁≤10^18, ta có nhiều nhất 18 chữ số → thuật toán rất nhanh, chạy tốt cho 𝑇 ≤20000.