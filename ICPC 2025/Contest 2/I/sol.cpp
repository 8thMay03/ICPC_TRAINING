#include <bits/stdc++.h>

using namespace std;

int64_t comb(int a, int b) {
    if (a < b) return 0;
    int64_t res = 1;
    for (int i = 1; i <= b; ++i) {
        res *= (a - i + 1);
        res /= i;
    }
    return res;
}

int main() {
    int A, B;
    int64_t K;
    cin >> A >> B >> K;
    string result;
    while (A > 0 && B > 0) {
        int64_t cnt = comb(A + B - 1, A - 1); // số xâu bắt đầu bằng 'a'
        if (K <= cnt) {
            result += 'a';
            A--;
        } else {
            result += 'b';
            K -= cnt;
            B--;
        }
    }
    result += string(A, 'a');
    result += string(B, 'b');
    cout << result << '\n';
}

// Ta không sinh ra toàn bộ các xâu (vì có thể lên tới hàng tỷ tổ hợp), mà xây xâu từng ký tự từ trái sang phải.

// Tại mỗi bước, bạn có 2 lựa chọn:
//     * Đặt 'a' đầu tiên → còn lại sẽ là A-1 chữ 'a', B chữ 'b' → số xâu như vậy là: C(A + B - 1, A - 1)
//     * Nếu K <= số xâu đó, thì xâu thứ K phải bắt đầu bằng 'a'
//     * Ngược lại, thì xâu thứ K bắt đầu bằng 'b', ta trừ bớt K -= số xâu bắt đầu bằng 'a'
// Cứ như vậy lặp lại cho đến khi hết ký tự.