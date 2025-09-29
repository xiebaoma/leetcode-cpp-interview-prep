/**
 * xiebaoma
 * 2025-09-27
 */

#include <iostream>
using namespace std;

int main() {
    
    int n, q;
    cin >> n >> q;

    long long odd_cnt = 0, even_cnt = 0;
    long long odd_sum = 0, even_sum = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x % 2 == 0) {
            even_cnt++;
            even_sum += x;
        } else {
            odd_cnt++;
            odd_sum += x;
        }
    }

    for (int i = 0; i < q; i++) {
        int t;
        long long X;
        cin >> t >> X;
        if (t == 1) { // 对奇数堆加 X
            odd_sum += odd_cnt * X;
            if (X % 2 == 1) { // 奇数堆变偶数堆
                even_sum += odd_sum;
                even_cnt += odd_cnt;
                odd_sum = 0;
                odd_cnt = 0;
            }
        } else {      // 对偶数堆加 X
            even_sum += even_cnt * X;
            if (X % 2 == 1) { // 偶数堆变奇数堆
                odd_sum += even_sum;
                odd_cnt += even_cnt;
                even_sum = 0;
                even_cnt = 0;
            }
        }
    }

    cout << (odd_sum + even_sum) << "\n";
    return 0;
}
