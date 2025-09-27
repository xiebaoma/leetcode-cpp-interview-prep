/**
 * xiebaoma
 * 2025-09-27
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<string> votes(n);
    for (int i = 0; i < n; i++) {
        cin >> votes[i];
    }

    int ans = 0;

    // 枚举所有子集，必须包含尧（第0号）
    // 用位掩码表示：bit i = 1 表示选手 i 参加
    for (int mask = 1; mask < (1 << n); mask++) {
        if ((mask & 1) == 0) continue; // 必须包含尧

        // 当前存活的选手集合
        vector<int> alive;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                alive.push_back(i);

        // 模拟 k 轮投票
        bool yaoAlive = true;
        for (int round = 0; round < k; round++) {
            int plusCnt = 0, minusCnt = 0;
            for (int id : alive) {
                if (votes[id][round] == '+') plusCnt++;
                else minusCnt++;
            }

            if (plusCnt == minusCnt) {   // 平票，全体淘汰
                yaoAlive = false;
                alive.clear();
                break;
            }

            char winVote = (plusCnt > minusCnt ? '+' : '-');
            vector<int> nextAlive;
            for (int id : alive) {
                if (votes[id][round] == winVote)
                    nextAlive.push_back(id);
            }
            alive.swap(nextAlive);

            // 检查尧是否还活着
            if (find(alive.begin(), alive.end(), 0) == alive.end()) {
                yaoAlive = false;
                break;
            }
        }

        // 如果尧活到最后，更新最大人数
        if (yaoAlive) {
            ans = max(ans, (int)alive.size());
        }
    }

    cout << ans << "\n";
    return 0;
}
