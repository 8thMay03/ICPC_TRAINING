#include <bits/stdc++.h>
using namespace std;

int main() {
    int K;
    cin >> K;

    vector<vector<int>> a(K, vector<int>(K));
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> a[i][j];
        }
    }

    // Bắt đầu với hàng đầu tiên
    vector<int> current = a[0];  // Kết quả tạm thời với hàng đầu tiên
    sort(current.begin(), current.end());  // Sắp xếp hàng đầu tiên

    // Duyệt qua từng hàng từ hàng thứ 2 trở đi
    for (int i = 1; i < K; ++i) {
        priority_queue<int> pq;  // Heap tối đa để giữ K tổng nhỏ nhất
        for (int x : current) {
            for (int y : a[i]) {
                int sum = x + y;
                pq.push(sum);
                if (pq.size() > K) {
                    pq.pop();  // Giữ lại đúng K phần tử nhỏ nhất
                }
            }
        }

        // Lấy lại K phần tử nhỏ nhất từ heap
        current.clear();
        while (!pq.empty()) {
            current.push_back(pq.top());
            pq.pop();
        }
        sort(current.begin(), current.end());  // Sắp xếp lại để giữ thứ tự
    }

    // In ra K tổng nhỏ nhất
    for (int i = 0; i < K; ++i) {
        cout << current[i] << " ";
    }
    cout << endl;

    return 0;
}
