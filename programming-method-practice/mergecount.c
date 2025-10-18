/**
 * xiebaoma
 * 2025-10-12
 */

#include <stdio.h>
#include <stdlib.h>

static long long merge_count(int *arr, int *tmp, int left, int right) {
    if (left >= right) return 0;
    int mid = (left + right) / 2;
    long long cnt = 0;
    cnt += merge_count(arr, tmp, left, mid);
    cnt += merge_count(arr, tmp, mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
            cnt += (mid - i + 1);
        }
    }
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= right) tmp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = tmp[i];
    return cnt;
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int *arr = (int *)malloc(sizeof(int) * N);
        int *tmp = (int *)malloc(sizeof(int) * N);
        if (!arr || !tmp) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        for (int i = 0; i < N; i++)
            scanf("%d", &arr[i]);

        long long ans = merge_count(arr, tmp, 0, N - 1);
        printf("%lld\n", ans);

        free(arr);
        free(tmp);
    }
    return 0;
}
