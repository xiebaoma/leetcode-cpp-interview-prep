#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

typedef long long ll;

// 最小堆
ll heap[MAXN + 5];
int heap_size = 0;

void swap(ll *a, ll *b) {
    ll tmp = *a;
    *a = *b;
    *b = tmp;
}

// 上浮
void heap_up(int idx) {
    while (idx > 1) {
        int parent = idx / 2;
        if (heap[parent] <= heap[idx]) break;
        swap(&heap[parent], &heap[idx]);
        idx = parent;
    }
}

// 下沉
void heap_down(int idx) {
    while (1) {
        int left = idx * 2;
        int right = idx * 2 + 1;
        int smallest = idx;

        if (left <= heap_size && heap[left] < heap[smallest]) smallest = left;
        if (right <= heap_size && heap[right] < heap[smallest]) smallest = right;

        if (smallest == idx) break;
        swap(&heap[idx], &heap[smallest]);
        idx = smallest;
    }
}

void heap_push(ll val) {
    heap[++heap_size] = val;
    heap_up(heap_size);
}

ll heap_pop() {
    ll top = heap[1];
    heap[1] = heap[heap_size--];
    heap_down(1);
    return top;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        heap_push(x);
    }

    ll total_cost = 0;

    while (heap_size > 1) {
        ll a = heap_pop();
        ll b = heap_pop();
        ll c = a + b;
        total_cost += c;
        heap_push(c);
    }

    printf("%lld\n", total_cost);
    return 0;
}
