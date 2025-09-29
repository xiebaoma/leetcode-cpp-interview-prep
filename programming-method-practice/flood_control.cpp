/**
 * xiebaoma
 * 2025-09-27
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main() {

    int n, R;
    cin >> n >> R;

    vector<long long> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    priority_queue<long long> pq;

    // 初始差值
    for (int i = 0; i < n; i++) {
        pq.push(llabs(A[i] - B[i]));
    }

    // R 次操作
    for (int i = 0; i < R; i++) {
        long long x = pq.top(); pq.pop();
        if (x > 0) x -= 1;
        else       x += 1;   // 只能增加
        pq.push(x);
    }

    // 计算相似度
    long long ans = 0;
    while (!pq.empty()) {
        long long x = pq.top(); pq.pop();
        ans += x * x;
    }

    cout << ans << "\n";
    return 0;
}
