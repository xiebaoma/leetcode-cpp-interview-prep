#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n + 1);
    for (int i = 1; i <= n; ++i) cin >> coins[i];

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        cout << coins[1] << endl;
        return 0;
    }

    vector<long long> dp(n + 1);
    dp[1] = coins[1];
    dp[2] = max((long long)coins[1], (long long)coins[2]);

    for (int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + coins[i]);
    }

    cout << dp[n] << endl;
    return 0;
}
