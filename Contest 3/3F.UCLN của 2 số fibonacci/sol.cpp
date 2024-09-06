#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

//GCD(F(a),F(b))=F(GCD(a,b))

// Hàm nhân 2 ma trận kích thước 2x2 với modulo M
vector<vector<ll>> matrixMultiply(const vector<vector<ll>>& A, const vector<vector<ll>>& B, ll M) {
    vector<vector<ll>> C(2, vector<ll>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
            }
        }
    }
    return C;
}

// Hàm tính ma trận lũy thừa A^n với modulo M
vector<vector<ll>> matrixPower(vector<vector<ll>> A, ll n, ll M) {
    vector<vector<ll>> result = {{1, 0}, {0, 1}}; // Ma trận đơn vị
    while (n > 0) {
        if (n % 2 == 1) {
            result = matrixMultiply(result, A, M);
        }
        A = matrixMultiply(A, A, M);
        n /= 2;
    }
    return result;
}

// Hàm tính F(n) % M dùng phương pháp nhân ma trận
ll fibMod(ll n, ll M) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    vector<vector<ll>> F = {{1, 1}, {1, 0}};
    vector<vector<ll>> result = matrixPower(F, n - 1, M);
    return result[0][0];
}

// Hàm tính GCD của 2 số nguyên a và b
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll a, b, M;
        cin >> a >> b >> M;
        ll g = gcd(a, b);
        cout << fibMod(g, M) << endl;
    }
    return 0;
}
