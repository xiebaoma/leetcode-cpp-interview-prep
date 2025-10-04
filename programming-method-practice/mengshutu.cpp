#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

// 使用 long long 避免溢出
typedef long long ll;

// 欧几里得算法求最大公约数
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// 寻找一个数的所有因子
void get_divisors(ll n, vector<ll>& divisors) {
    divisors.clear();
    ll limit = sqrt(n);
    for (ll i = 1; i <= limit; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
}

// 解决问题的核心函数
void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    // K = ac (可能很大，最大 10^12)
    ll K = a * c; 
    // T = cd (最大 10^9)
    ll T = c * d; 

    // 1. 寻找 T=cd 的所有因子 f
    vector<ll> T_factors;
    get_divisors(T, T_factors);

    ll count = 0;

    // 2. 遍历 T 的每个因子 f
    for (ll f : T_factors) {
        // f = A' + b*x' = (ac/g) + b*x'
        // 需要找到 (ac/g) 和 g，使得 x' 是正整数且满足 gcd(x', ac/g) = 1

        // R = f - ac/g
        // R 必须是正数，且 R 必须能被 b 整除
        // ac/g < f  =>  ac < f*g  =>  g > ac/f

        // 3. 寻找满足条件的 g，g 是 ac 的因子
        // g 必须是 ac 的因子，且 g > ac / f

        ll lower_bound_g = (K + f - 1) / f; // g >= K/f (向上取整)

        ll limit = sqrt(K);
        // 遍历 K=ac 的因子 g
        for (ll g = 1; g <= limit; ++g) {
            if (K % g == 0) {
                // 找到一对因子 (g, K/g)

                // 检查因子 g
                if (g >= lower_bound_g) {
                    ll Ap = K / g; // A' = ac/g
                    ll R = f - Ap;
                    if (R % b == 0) {
                        ll xp = R / b; // x' = R/b
                        // 验证 gcd(x', A') = 1
                        if (gcd(xp, Ap) == 1) {
                            count++;
                        }
                    }
                }

                // 检查因子 K/g (如果 K/g != g)
                if (g * g != K) {
                    ll g_alt = K / g;
                    if (g_alt >= lower_bound_g) {
                        ll Ap = K / g_alt; // A' = ac/g_alt
                        ll R = f - Ap;
                        if (R % b == 0) {
                            ll xp = R / b; // x' = R/b
                            // 验证 gcd(x', A') = 1
                            if (gcd(xp, Ap) == 1) {
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << count+1 << endl;
}

int main() {
    // 快速IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    // 1 <= T <= 1000
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}