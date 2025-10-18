/**
 * xiebaoma
 * 2025-10-12
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int cur = a[0], ans = a[0];
    for (int i = 1; i < n; ++i) {
        cur = max(a[i], cur + a[i]);
        ans = max(ans, cur);
    }

    cout << ans << "\n";
    return 0;
}
