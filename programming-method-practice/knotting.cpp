#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int steps = 0;

    // 贪心地从左往右处理
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1') {
            // 翻转 s[i] 和 s[i+1]
            s[i] = (s[i] == '1' ? '0' : '1');
            s[i + 1] = (s[i + 1] == '1' ? '0' : '1');
            steps++;
        }
    }

    // 检查最后一位
    if (s[n - 1] == '0')
        cout << steps << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
