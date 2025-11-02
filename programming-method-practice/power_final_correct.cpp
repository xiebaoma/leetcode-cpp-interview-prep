/*
最终正确版本：
关键洞察：我们需要让所有数字互不相同，但可以自由选择哪些数字增加多少

策略：
1. 统计每个数字出现的次数
2. 对于出现多次的数字，除了第一个保持不变，其余的需要增加
3. 计算所有需要的增加量
4. 贪心分配：最大增加量使用最小代价
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

    // 统计每个数字需要调整的情况
    map<ull, int> count;
    for (ull x : Num) {
        count[x]++;
    }
    
    vector<ull> increases;
    
    // 对于每个重复的数字，计算需要的增加量
    for (auto& p : count) {
        ull value = p.first;
        int cnt = p.second;
        
        // 如果这个数字出现多次，需要调整除第一个外的所有
        for (int i = 1; i < cnt; ++i) {
            // 第i个重复的数字需要增加i，使其变成value+i
            increases.push_back(i);
        }
    }
    
    // 但是还要考虑调整后可能与其他数字冲突的情况
    // 更简单的方法：排序后计算最小调整方案
    sort(Num.begin(), Num.end());
    increases.clear();
    
    for (int i = 1; i < N; ++i) {
        if (Num[i] <= Num[i-1]) {
            ull need = Num[i-1] + 1 - Num[i];
            increases.push_back(need);
            Num[i] = Num[i-1] + 1;
        }
    }
    
    // 贪心：最大增加量用最小代价
    sort(increases.begin(), increases.end(), greater<ull>());
    sort(Cost.begin(), Cost.end());
    
    ull ans = 0;
    for (int i = 0; i < increases.size(); ++i) {
        ans += increases[i] * Cost[i];
    }
    
    printf("%llu\n", ans);
    return 0;
}
