/**
 * xiebaoma
 * 2025-10-12
 */

#include <bits/stdc++.h>
using namespace std;

long long n, k, A, B;
vector<long long> soldiers;

long long solve(long long l, long long r) {
    // 区间长度
    long long L = r - l + 1;

    // 查找区间内士兵数量 s
    auto left_it = lower_bound(soldiers.begin(), soldiers.end(), l);
    auto right_it = upper_bound(soldiers.begin(), soldiers.end(), r);
    long long s = distance(left_it, right_it);

    // 如果区间无士兵
    if (s == 0) return A;

    // 直接烧毁
    long long cost_direct = B * s * L;

    // 不能再拆分
    if (l == r) return cost_direct;

    // 分成两段
    long long mid = (l + r) / 2;
    long long cost_split = solve(l, mid) + solve(mid + 1, r);

    return min(cost_direct, cost_split);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> A >> B;
    soldiers.resize(k);
    for (int i = 0; i < k; i++) cin >> soldiers[i];
    sort(soldiers.begin(), soldiers.end());

    long long total_length = 1LL << n;
    cout << solve(1, total_length) << "\n";
    return 0;
}
