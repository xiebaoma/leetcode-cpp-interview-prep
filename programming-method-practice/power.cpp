/*
用C++解决这个问题： 明朝，朱权在位期间，朝廷内有两位权臣——张居正和冯保。张居正掌管国库，而冯保掌管兵权。 某日，天子发现朝中有N名重臣的权力过于接近，这可能会导致政局不稳。他决定重新分配这N名大臣的权力。 张居正提供了一套记录这些大臣权力的册子（Num），冯保则提供了一套调整这些权力所需要的代价册子(Cost)。为了使得代价最小，张居正提议在调整权力前，允许冯保重新排序代价册子(Cost)中的代价值。 每当增加某大臣的权力值(Num[i])时，都需要消耗(Cost[i])的代价。一旦开始调整，代价册子(Cost)就不能再进行改动。 在这种情况下，如何使得这N名大臣的权力互不相同，并且总代价最小？结果需要对2^64取模。 输入描述 第一个一个正整数N 第二行N个正整数Num[i] 第三行N个正整数Cost[i] N -> [1,10^6] Num,Cost -> [1,10^9] 尽量不要使用cin输入，以免输入时间开销过大 输出描述 最小代价值，记得对2^64次取模 测试用例 1 以文本方式显示 3↵ 3 3 3↵ 1 2 3↵ 以文本方式显示 4↵ 测试用例 2 以文本方式显示 3↵ 3 3 4↵ 3 2 1↵ 以文本方式显示 2↵
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
    for (int i = 0; i < N; ++i)
        ans += diff[i] * Cost[i];

    printf("%llu\n", ans);
    return 0;
}
