/*
优化版本：利用位与操作的单调性，使用双指针或预处理
由于AND操作的单调递减性质，我们可以预处理每个位置开始的最远可达位置
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
int n, q;
int a[MAXN + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    cin >> q;
    
    for (int i = 0; i < q; ++i) {
        int l, k;
        cin >> l >> k;
        
        int current_and = a[l];
        int res = -1;
        
        // 从l开始向右扩展，直到AND值小于k
        for (int r = l; r <= n; ++r) {
            if (r > l) {
                current_and &= a[r];
            }
            
            if (current_and >= k) {
                res = r; // 更新最大的r
            } else {
                break; // 由于单调性，后面的都不会满足条件
            }
        }
        
        cout << res;
        cout << " ";
    }
    cout << "\n";

    return 0;
}
