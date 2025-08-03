#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool canTransform(const string &S, const string &T) {
    if (S.length() != T.length()) {
        return false;
    }

    unordered_map<char, char> map_S_to_T;
    unordered_map<char, char> map_T_to_S;

    for (int i = 0; i < S.length(); ++i) {
        char s_char = S[i];
        char t_char = T[i];

        // Kiểm tra xem có mâu thuẫn trong phép ánh xạ không
        if (map_S_to_T.count(s_char) && map_S_to_T[s_char] != t_char) {
            return false;
        }
        if (map_T_to_S.count(t_char) && map_T_to_S[t_char] != s_char) {
            return false;
        }

        // Cập nhật ánh xạ
        map_S_to_T[s_char] = t_char;
        map_T_to_S[t_char] = s_char;
    }

    return true;
}

int main() {
    string S, T;
    cout << "Nhập xâu S: ";
    cin >> S;
    cout << "Nhập xâu T: ";
    cin >> T;

    if (canTransform(S, T)) {
        cout << "Có thể biến đổi xâu S thành xâu T.\n";
    } else {
        cout << "Không thể biến đổi xâu S thành xâu T.\n";
    }

    return 0;
}
