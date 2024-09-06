#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Bảng băm để lưu tổng của các tập con và danh sách các mặt nạ bit tương ứng
    unordered_map<int, vector<int>> sum_map;
    
    // Tạo tất cả các tập con
    for (int mask = 1; mask < (1 << N); ++mask) {
        int subset_sum = 0;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                subset_sum += A[i];
            }
        }
        sum_map[subset_sum].push_back(mask);
    }
    
    // Tìm các giá trị X sao cho có ít nhất hai tập con có tổng bằng X và không giao nhau
    set<int> results;
    for (const auto& entry : sum_map) {
        const vector<int>& masks = entry.second;
        int size = masks.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if ((masks[i] & masks[j]) == 0) {  // Kiểm tra xem hai tập con có giao nhau không
                    results.insert(entry.first);
                    break;
                }
            }
            if (results.find(entry.first) != results.end()) {
                break;
            }
        }
    }
    
    // In kết quả
    cout << results.size() << endl;
    for (int x : results) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}
