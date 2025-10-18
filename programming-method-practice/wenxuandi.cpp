#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    int m;
    if (!(cin >> n)) return 0;
    cin >> m;

    if (m == 0) { // 不做任何操作，只有初始一种状态
        cout << 1 << '\n';
        return 0;
    }

    int n_eff = (int)min( (long long)3, n ); // 只需看前3个坑
    unordered_set<string> states;

    // 按位意义：bit0 - 操作1(反转所有)
    //            bit1 - 操作2(反转偶数)
    //            bit2 - 操作3(反转奇数)
    //            bit3 - 操作4(反转编号为 3k+1)
    for (int mask = 0; mask < 16; ++mask) {
        int s = __builtin_popcount((unsigned)mask);
        if (s > m) continue;
        if ((m - s) % 2 != 0) continue; // (m - s) 必须为偶数

        string cur;
        cur.reserve(n_eff);
        for (int pos = 1; pos <= n_eff; ++pos) {
            int val = 1; // 初始为已满，表示 1
            int toggles = 0;
            if (mask & 1) toggles ^= 1; // 操作1: 所有位置都反转
            if (mask & 2) { // 操作2: 偶数编号反转
                if (pos % 2 == 0) toggles ^= 1;
            }
            if (mask & 4) { // 操作3: 奇数编号反转
                if (pos % 2 == 1) toggles ^= 1;
            }
            if (mask & 8) { // 操作4: 编号为 3k+1 (pos-1)%3==0
                if ((pos - 1) % 3 == 0) toggles ^= 1;
            }
            int finalv = val ^ toggles;
            cur.push_back(finalv ? '1' : '0');
        }
        states.insert(cur);
    }

    cout << states.size() << '\n';
    return 0;
}
