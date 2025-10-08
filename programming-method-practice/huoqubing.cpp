#include <bits/stdc++.h>
using namespace std;

struct Soldier {
    double x, y;
};

int N;
vector<Soldier> soldiers;

// 计算在 x 轴上某点 cx 时，到所有士兵的最远距离
double maxDistance(double cx) {
    double res = 0.0;
    for (auto &s : soldiers) {
        double dx = cx - s.x;
        double dy = s.y;   // 指挥点在 x 轴上，y=0
        double dist = sqrt(dx * dx + dy * dy);
        if (dist > res) res = dist;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    soldiers.resize(N);

    double L = 1e9, R = -1e9; // 初始搜索区间
    for (int i = 0; i < N; ++i) {
        cin >> soldiers[i].x >> soldiers[i].y;
        L = min(L, soldiers[i].x);
        R = max(R, soldiers[i].x);
    }

    // 三分搜索
    for (int i = 0; i < 100; ++i) {  // 迭代次数足够保证精度
        double m1 = L + (R - L) / 3.0;
        double m2 = R - (R - L) / 3.0;

        double f1 = maxDistance(m1);
        double f2 = maxDistance(m2);

        if (f1 > f2)
            L = m1;
        else
            R = m2;
    }

    double ans = maxDistance((L + R) / 2.0);
    cout << fixed << setprecision(4) << ans << "\n";

    return 0;
}
