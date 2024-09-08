#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 15;
vector<long long> fact(MAXN + 1);

// Hàm tính giai thừa trước
void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        fact[i] = fact[i - 1] * i;
    }
}

// Hàm trả về số thứ tự của hoán vị P
long long permutationToIndex(const vector<int>& P) {
    int N = P.size();
    vector<bool> used(N + 1, false);
    long long index = 0;
    
    for (int i = 0; i < N; ++i) {
        int smaller = 0;  // Đếm các phần tử nhỏ hơn P[i] chưa sử dụng
        for (int j = 1; j < P[i]; ++j) {
            if (!used[j]) smaller++;
        }
        index += smaller * fact[N - i - 1];
        used[P[i]] = true;
    }
    
    return index + 1;  // Hoán vị bắt đầu từ 1
}

// Hàm trả về hoán vị thứ X
vector<int> indexToPermutation(int N, long long X) {
    vector<int> P;
    vector<int> available;
    for (int i = 1; i <= N; ++i) {
        available.push_back(i);
    }
    
    X--;  // Chuyển về chỉ số 0
    for (int i = N; i >= 1; --i) {
        int pos = X / fact[i - 1];
        P.push_back(available[pos]);
        available.erase(available.begin() + pos);
        X %= fact[i - 1];
    }
    
    return P;
}

int main() {
    precomputeFactorials();
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        int K;
        cin >> K;
        
        if (K == 1) {
            // Truy vấn loại 1: Tìm số thứ tự của hoán vị
            vector<int> P(N);
            for (int i = 0; i < N; ++i) {
                cin >> P[i];
            }
            cout << permutationToIndex(P) << endl;
        } else if (K == 2) {
            // Truy vấn loại 2: Tìm hoán vị thứ X
            long long X;
            cin >> X;
            vector<int> result = indexToPermutation(N, X);
            for (int i = 0; i < N; ++i) {
                cout << result[i] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
