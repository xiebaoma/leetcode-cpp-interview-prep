#include <stdio.h>

#define MAXN 10

int n;
int a[MAXN];      // 存放当前排列

// 交换两个元素
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// 输出当前排列
void print_permutation() {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

// 回溯生成排列
void permute(int start) {
    if (start == n) {
        // 递归到末尾，输出当前排列
        print_permutation();
        return;
    }

    for (int i = start; i < n; i++) {
        swap(&a[start], &a[i]);       // 固定当前位置
        permute(start + 1);           // 递归处理后面的元素
        swap(&a[start], &a[i]);       // 回溯：恢复原状
    }
}

int main() {
    if (scanf("%d", &n) != 1) {             // 检查输入是否成功
        fprintf(stderr, "输入无效！\n");
        return 1;
    }

    for (int i = 0; i < n; i++) a[i] = i + 1;
    permute(0);

    return 0;
}
