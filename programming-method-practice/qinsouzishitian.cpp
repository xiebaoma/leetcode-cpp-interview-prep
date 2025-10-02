/**
 * xiebaoma
 * 2025-10-2
 */
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Point {
    double x, y;
};

// 叉积 (P1P2 × P1P3)
double cross(const Point &p1, const Point &p2, const Point &p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - 
           (p2.y - p1.y) * (p3.x - p1.x);
}

// 两点距离
double dist(const Point &a, const Point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

    if (n == 1) {  // 只有一个点，周长为0
        cout << "0.0\n";
        return 0;
    }

    // 找出所有凸包边
    set<pair<int,int>> edges; // 用于去重

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int pos = 0, neg = 0;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                double c = cross(pts[i], pts[j], pts[k]);
                if (c > 1e-9) pos++;
                else if (c < -1e-9) neg++;
                if (pos && neg) break; // 不在同侧
            }
            if (!(pos && neg)) {
                // 说明 (i,j) 在凸包上
                edges.insert({i,j});
                edges.insert({j,i});
            }
        }
    }

    // edges中已经包含了凸包边的双向对
    // 现在需要计算凸包的周长
    // 方法：从最左下点出发，依次找到凸包上的下一个点

    // 找起点：y最小，如果相同选x最小
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (pts[i].y < pts[start].y || 
           (fabs(pts[i].y - pts[start].y) < 1e-9 && pts[i].x < pts[start].x))
            start = i;
    }

    double ans = 0.0;
    int cur = start, prev = -1;
    do {
        // 找到cur的下一个凸包点
        int nxt = -1;
        for (int i = 0; i < n; i++) {
            if (i == cur) continue;
            if (edges.count({cur,i}) == 0) continue;
            if (nxt == -1) nxt = i;
            else {
                double c = cross(pts[cur], pts[nxt], pts[i]);
                if (c < -1e-9) // 选择更逆时针的点
                    nxt = i;
            }
        }
        ans += dist(pts[cur], pts[nxt]);
        cur = nxt;
    } while (cur != start);

    cout << fixed << setprecision(6) << ans << "\n";
    return 0;
}
