/*
抗日战争期间，中国军民万众一心，为了保护自己的家园前赴后继。即使在敌占区，也有国民党和共产党的情报人员，通过自己的伪装，不断地将敌人的情报向抗日民族统一战线进行传递。

现在有一段情报以数字进行呈现，先给出一段长为n的数据，之后的m行询问的每一个结果会合成整个真实的情报码。询问以l,k的形式出现，
定义 f(l,r)(1≤l≤r≤n) 表示 a[l​]&a[l+1]​&…&a[r−1​]&a[r​] 的结果。其中，& 表示位与运算。

对于每次询问，将给定 l,k。请你找到最大的 r 使得 f(l,r)≥k。如果无解，输出 -1。

修复版本：使用线段树正确处理区间AND查询
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
int n, q;
int a[MAXN + 5];

// 线段树节点
struct SegmentTree {
    vector<int> tree;
    int size;
    
    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, (1 << 30) - 1); // 初始化为全1
    }
    
    void build(int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < n) {
                tree[x] = a[lx + 1]; // 注意索引转换
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(2 * x + 1, lx, mid);
        build(2 * x + 2, mid, rx);
        tree[x] = tree[2 * x + 1] & tree[2 * x + 2];
    }
    
    void build() {
        build(0, 0, size);
    }
    
    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return (1 << 30) - 1; // 返回全1，不影响AND结果
        if (lx >= l && rx <= r) return tree[x];
        
        int mid = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, mid) & query(l, r, 2 * x + 2, mid, rx);
    }
    
    int query(int l, int r) {
        return query(l - 1, r, 0, 0, size); // 转换为0-based索引
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    SegmentTree st(n);
    st.build();

    cin >> q;
    vector<int> ans(q);

    for (int i = 0; i < q; ++i) {
        int l, k;
        cin >> l >> k;
        
        int L = l, R = n, res = -1;
        while (L <= R) {
            int mid = (L + R) / 2;
            int val = st.query(l, mid);
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
