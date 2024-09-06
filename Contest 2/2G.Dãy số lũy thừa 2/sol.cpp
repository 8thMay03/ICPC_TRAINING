/*
    Created by kamine
*/
#include <bits/stdc++.h>

using namespace std;

class BigInt {
private:
    string num;

public:    
    BigInt() {
        num = "0";
    }

    BigInt(string num) {
        this->num = num;
    }

    bool operator < (BigInt other) {
        string a = num;
        string b = other.num;
        if (a.size() != b.size()) {
            return a.size() < b.size();
        }
        return a < b;
    }

    bool operator > (BigInt other) {
        string a = num;
        string b = other.num;
        if (a.size() != b.size()) {
            return a.size() > b.size();
        }
        return a > b;
    }

    bool operator == (BigInt other) {
        return num == other.num;
    }

    bool operator <= (BigInt other) {
        return *this < other || *this == other;
    }

    bool operator >= (BigInt other) {
        return *this > other || *this == other;
    }

    void operator = (BigInt other) {
        num = other.num;
    }

    string to_string() {
        return num;
    }

    BigInt operator + (BigInt other) {
        string a = num;
        string b = other.num;
        if (a.size() < b.size()) {
            swap(a, b);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        string res;
        for (int i = 0; i < (int)a.size(); i++) {
            int x = a[i] - '0';
            int y = i < (int)b.size() ? b[i] - '0' : 0;
            int sum = x + y + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry) {
            res.push_back(carry + '0');
        }
        reverse(res.begin(), res.end());
        return BigInt(res);
    }

    BigInt operator - (BigInt other) {
        string a = num;
        string b = other.num;
        if (a.size() < b.size() || (a.size() == b.size() && a < b)) {
            swap(a, b);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        string res;
        for (int i = 0; i < (int)a.size(); i++) {
            int x = a[i] - '0';
            int y = i < (int)b.size() ? b[i] - '0' : 0;
            int sub = x - y - carry;
            if (sub < 0) {
                sub += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res.push_back(sub + '0');
        }
        while (res.size() > 1 && res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return BigInt(res);
    }

    BigInt operator * (BigInt other) {
        string a = num;
        string b = other.num;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        vector<int> mul(a.size() + b.size());
        for (int i = 0; i < (int)a.size(); i++) {
            for (int j = 0; j < (int)b.size(); j++) {
                mul[i + j] += (a[i] - '0') * (b[j] - '0');
            }
        }
        int carry = 0;
        string res;
        for (int i = 0; i < (int)mul.size(); i++) {
            int sum = mul[i] + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        while (res.size() > 1 && res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return BigInt(res);
    }

    BigInt operator / (BigInt other) {
        string a = num;
        string b = other.num;
        BigInt res;
        BigInt zero("0");
        BigInt one("1");
        BigInt two("2");
        BigInt ten("10");
        while (a.size() >= b.size()) {
            BigInt l = zero;
            BigInt r = BigInt(a);
            while (l < r) {
                BigInt mid = (l + r) / two;
                BigInt val = other * mid;
                if (val <= BigInt(a)) {
                    l = mid + one;
                } else {
                    r = mid;
                }
            }
            res = res * ten + l - one;
            BigInt val = other * l;
            a = (BigInt(a) - val).to_string();
        }
        return res;
    }

    BigInt operator % (BigInt other) {
        string a = num;
        string b = other.num;
        BigInt res;
        BigInt zero("0");
        BigInt one("1");
        BigInt two("2");
        BigInt ten("10");
        while (a.size() >= b.size()) {
            BigInt l = zero;
            BigInt r = BigInt(a);
            while (l < r) {
                BigInt mid = (l + r) / two;
                BigInt val = other * mid;
                if (val <= BigInt(a)) {
                    l = mid + one;
                } else {
                    r = mid;
                }
            }
            res = res * ten + l - one;
            BigInt val = other * l;
            a = (BigInt(a) - val).to_string();
        }
        return BigInt(a);
    }

    BigInt operator << (int k) {
        string a = num;
        while (k--) {
            a.push_back('0');
        }
        return BigInt(a);
    }

    BigInt operator >> (int k) {
        string a = num;
        while (k--) {
            a.pop_back();
        }
        return BigInt(a);
    }

    BigInt pow(BigInt a, BigInt b) {
        if (b == BigInt("0")) {
            return BigInt("1");
        }
        BigInt tmp = pow(a, b / BigInt("2"));
        if (b % BigInt("2") == BigInt("0")) {
            return tmp * tmp;
        }
        return a * tmp * tmp;
    }

    BigInt operator & (BigInt other) {
        string a = num;
        string b = other.num;
        while (a.size() < b.size()) {
            a = '0' + a;
        }
        while (b.size() < a.size()) {
            b = '0' + b;
        }
        string res;
        for (int i = 0; i < (int)a.size(); i++) {
            res.push_back((a[i] - '0') & (b[i] - '0') + '0');
        }
        return BigInt(res);
    }

    BigInt operator | (BigInt other) {
        string a = num;
        string b = other.num;
        while (a.size() < b.size()) {
            a = '0' + a;
        }
        while (b.size() < a.size()) {
            b = '0' + b;
        }
        string res;
        for (int i = 0; i < (int)a.size(); i++) {
            res.push_back((a[i] - '0') | (b[i] - '0') + '0');
        }
        return BigInt(res);
    }

    BigInt operator ^ (BigInt other) {
        string a = num;
        string b = other.num;
        while (a.size() < b.size()) {
            a = '0' + a;
        }
        while (b.size() < a.size()) {
            b = '0' + b;
        }
        string res;
        for (int i = 0; i < (int)a.size(); i++) {
            res.push_back((a[i] - '0') ^ (b[i] - '0') + '0');
        }
        return BigInt(res);
    }

    friend ostream& operator << (ostream& os, const BigInt& BigInt) {
        os << BigInt.num;
        return os;
    }

    friend istream& operator >> (istream& is, BigInt& BigInt) {
        is >> BigInt.num;
        return is;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<BigInt> a(n);
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        a[i] = BigInt(x);
    }
    stack<BigInt> st;
    for (BigInt i : a) {
        while (!st.empty() && st.top() < i) {
            st.pop();
        }
        while (!st.empty() && i == st.top()) {
            st.pop();
            i = i + i;
        }
        st.push(i);
    }
    while (st.size() > 1) {
        st.pop();
    }
    cout << st.top() << '\n';
}