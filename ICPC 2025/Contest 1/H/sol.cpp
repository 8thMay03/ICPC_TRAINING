#include <iostream>
#include <cmath>
using namespace std;

int min_steps_to_equal(int A, int B) {
    long long diff = abs(A - B);
    if (diff == 0) return 0;
    long long k = 0, total = 0;
    while (true) {
        ++k;
        total += k;
        if (total >= diff && (total - diff) % 2 == 0) {
            return k;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << min_steps_to_equal(A, B) << '\n';
    }
}
