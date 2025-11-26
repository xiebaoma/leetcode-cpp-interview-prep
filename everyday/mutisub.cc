#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 去除前导零
string trim(const string &s) {
    int i = 0;
    while (i < s.size() - 1 && s[i] == '0') i++;
    return s.substr(i);
}

// 字符串大整数加法
string add(const string &a, const string &b) {
    string A = string(a.rbegin(), a.rend());
    string B = string(b.rbegin(), b.rend());

    string res;
    int carry = 0;

    for (int i = 0; i < max(A.size(), B.size()); i++) {
        int x = (i < A.size() ? A[i] - '0' : 0);
        int y = (i < B.size() ? B[i] - '0' : 0);
        int sum = x + y + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry) res.push_back(carry + '0');

    reverse(res.begin(), res.end());
    return trim(res);
}

// 字符串右移（乘以 10^n）
string shift10(const string &s, int n) {
    if (s == "0") return "0";
    return s + string(n, '0');
}

// 普通小型乘法（递归基底）
string multiplySmall(const string &a, const string &b) {
    if (a == "0" || b == "0") return "0";

    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int x = (a[i] - '0') * (b[j] - '0');
            int pos1 = i + j;
            int pos2 = i + j + 1;

            int sum = x + res[pos2];
            res[pos2] = sum % 10;
            res[pos1] += sum / 10;
        }
    }

    string out;
    for (int v : res) out.push_back(v + '0');
    return trim(out);
}

// 分治大数乘法
string multiplyDivideAndConquer(const string &X, const string &Y) {
    string A = trim(X), B = trim(Y);
    int n = max(A.size(), B.size());

    // 末尾补零，对齐长度
    while (A.size() < n) A = "0" + A;
    while (B.size() < n) B = "0" + B;

    // 小规模直接乘
    if (n <= 4) return multiplySmall(A, B);

    int m = n / 2;

    // 切分为高位和低位
    string A1 = A.substr(0, n - m);   // 高位
    string A2 = A.substr(n - m);      // 低位
    string B1 = B.substr(0, n - m);
    string B2 = B.substr(n - m);

    // 分治递归：4次子乘法
    string P1 = multiplyDivideAndConquer(A1, B1);
    string P2 = multiplyDivideAndConquer(A2, B2);
    string P3 = multiplyDivideAndConquer(A1, B2);
    string P4 = multiplyDivideAndConquer(A2, B1);

    // 合成结果
    // X*Y = P1*10^(2m) + (P3+P4)*10^m + P2
    string mid = add(P3, P4);
    string res = add( add(shift10(P1, 2*m), shift10(mid, m)), P2 );

    return trim(res);
}

int main() {
    string X = "12345678901234567890";
    string Y = "98765432109876543210";

    cout << "结果: " << multiplyDivideAndConquer(X, Y) << endl;
    return 0;
}
