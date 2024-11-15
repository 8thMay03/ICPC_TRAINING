#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> masks(N);
    
    // Đọc các chuỗi và chuyển mỗi chuỗi thành bitmask
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        int mask = 0;
        for (char c : s) {
            mask |= (1 << (c - 'a')); // Đánh dấu sự xuất hiện của ký tự c bằng cách set bit tương ứng
        }
        masks[i] = mask;
    }
    
    int totalCount = 0;
    
    // Duyệt qua tất cả các tập con của N chuỗi
    for (int mask = 1; mask < (1 << N); ++mask) {
        int combinedMask = 0;
        
        // Xét các chuỗi thuộc tập con
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) { // Kiểm tra nếu chuỗi thứ i thuộc tập con
                combinedMask |= masks[i]; // Hợp bitmask của chuỗi này vào combinedMask
            }
        }
        
        // Kiểm tra nếu combinedMask có đủ 26 ký tự (tất cả 26 bit đầu tiên đều là 1)
        if (combinedMask == (1 << 26) - 1) {
            ++totalCount;
        }
    }
    
    // In ra kết quả
    cout << totalCount << endl;
    
    return 0;
}
