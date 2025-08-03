#include <bits/stdc++.h>

using namespace std;

int main() {
    // Dãy ký tự chuẩn P[]
    string P = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
    map<char, int> char_to_index;
    
    // Tạo bảng ánh xạ từ ký tự đến vị trí của nó trong dãy P
    for (int i = 0; i < 28; ++i) {
        char_to_index[P[i]] = i;
    }

    int K;
    string S;
    
    // Đọc input cho đến khi K = 0
    while (cin >> K && K != 0) {
        cin >> S;
        
        string encoded = ""; // Chuỗi đã mã hóa
        
        // Mã hóa từng ký tự
        for (char c : S) {
            int current_index = char_to_index[c]; // Lấy vị trí của ký tự trong P
            int new_index = (current_index + K) % 28; // Vị trí mới sau khi dịch K
            encoded += P[new_index]; // Thêm ký tự mới vào chuỗi đã mã hóa
        }
        
        // Đảo ngược chuỗi đã mã hóa
        reverse(encoded.begin(), encoded.end());
        
        // Xuất kết quả
        cout << encoded << endl;
    }

    return 0;
}
