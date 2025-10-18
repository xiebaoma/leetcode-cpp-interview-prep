#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long sumAll = N * (N + 1) / 2;
    long long sumSqAll = N * (N + 1) * (2 * N + 1) / 6;

    long long sumGiven = 0, sumSqGiven = 0;
    long long x;
    for (int i = 0; i < N - 2; ++i) {
        cin >> x;
        sumGiven += x;
        sumSqGiven += 1LL * x * x;
    }

    long long sum_missing = sumAll - sumGiven;         // x + y
    long long sq_missing = sumSqAll - sumSqGiven;      // x^2 + y^2

    // xy = ((x+y)^2 - (x^2+y^2)) / 2
    long long xy = (sum_missing * sum_missing - sq_missing) / 2;

    // 求解二次方程 t^2 - sum_missing*t + xy = 0
    long double delta = (long double)sum_missing * sum_missing - 4.0L * xy;
    long double sqrt_delta = sqrtl(delta);

    long long a = (long long)((sum_missing + sqrt_delta) / 2 + 0.5);
    long long b = sum_missing - a;

    if (a > b) swap(a, b);
    cout << a << " " << b << "\n";

    return 0;
}
