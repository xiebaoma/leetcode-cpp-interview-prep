/*
抗日战争期间，中国军民万众一心，为了保护自己的家园前赴后继。即使在敌占区，也有国民党和共产党的情报人员，通过自己的伪装，不断地将敌人的情报向抗日民族统一战线进行传递。

现在有一段情报以数字进行呈现，先给出一段长为n的数据，之后的m行询问的每一个结果会合成整个真实的情报码。询问以l,k的形式出现，
定义 f(l,r)(1≤l≤r≤n) 表示 a[l​]&a[l+1]​&…&a[r−1​]&a[r​] 的结果。其中，& 表示位与运算。

对于每次询问，将给定 l,k。请你找到最大的 r 使得 f(l,r)≥k。如果无解，输出 -1。


输入描述
第一行一个整数n

第二行n个正整数表示给定的含有n个数的数组a

第三行一个整数q

之后q行每行两个整数l,k代表一次询问

n,q -> [1,10^5]

ai -> [0,10^9]

l->[1,n]

k->[0,10^9]


输出描述
一行q个数代表询问答案
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
int n, q;
int a[MAXN + 5];
int st[MAXN + 5][20];
int lg2_[MAXN + 5];

int range_and(int L, int R) {
    int k = lg2_[R - L + 1];
    return st[L][k] & st[R - (1 << k) + 1][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // 预处理 log2
    lg2_[1] = 0;
    for (int i = 2; i <= n; ++i) lg2_[i] = lg2_[i / 2] + 1;

    // 构建稀疏表
    for (int i = 1; i <= n; ++i) st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[i][j] = st[i][j - 1] & st[i + (1 << (j - 1))][j - 1];

    cin >> q;
    vector<int> ans(q);

    for (int i = 0; i < q; ++i) {
        int l, k;
        cin >> l >> k;
        int L = l, R = n, res = -1;
        while (L <= R) {
            int mid = (L + R) / 2;
            int val = range_and(l, mid);
            if (val >= k) {
                res = mid;
                L = mid + 1; // 继续往右找更大的 r
            } else {
                R = mid - 1;
            }
        }
        ans[i] = res;
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i];
        if (i + 1 < q) cout << " ";
    }
    cout << "\n";

    return 0;
}
