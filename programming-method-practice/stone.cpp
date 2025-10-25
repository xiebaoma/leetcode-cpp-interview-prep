#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    cin >> L;

    int S, T, M;
    cin >> S >> T >> M;

    vector<int> stone(M);
    for (int i = 0; i < M; ++i)
        cin >> stone[i];
    sort(stone.begin(), stone.end());

    // ---------- Step 1: 坐标压缩 ----------
    // 因为 S,T 都很小，所以相邻石头间隔太大时可以压缩
    vector<int> pos;
    pos.push_back(0);
    for (int i = 0; i < M; ++i) {
        if (i == 0)
            pos.push_back(stone[i]);
        else {
            int gap = stone[i] - stone[i - 1];
            if (gap > 1000)
                gap = 1000; // 压缩大间隙
            pos.push_back(pos.back() + gap);
        }
    }
    int len = pos.back() + T; // 最远可能跳到石头之后

    vector<int> isStone(len + 1, 0);
    for (int i = 1; i <= M; ++i)
        isStone[pos[i]] = 1;

    // ---------- Step 2: 动态规划 ----------
    vector<int> dp(len + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= len; ++i) {
        for (int j = S; j <= T; ++j) {
            if (i - j >= 0)
                dp[i] = min(dp[i], dp[i - j] + isStone[i]);
        }
    }

    // ---------- Step 3: 求答案 ----------
    int ans = INF;
    for (int i = pos.back(); i <= len; ++i)
        ans = min(ans, dp[i]);

    cout << ans << "\n";
    return 0;
}
