#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000000
#define MAXV 1000000000

// 全局数据
int N, T;
int B;              // 块大小
int numBlocks;      // 块的数量
int arr[MAXN];      // 原始数组

// 每个块的信息
int *blockVal[1200];      // 原始值
int *blockSorted[1200];   // 排序后的值
int blockCnt[1200];       // 块内元素数量

// 用于qsort的比较函数
int cmp(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x < y) ? -1 : (x > y);
}

// 重建块 k 的有序数组
void rebuildBlock(int k) {
    int cnt = blockCnt[k];
    memcpy(blockSorted[k], blockVal[k], cnt * sizeof(int));
    qsort(blockSorted[k], cnt, sizeof(int), cmp);
}

// 初始化分块
void build() {
    B = 1000;                        // 经验值，可根据 N 调整
    numBlocks = (N + B - 1) / B;
    for (int i = 0; i < numBlocks; ++i) {
        blockVal[i] = (int*)malloc(B * sizeof(int));
        blockSorted[i] = (int*)malloc(B * sizeof(int));
    }
    for (int i = 0; i < N; ++i) {
        int b = i / B;
        int pos = blockCnt[b]++;
        blockVal[b][pos] = arr[i];
    }
    for (int i = 0; i < numBlocks; ++i) {
        rebuildBlock(i);
    }
}

// 修改第 k 个烽火台的守军为 x
void update(int k, int x) {
    int b = k / B;
    int idx = k % B;
    // 找到原值在块内的位置
    arr[k] = x;
    blockVal[b][idx] = x;
    rebuildBlock(b);
}

// 统计 [L,R] 区间内 <= mid 的元素数量
int countLE(int L, int R, int mid) {
    int cnt = 0;
    int startBlock = L / B, endBlock = R / B;
    if (startBlock == endBlock) {
        for (int i = L; i <= R; ++i)
            if (arr[i] <= mid) cnt++;
        return cnt;
    }
    // 处理首块剩余
    int end1 = (startBlock + 1) * B - 1;
    for (int i = L; i <= end1; ++i)
        if (arr[i] <= mid) cnt++;
    // 处理中间整块
    for (int b = startBlock + 1; b < endBlock; ++b) {
        // 在 blockSorted[b] 中二分出 <=mid 的数量
        int lo = 0, hi = blockCnt[b];
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (blockSorted[b][m] <= mid) lo = m + 1;
            else hi = m;
        }
        cnt += lo;
    }
    // 处理尾块剩余
    int start2 = endBlock * B;
    for (int i = start2; i <= R; ++i)
        if (arr[i] <= mid) cnt++;
    return cnt;
}

// 查询 [L,R] 区间第 k 小的值
int query(int L, int R, int k) {
    int lo = 0, hi = MAXV, ans = -1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) / 2);
        int c = countLE(L, R, mid);
        if (c >= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    if (scanf("%d", &N) != 1) return 0;
    for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);
    build();
    scanf("%d", &T);
    while (T--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int k, x;
            scanf("%d %d", &k, &x);
            update(k, x);
        } else if (type == 2) {
            int L, R, k;
            scanf("%d %d %d", &L, &R, &k);
            printf("%d\n", query(L, R, k));
        }
    }
    return 0;
}
