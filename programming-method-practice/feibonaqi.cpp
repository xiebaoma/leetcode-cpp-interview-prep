#include <bits/stdc++.h>
using namespace std;

/*
  实现说明：
  - 按行模拟，维护 used[1..MAXV] 标记被占用的正整数。
  - curMex 指向当前最小未被占用的正整数，查找 a_{t,1} 时从 curMex 开始前进。
  - 对每行生成若干项并标记 used，直到生成的项超过 MAXV（或行项增长很快无法再影响小整数）。
  - 一旦得到了第 i 行的前两项 p,q，使用矩阵快速幂求 a_{i,j} mod m。
*/

using int64 = long long;

struct Mat {
    int64 a[2][2];
};

Mat mul(const Mat &A, const Mat &B, int mod) {
    Mat C;
    C.a[0][0] = (A.a[0][0]*B.a[0][0] + A.a[0][1]*B.a[1][0]) % mod;
    C.a[0][1] = (A.a[0][0]*B.a[0][1] + A.a[0][1]*B.a[1][1]) % mod;
    C.a[1][0] = (A.a[1][0]*B.a[0][0] + A.a[1][1]*B.a[1][0]) % mod;
    C.a[1][1] = (A.a[1][0]*B.a[0][1] + A.a[1][1]*B.a[1][1]) % mod;
    return C;
}

Mat matPow(Mat base, long long e, int mod) {
    Mat res;
    res.a[0][0]=1; res.a[0][1]=0; res.a[1][0]=0; res.a[1][1]=1;
    while (e > 0) {
        if (e & 1) res = mul(res, base, mod);
        base = mul(base, base, mod);
        e >>= 1;
    }
    return res;
}

// 通过前两项 p,q 求第 j 项（1-based），返回 mod m
int compute_jth_mod(int64 p, int64 q, long long j, int m) {
    // a1 = p, a2 = q
    if (j == 1) return (int)((p % m + m) % m);
    if (j == 2) return (int)((q % m + m) % m);
    // recurrence vector: [a_k, a_{k+1}]^T = M^{k-1} * [a1, a2]^T,
    // where M = [[0,1],[1,1]].
    Mat M;
    M.a[0][0]=0; M.a[0][1]=1;
    M.a[1][0]=1; M.a[1][1]=1;
    Mat P = matPow(M, j-1, m); // v_j = P * v_1
    // v_1 = [a1, a2]^T
    int64 aj = (P.a[0][0] * (p % m) + P.a[0][1] * (q % m)) % m;
    if (aj < 0) aj += m;
    return (int)aj;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long i;
    long long j;
    int m;
    if (!(cin >> i >> j >> m)) return 0;

    // ========== 可调参数 ==========
    // MAXV 决定了我们能把小整数分配到的范围。
    // 增大 MAXV 可以支持更大的 i，但内存和时间也会增加。
    // 若你要处理非常大的 i（如 1e8/1e9），需要数学性质或专门算法。
    const int MAXV = 2000000; // 2e6，工程上可调整（内存 ~2MB 布尔 + 少量）
    // =============================

    if (i <= 0 || j <= 0 || m < 2) {
        cout << 0 << "\n";
        return 0;
    }

    // Quick guard: if i extremely large beyond what we can simulate:
    // we tell user that we cannot finish with this MAXV.
    // But we'll attempt; if curMex exceeds MAXV, we abort with message.
    vector<char> used(MAXV + 5, 0);

    long long curMex = 1; // minimal positive integer not used yet
    long long curRow = 1;

    int64 row_p = -1, row_q = -1; // result for target row i

    // simulate rows until reach i or curMex exceeds MAXV (failure region)
    while (curRow <= i) {
        // find next unused
        while (curMex <= MAXV && used[curMex]) ++curMex;
        if (curMex > MAXV) {
            cerr << "Error: needed mex exceeded MAXV = " << MAXV << ".\n";
            cerr << "Increase MAXV or provide mathematical formula for a_{i,1}.\n";
            // graceful exit: we cannot compute
            return 0;
        }
        long long p = curMex;
        long long q = 2 * p - curRow + 1; // second element

        if (curRow == i) {
            row_p = p;
            row_q = q;
            break;
        }

        // mark this row's elements into used[] as long as they are <= MAXV
        // generate until term > MAXV (since only small numbers matter for future mex)
        long long x = p, y = q;
        if (x <= MAXV) used[x] = 1;
        if (y <= MAXV) used[y] = 1;
        // advance curMex quickly if needed
        while (curMex <= MAXV && used[curMex]) ++curMex;

        // produce further terms
        for (;;) {
            long long z = x + y;
            if (z > MAXV) break;
            used[z] = 1;
            x = y; y = z;
            // advance curMex while possible
            while (curMex <= MAXV && used[curMex]) ++curMex;
        }

        ++curRow;
    }

    if (row_p == -1) {
        // If we broke for some reason (shouldn't happen)
        cerr << "Failed to get row " << i << " within MAXV.\n";
        return 0;
    }

    // now compute j-th term mod m
    int ans = compute_jth_mod(row_p % m, row_q % m, j, m);
    cout << ans % m << "\n";
    return 0;
}
