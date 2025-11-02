/*
正确的解法：
1. 计算让所有数字互不相同需要的最小增加量
2. 贪心分配：最大的增加量使用最小的代价
*/

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

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

    // 对原数组排序，找出需要调整的最小方案
    vector<ull> sortedNum = Num;
    sort(sortedNum.begin(), sortedNum.end());
    
    // 计算每个位置需要增加多少才能让所有数字互不相同
    vector<ull> increases;
    
    for (int i = 1; i < N; ++i) {
        if (sortedNum[i] <= sortedNum[i-1]) {
            ull need = sortedNum[i-1] + 1 - sortedNum[i];
            increases.push_back(need);
            sortedNum[i] = sortedNum[i-1] + 1; // 更新值
        }
    }
    
    // 贪心策略：最大的增加量分配最小的代价
    sort(increases.begin(), increases.end(), greater<ull>());
    sort(Cost.begin(), Cost.end());
    
    ull ans = 0;
    for (int i = 0; i < increases.size(); ++i) {
        ans += increases[i] * Cost[i];
    }
    
    printf("%llu\n", ans);
    return 0;
}
