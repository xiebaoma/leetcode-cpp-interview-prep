/**
 * xiebaoma
 * 2025-10-25
 */

#include <bits/stdc++.h>
using namespace std;

int n;
int a[70];
bool used[70];
int sum, target;

bool dfs(int stick_cnt, int cur_len, int start, int target_cnt) {
    if (stick_cnt == target_cnt) return true;        // 拼完所有树枝
    if (cur_len == target) return dfs(stick_cnt + 1, 0, 0, target_cnt); // 拼下一根树枝

    int prev = -1;
    for (int i = start; i < n; ++i) {
        if (used[i]) continue;
        if (a[i] == prev) continue; // 跳过相同长度的重复搜索
        if (cur_len + a[i] > target) continue;

        used[i] = true;
        if (dfs(stick_cnt, cur_len + a[i], i + 1, target_cnt)) return true;
        used[i] = false;

        prev = a[i]; // 记录上一个尝试过的长度

        // 剪枝3：当前拼不下且是第一根木柴，直接失败
        if (cur_len == 0 || cur_len + a[i] == target) return false;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + n, greater<int>()); // 从大到小排序

    for (target = a[0]; target <= sum; ++target) {
        if (sum % target != 0) continue; // 必须能整除
        memset(used, false, sizeof(used));
        int cnt = sum / target;
        if (dfs(0, 0, 0, cnt)) {
            cout << target << "\n";
            return 0;
        }
    }
    return 0;
}
