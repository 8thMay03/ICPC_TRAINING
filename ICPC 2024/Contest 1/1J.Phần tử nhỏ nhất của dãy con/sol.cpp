#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> calculate_sx(const vector<int>& arr) {
    int n = arr.size();
    vector<int> S(n, 0);
    vector<int> next_smaller(n, n), prev_smaller(n, -1);

    stack<int> st;

    // Tính mảng next_smaller
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            next_smaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    // Làm trống ngăn xếp để tái sử dụng cho prev_smaller
    while (!st.empty()) st.pop();

    // Tính mảng prev_smaller
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            prev_smaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    // Tính giá trị lớn nhất của các giá trị nhỏ nhất cho tất cả độ dài dãy con
    vector<int> max_of_min(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int length = next_smaller[i] - prev_smaller[i] - 1;
        max_of_min[length] = max(max_of_min[length], arr[i]);
    }

    // Điền vào mảng kết quả S theo thứ tự ngược lại
    for (int i = n - 1; i >= 1; --i) {
        max_of_min[i] = max(max_of_min[i], max_of_min[i + 1]);
    }

    for (int i = 1; i <= n; ++i) {
        S[i - 1] = max_of_min[i];
    }

    return S;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> result = calculate_sx(A);

    for (int value : result) {
        cout << value << ' ';
    }

    return 0;
}
