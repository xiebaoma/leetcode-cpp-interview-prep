#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;

// 高斯消元法
int gauss(vector<vector<double>>& a, vector<double>& ans, int n) {
    int row = 0, col = 0;
    for (; col < n && row < n; ++col) {
        // 1. 选主元（选该列中绝对值最大的行）
        int pivot = row;
        for (int i = row + 1; i < n; ++i) {
            if (fabs(a[i][col]) > fabs(a[pivot][col])) pivot = i;
        }

        // 如果该列主元为 0，则跳过
        if (fabs(a[pivot][col]) < EPS) continue;

        // 2. 交换行
        swap(a[row], a[pivot]);

        // 3. 主元归一化
        double div = a[row][col];
        for (int j = col; j <= n; ++j) a[row][j] /= div;

        // 4. 消元
        for (int i = 0; i < n; ++i) {
            if (i != row && fabs(a[i][col]) > EPS) {
                double factor = a[i][col];
                for (int j = col; j <= n; ++j) {
                    a[i][j] -= factor * a[row][j];
                }
            }
        }
        ++row;
    }

    // 判断解的情况
    // 若出现 0x+0y+0z=非0，则无解
    for (int i = row; i < n; ++i) {
        if (fabs(a[i][n]) > EPS) return 0; // No solution
    }

    // 若秩 < n，则有无穷多解
    if (row < n) return 2; // Infinite solutions

    // 唯一解
    for (int i = 0; i < n; ++i) ans[i] = a[i][n];
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<double>> a(n, vector<double>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<double> ans(n, 0);
    int status = gauss(a, ans, n);

    if (status != 1) {
        cout << "No Solution\n";
    } else {
        cout << fixed << setprecision(2);
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << "\n";
        }
    }

    return 0;
}
