#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> d(m);
    for (int i = 0; i < m; ++i) cin >> d[i];

    const int INF = INT_MAX / 2;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i >= d[j]) {
                dp[i] = min(dp[i], dp[i - d[j]] + 1);
            }
        }
    }

    if (dp[n] == INF)
        cout << "无法找零" << endl;
    else
        cout << dp[n] << endl;

    return 0;
}
