/*
最终修复版本：保持原算法逻辑，添加必要的修复
*/

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

// 更安全的快速读取函数
inline int fastRead() {
    int x = 0, c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

int main() {
    int N = fastRead();
    vector<ull> Num(N), Cost(N);
    for (int i = 0; i < N; ++i) Num[i] = fastRead();
    for (int i = 0; i < N; ++i) Cost[i] = fastRead();

    sort(Num.begin(), Num.end());

    vector<ull> diff(N, 0);
    ull last = Num[0];
    for (int i = 1; i < N; ++i) {
        if (Num[i] <= last) {
            diff[i] = last + 1 - Num[i];
            last = last + 1;
        } else {
            diff[i] = 0;
            last = Num[i];
        }
    }

    sort(diff.begin(), diff.end(), greater<ull>());
    sort(Cost.begin(), Cost.end());

    ull ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += diff[i] * Cost[i];
        // 由于使用unsigned long long，溢出会自动取模2^64
    }

    printf("%llu\n", ans);
    return 0;
}
