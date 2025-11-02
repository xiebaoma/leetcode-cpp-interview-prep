/*
修复版本：正确处理权力调整问题

问题分析：
1. 需要让所有大臣权力互不相同
2. 只能增加权力，不能减少
3. 可以重新排序代价数组
4. 目标是最小化总代价

策略：
1. 将权力数组排序
2. 计算每个位置需要增加的最小权力值
3. 将需要增加的权力值按降序排列
4. 将代价按升序排列
5. 贪心匹配：最大的增加量对应最小的代价
*/

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

inline int fastRead() {
    int x = 0, c = getchar_unlocked();
    while (c < '0' || c > '9') c = getchar_unlocked();
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar_unlocked();
    }
    return x;
}

int main() {
    int N = fastRead();
    vector<ull> Num(N), Cost(N);
    for (int i = 0; i < N; ++i) Num[i] = fastRead();
    for (int i = 0; i < N; ++i) Cost[i] = fastRead();

    // 将权力值排序
    sort(Num.begin(), Num.end());

    // 计算每个位置需要增加的权力值
    vector<ull> increase(N, 0);
    
    for (int i = 1; i < N; ++i) {
        if (Num[i] <= Num[i-1]) {
            // 需要调整到比前一个大1
            ull target = Num[i-1] + 1;
            increase[i] = target - Num[i];
            Num[i] = target; // 更新实际权力值
        }
    }

    // 贪心策略：最大的增加量对应最小的代价
    sort(increase.begin(), increase.end(), greater<ull>());
    sort(Cost.begin(), Cost.end());

    ull ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += increase[i] * Cost[i];
    }

    printf("%llu\n", ans);
    return 0;
}
